#include<stdio.h>

struct point {
    int x, y;
};

int main() {
    int i, j, k, n, a, b, c, d, flag;
    printf("Enter the number of points you want: ");
    scanf("%d", &n);
    struct point p[n];
    for (i = 0; i < n; i++) {
        printf("Enter the x and y values: ");
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            a = p[j].y - p[i].y;
            b = p[i].x - p[j].x;
            c = (p[i].y * p[j].x) - (p[i].x * p[j].y);
            flag = 1; // Assume points form the convex hull

            for (k = 0; k < n; k++) {
                if (k != i && k != j)
                

                d = a * p[k].x + b * p[k].y;
                if (d > c) {
                    flag = 0; // Points do not form the convex hull
                    break;
                }
            }

            if (flag) {
                printf("The two points p(%d, %d) and p(%d, %d) form the convex hull.\n",
                    p[i].x, p[i].y, p[j].x, p[j].y);
            } else {
                printf("The two points p(%d, %d) and p(%d, %d) do not form the convex hull.\n",
                    p[i].x, p[i].y, p[j].x, p[j].y);
            }
        }
    }

    return 0;
}
