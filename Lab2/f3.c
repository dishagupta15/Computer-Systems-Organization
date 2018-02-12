int f3(unsigned int i)
{
   int x = 0;

   while (i != 0) {
        if (i & 1)
            x++;
        i /= 2;
    }

    return (-x);
}
