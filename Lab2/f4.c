char f4(unsigned int i)
{
    if (i > 0xf)
        i = 0x41;
    else if (i <= 0xa)
        i = 0x40 + i;
    else
        i = 0x60 + i;

    return i;
}
