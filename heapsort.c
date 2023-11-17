#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i) { // time complexity of heapify is O(n)
    int largest = i;
    int l = 2 * i ; // Changed l = 2 * i +1
    int r = 2 * i + 1; // Changed r = 2 * i + 2 when index start with 0

    if (l < n && a[l] > a[largest]) {
        largest = l;
    }

    if (r < n && a[r] > a[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&a[largest], &a[i]);
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n) {
    for (int i = n / 2 ; i >= 1; i--) { // Changed i = n / 2 -1 and we have to use this when index start with 0 and i>=0
        heapify(a, n, i);
    }

    for (int i = n ; i >= 1; i--) { // Changed i = n-1 and we have to use this when index is start with 0
        swap(&a[1], &a[i]); // we have to swap a[0],a[i]
        heapify(a, i, 1); // we have heapify with a,i,0
    }
}
// time complexity is O(nlogn)

int main() {
    printf("Enter the size of the array: ");
    int n,i;
    scanf("%d", &n);
    int a[n];
    srand(time(NULL));
    printf("enter values");
    for ( i = 1; i <= n; i++) {
       scanf("%d",&a[i]);
        //a[i] = rand() % 100;
    }

    printf("Unsorted array: ");
    for ( i = 1; i <=n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    clock_t st = clock();
    heapsort(a, n);
    clock_t ed = clock();

    printf("Sorted array: ");
    for ( i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    double time_taken = (double)(ed - st) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}
