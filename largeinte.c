#include <stdio.h>
#include <math.h>

int DC_CLEVER_MULTIPLICATION(int a, int b) {
    if (abs(a) == 1 || abs(b) == 1) {
        return a * b;
    } else {
        int n = fmax(abs(a), abs(b));
        int a1 = a / pow(10, n/2);
        int a0 = a % (int)pow(10, n/2);
        int b1 = b / pow(10, n/2);
        int b0 = b % (int)pow(10, n/2);

        int c2 = DC_CLEVER_MULTIPLICATION(a1, b1);
        int c0 = DC_CLEVER_MULTIPLICATION(a0, b0);
        int x = DC_CLEVER_MULTIPLICATION(a1 + a0, b1 + b0);

        return c2 * pow(10, n) + (x - c2 - c0) * pow(10, n/2) + c0;
    }
}

int main() {
    int A, B;
    printf("Enter two numbers A and B: ");
    scanf("%d %d", &A, &B);

    int result = DC_CLEVER_MULTIPLICATION(A, B);
    printf("Result: %d\n", result);

    return 0;
}
