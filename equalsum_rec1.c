#include <stdio.h>
#include <limits.h>
#include <math.h>

int ss(int wt[], int n, int sum) {
    if (n == 0) {
        return 0;
    }
    if (sum == 0) {
        return 1;
    }
    if (wt[n - 1] <= sum) {
        return ss(wt, n - 1, sum - wt[n - 1]) || ss(wt, n - 1, sum);
    } else {
        return ss(wt, n - 1, sum);
    }
}

int partition(int wt[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += wt[i];
    }
    if (sum % 2 != 0) {
        return 0;
    } else {
        return ss(wt, n, sum / 2);
    }
}

int main() {
    int wt[] = {1, 5, 11, 5};
    int n = sizeof(wt) / sizeof(wt[0]);
    int k = partition(wt, n);
    if (k) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    return 0;
}
