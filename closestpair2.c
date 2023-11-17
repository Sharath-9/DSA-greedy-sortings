#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

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

float dist(struct Point p1, struct Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
				(p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(struct Point P[], int n) {
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (dist(P[i], P[j]) < min) {
				min = dist(P[i], P[j]);
			}
		}
	}
	return min;
}

float min(float x, float y) {
	return (x < y) ? x : y;
}

float stripClosest(struct Point strip[], int size, float d) {
	float minDistance = d;

	qsort(strip, size, sizeof(struct Point), compareY);

	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDistance; ++j) {
			if (dist(strip[i], strip[j]) < minDistance) {
				minDistance = dist(strip[i], strip[j]);
			}
		}
	}

	return minDistance;
}

float closestUtil(struct Point P[], int n) {
	if (n <= 3) {
		return bruteForce(P, n);
	}

	int mid = n / 2;
	struct Point midPoint = P[mid];

	float dl = closestUtil(P, mid);
	float dr = closestUtil(P + mid, n - mid);
	float d = min(dl, dr);

	struct Point strip[n];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (abs(P[i].x - midPoint.x) < d) {
			strip[j] = P[i];
			j++;
		}
	}

	return min(d, stripClosest(strip, j, d));
}

float closest(struct Point P[], int n) {
	qsort(P, n, sizeof(struct Point), compareX);
	return closestUtil(P, n);
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

	float minDistance = closest(P, n);

	printf("The smallest distance is %f\n", minDistance);
	return 0;
}
