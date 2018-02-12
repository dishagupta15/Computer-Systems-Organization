long f2(int x)
{
    int y;
    int z = 17;
    
    x *= 7;

    for (y = 0; y < x; y++)
        z += y;

    return z;
}
