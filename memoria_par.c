#include <stdio.h>

int main() {
    unsigned short int a, b, c;
    scanf("%hu %hu %hu", &a, &b, &c);

    // Tornar par
    a = a & ~1;
    b = b & ~1;
    c = c & ~1;

    // Posicionar e juntar 
    unsigned long long result = ((unsigned long long)c << 32) | ((unsigned long long)b << 16) | a;

    printf("%llu\n", result);

    return 0;
}