unsigned int check(unsigned int x) {
    unsigned int y = 1;
    
    while (x > 0) {
        y = x + y;
        x--;
    }
    
    return y;
}

unsigned int count(unsigned int x) {
    unsigned int y = 0;
    
    while (x > 0) {
        y = y << (x & 1);
        x = x/2;
    }
    
    return y;
}

unsigned int f5(unsigned int x) {
    switch (x) {
        case 0: 
            x = x >> 2; 
            break;
        case 1:
            x = x << 2;
            break;
        case 2:
            x = x;
            break;
        case 3:
            x = check(x);
            break;
        case 4:
            x = count(x);
            break;
        case 5:
            x = 7;
            break;
        default:
            x = 3*x;
    }

    return x;  
}
