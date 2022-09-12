
#ifdef CRINGE
#include <ultra64.h>
#include "n64_defs.h"
#include "farcall.h"

enum InsnTypes {
    R_TYPE,
    I_TYPE,
    J_TYPE,
};

enum ParamTypes {
    PARAM_NONE,
    PARAM_SWAP_RS_IMM,
    PARAM_JAL,
    PARAM_JR,
    PARAM_LUI,
};

extern far char *parse_map(u32);
static char insn_as_string[100];

#define ACOUNT(x) (sizeof((x)) / sizeof((x)[0]))

typedef struct __attribute__((packed)) {
    u16 rd        : 5;
    u16 shift_amt : 5;
    u16 function  : 6;
} RTypeData;

typedef struct __attribute__((packed)) {
    u16 opcode : 6;
    u16 rs     : 5;
    u16 rt     : 5;
    union {
        RTypeData rdata;
        u16 immediate;
    };
} Insn;

typedef union {
    Insn i;
    u32  d;
} InsnData;

typedef struct __attribute__((packed)) {
    u32 type;
    u32 arbitraryParam;
    u16 opcode   : 6;
    u16 function : 6;
    u8 name[10];
} InsnTemplate;


InsnTemplate insn_db[] = {
    {R_TYPE, PARAM_NONE, 0, 0b100000, "ADD"},
    {R_TYPE, PARAM_NONE, 0, 0b100001, "ADDU"},
    {I_TYPE, PARAM_SWAP_RS_IMM,  0b001001, 0, "ADDIU"},
    {R_TYPE, PARAM_NONE, 0, 0b100100, "AND"},
    {R_TYPE, PARAM_NONE, 0, 0b011010, "DIV"},
    {R_TYPE, PARAM_NONE, 0, 0b011011, "DIVU"},
    {R_TYPE, PARAM_NONE, 0, 0b001000, "JR"},
 
    {I_TYPE, PARAM_NONE, 0b101000, 0, "SB"},
    {I_TYPE, PARAM_NONE, 0b100000, 0, "LB"},
    {I_TYPE, PARAM_NONE, 0b100100, 0, "LBU"},
    {I_TYPE, PARAM_NONE, 0b101001, 0, "SH"},
    {I_TYPE, PARAM_NONE, 0b100001, 0, "LH"},
    {I_TYPE, PARAM_NONE, 0b100101, 0, "LHU"},
    {I_TYPE, PARAM_NONE, 0b101011, 0, "SW"},
    {I_TYPE, PARAM_NONE, 0b100011, 0, "LW"},
    {I_TYPE, PARAM_LUI,  0b001111, 0, "LUI"},

    // branches
    {I_TYPE, PARAM_SWAP_RS_IMM, 0b000100, 0, "BEQ"},
    {I_TYPE, PARAM_SWAP_RS_IMM, 0b000101, 0, "BNE"},
    {R_TYPE, PARAM_NONE, 0, 0b110100, "TEQ"},
    {R_TYPE, PARAM_NONE, 0, 0b001001, "JALR"},

    // jal (special)
    {J_TYPE, PARAM_JAL, 0b000011, 0, "JAL"},

    {0,'NOP',0,0,"NOP"},
};


char registerMaps[][4] = {
    "$R0",
    "$AT",
    "$V0", "$V1",
    "$A0", "$A1", "$A2", "$A3",
    "$T0", "$T1", "$T2", "$T3", "$T4", "$T5", "$T6", "$T7",
    "$S0", "$S1", "$S2", "$S3", "$S4", "$S5", "$S6", "$S7",
    "$T8", "$T9",
    "$K0", "$K1",
    "$GP", "$SP", "$FP", "$RA",
};

u32 nextTok(char *str) {
    int i;
    for (i = 0; *str != ' '; i++, str++);
    return i;
}

u32 nextLine(char *str) {
    int i;
    for (i = 0; *str != '\n'; i++, str++);
    return i;
}

u32 findReg(char *str) {
    int i = 0;
    for (i = 0; i < ACOUNT(registerMaps), i++) {
        if (strcmp(str, registerMaps[i]) == 0) {
            return i;
        }
    }
}

u8 *insn_assemble(char *str) {
    char *sizep = str;
    char *ap = str;

    // pass 1: figure out size (naive) by counting newlines
    u32 insn_size = 0;

    while (*sizep) {
        if (*sizep == '\n') {
            insn_size++;
        }
        sizep++;
    }

    // allocate more than necessary
    Insn *binSearch = main_pool_alloc(insn_size * 2 * sizeof(Insn));
    Insn *ret = binSearch;

    // pass 2: actually assemble
    while (*ap) {

        // short circuit if "...""
        if (strcmp_space(ap, "...") == 0) {
            *(u32*)binSearch = 'skipinsn';

            binSearch++;
            ap += nextLine(ap);
            continue;
        }

        // get Instruction
        InsnTemplate *toEncode;
        for (int i = 0; i < ACOUNT(insn_db); i++) {
            if (strcmp_space(ap, insn_db[i].name) == 0) {
                toEncode = &insn_db[i];
                break;
            }
        }

        // Encode+write instruction
        if (toEncode->arbitraryParam == 'NOP') {
            *(u32*)binSearch = 0;
        }
        else {
            binSearch->opcode = toEncode->opcode;
            binSearch->rt = findReg(ap);
            ap += 4;
            binSearch->rs = findReg(ap);
            ap += 4;

            if (toEncode->type == R_TYPE) {
                binSearch->RTypeData = toEncode->function;
            } else if (toEncode->type == I_TYPE) {
                binSearch->immediate = strtoul(ap, NULL, 16);
            }
        }


        // continue
        binSearch++;
        ap += nextLine(ap);


    }

    return (u8*)ret;
}


int main() {
    insn_assemble(R"(
        LUI $AT, 8034
        ADDIU $AT $AT B170
        ...
        JR $RA $R0 $RA
        NOP
)")
}
#endif