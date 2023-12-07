#include <stdio.h>
#include <stdlib.h>

int lambda(const void *a, const void *b) {
	return (*(int *) b - *(int *) a);
}

int main() {
	int n;
	scanf("%d", &n);
	int *arr = (int *) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), lambda);
	long long sum = arr[0];
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if ((max + arr[i]) & 1) {
			sum += arr[i];
			max = arr[i];
		}
	}
	printf("%lld", sum);
	free(arr);
	return 0;
}