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
    1, 4 /* Lines per box */, 30 /* Left offset */, 200 /* Width */, string0, VOICE_NONE
};

const u8 string1[] = {
    "I don't know how I'm\n"
    "losing.\n"
    "\n"
    "I think they're cheating,\n"
    "but I can't prove it\n"
    "at all.\n"
    "I can't risk looking rude,\n"
    "of course."
};

const struct DialogEntry entry1 = {
    1, 3 /* Lines per box */, 30 /* Left offset */, 200 /* Width */, string1, VOICE_NONE
};

const u8 string2[] = {
    "@FFFFFF80(I've been eating my\n"
    "cards while they're\n"
    "not looking.)\n"
    "@FFFFFF80(They taste pretty bad,\n"
    "but at least I'm\n"
    "winning.)"
};

const struct DialogEntry entry2 = {
    1, 3 /* Lines per box */, 30 /* Left offset */, 200 /* Width */, string2, VOICE_NONE
};

const u8 string3[] = {
    "Argh, I'm tryin' to chart\n"
    "a course across the sea,\n"
    "but none of these maps\n"
    "make any sense!\n"
    "It's almost as if they\n"
    "were drawn upside-down..."
};

const struct DialogEntry entry3 = {
    1, 4 /* Lines per box */, 30 /* Left offset */, 200 /* Width */, string3, VOICE_NONE
};

const struct DialogEntry *const levelDialogTable[] = {
    &entry0, &entry1, &entry2, &entry3, NULL,
};