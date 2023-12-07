#include <stdio.h>
#define SIZE 3

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(int arr[], int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < SIZE && arr[left] < arr[smallest])
        smallest = left;
    if (right < SIZE && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, smallest);
    }
}

void sort(int arr[]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = i + 1; j < SIZE; ++j) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void solve(int arr[], int n) {
    int heap[SIZE] = { 0 };
    for (int i = 0; i < n; ++i) {
        if (i < SIZE)
            heap[i] = arr[i];
        else if (arr[i] > heap[0]) {
            heap[0] = arr[i];
            minHeapify(heap, 0);
        }

        if (i >= SIZE - 1) {
            sort(heap);
            printf("%d %d %d\n", heap[2], heap[1], heap[0]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    solve(arr, n);

    return 0;
}
