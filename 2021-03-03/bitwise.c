#include <stdio.h>


int main() {
    int a = 0, // 0000 0000
        b = 1, // 0000 0001
        c = 2, // 0000 0010
        d = 7, // 0000 0111
        e = 9; // 0000 1001

    printf("\n--- XOR ---\n");
    printf("a ^ b = %d\n", a ^ b); //   1
    printf("b ^ c = %d\n", b ^ c); //   3
    printf("d ^ e = %d\n", d ^ e); //  14

    printf("\n--- AND ---\n");
    printf("a & b = %d\n", a & b); //   0
    printf("b & c = %d\n", b & c); //   0
    printf("d & e = %d\n", d & e); //   1

    printf("\n--- OR ---\n");
    printf("a | b = %d\n", a | b); //   1
    printf("b | c = %d\n", b | c); //   3
    printf("d | e = %d\n", d | e); //  15

    return 0;
}