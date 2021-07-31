
void faz_ambient_loop(void)
{
    switch(o->oBehParams2ndByte)
    {
    case 0:
        {
            if (gMarioCurrentRoom == 1)
                cur_obj_play_sound_1(SOUND_AIR_HOWLING_WIND);
            break;
        }
    }
}
