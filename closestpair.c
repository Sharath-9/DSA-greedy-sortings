#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define sqrt
struct Point {
    int x, y;
};

int compareX(const void* a, const void* b) {
    struct Point* p1 = (struct Point*)a;
    struct Point* p2 = (struct Point*)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b) {
    struct Point* p1 = (struct Point*)a;
    struct Point* p2 = (struct Point*)b;
    return (p1->y - p2->y);
}

double distance(struct Point p1, struct Point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double min(double x, double y) {
    return (x < y) ? x : y;
}

double bruteForce(struct Point P[], int st, int end) {
    double minDist = INT_MAX;

    for (int i = st; i <= end; i++) {
        for (int j = i + 1; j <= end; j++) {
            double dist = distance(P[i], P[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }

    return minDist;
}

double stripClose(struct Point strip[], int size, double minDist) {
    double minDistance = minDist;

    qsort(strip, size, sizeof(struct Point), compareY);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDistance; j++) {
            double dist = distance(strip[i], strip[j]);
            if (dist < minDistance) {
                minDistance = dist;
            }
        }
    }

    return minDistance;
}

double closest(struct Point P[], int st, int end) {
    if (end - st <= 3) {
        return bruteForce(P, st, end);
    }

    int mid = st + (end - st) / 2;
    double dl = closest(P, st, mid);
    double dr = closest(P, mid + 1, end);
    double minDist = min(dl, dr);

    struct Point strip[end - st + 1];
    int j = 0;
    for (int i = st; i <= end; i++) {
        if (abs(P[i].x - P[mid].x) < minDist) {
            strip[j++] = P[i];
        }
    }

    double stripDist = stripClose(strip, j, minDist);

    return min(minDist, stripDist);
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    struct Point P[n];
    for (int i = 0; i < n; i++) {
        printf("Enter x and y coordinates for point %d: ", i + 1);
        scanf("%d %d", &P[i].x, &P[i].y);
    }

    // Sort the points by x coordinates
    qsort(P, n, sizeof(struct Point), compareX);

    struct Point Px[n];
    for (int i = 0; i < n; i++) {
        Px[i] = P[i];
    }

    double minDistance = closest(Px, 0, n - 1);

    printf("Minimum distance between two points: %lf\n", minDistance);

    return 0;
}
