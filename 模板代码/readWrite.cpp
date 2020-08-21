inline int read()
{
    int X = 0;
    char ch = 0; while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return X;
}

inline void write(int x)
{
    int y = 10, len = 1;
    while (y <= x) { y *= 10; len++; }
    while (len--) { y /= 10; putchar(x / y + 48); x %= y; }
}