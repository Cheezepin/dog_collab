const u8 string0[] = {
    "O-oh, a visitor?\n"
    "That's odd...\n"
    "\n"
    "\n"
    "Anyways, welcome to\n"
    "Upturn Village! You should\n"
    "probably go speak with\n"
    "the elder."
};

const struct DialogEntry entry0 = {
    1, 4 /* Lines per box */, 30 /* Left offset */, 200 /* Width */, string0
};

const u8 string1[] = {
    "farts lmao"
};

const struct DialogEntry entry1 = {
    1, 4 /* Lines per box */, 30 /* Left offset */, 200 /* Width */, string1
};

const struct DialogEntry *const levelDialogTable[] = {
    &entry0, &entry1, NULL,
};