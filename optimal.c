#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i) {
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;
    int smallest = i;

    if (leftChild < n && a[leftChild] < a[smallest])
        smallest = leftChild;

    if (rightChild < n && a[rightChild] < a[smallest])
        smallest = rightChild;

    if (smallest != i) {
        swap(&a[i], &a[smallest]);
        heapify(a, n, smallest);
    }
}

int opt_merge(int a[], int n) {
    int b, c, d;
    int sum = 0;
    for (int i = n  - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    
    printf("\nAfter heapifying: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    for (int i = n - 1; i > 0; i--) {
        b = a[0];
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
        c = a[0];
        d = b + c;
        sum += d;
        printf("\n%d", d);
        a[0] = d;
        heapify(a, i, 0);
    }
    printf("\nThe solution is %d", sum);
    //return sum;
}

int main() {
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter the value: ");
        scanf("%d", &a[i]);
    }
    opt_merge(a, n);
}
