#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

typedef struct {
    ll first;
    ll second;
} pair;

typedef struct {
    ll *heapArr;
    int size;
    int capacity;
} MaxHeap;

MaxHeap *createMaxHeap(int capacity) {
    MaxHeap *maxHeap = (MaxHeap *) malloc(sizeof(MaxHeap));
    maxHeap->size = 0;
    maxHeap->capacity = capacity;
    maxHeap->heapArr = (ll *) malloc(capacity * sizeof(ll));
    return maxHeap;
}

void swap(ll *a, ll *b) {
    ll t = *a;
    *a = *b;
    *b = t;
}

void maxHeapify(MaxHeap *maxHeap, int idx) {
    int largest = idx;
    int left = (idx << 1) + 1;
    int right = (idx + 1) << 1;
    if (left < maxHeap->size && maxHeap->heapArr[left] > maxHeap->heapArr[largest]) largest = left;
    if (right < maxHeap->size && maxHeap->heapArr[right] > maxHeap->heapArr[largest]) largest = right;
    if (largest != idx) {
        swap(&maxHeap->heapArr[largest], &maxHeap->heapArr[idx]);
        maxHeapify(maxHeap, largest);
    }
}

void push(MaxHeap *maxHeap, ll k) {
    if (maxHeap->size == maxHeap->capacity) {
        return;
    }
    maxHeap->size++;
    int i = maxHeap->size - 1;
    maxHeap->heapArr[i] = k;
    while (i != 0 && maxHeap->heapArr[(i - 1) / 2] < maxHeap->heapArr[i]) {
        swap(&maxHeap->heapArr[i], &maxHeap->heapArr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

ll pop(MaxHeap *maxHeap) {
    if (maxHeap->size <= 0) return 0;
    if (maxHeap->size == 1) {
        maxHeap->size--;
        return maxHeap->heapArr[0];
    }

    ll root = maxHeap->heapArr[0];
    maxHeap->heapArr[0] = maxHeap->heapArr[maxHeap->size - 1];
    maxHeap->size--;
    maxHeapify(maxHeap, 0);
    return root;
}

int compare(const void *a, const void *b) {
    pair *pair1 = (pair *) a;
    pair *pair2 = (pair *) b;
    return pair1->first == pair2->first ? pair1->second - pair2->second : pair1->first - pair2->first;
}

int main() {
    ll n;
    scanf("%lld", &n);
    pair *arr = malloc(n * sizeof(pair));
    for (ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &arr[i].first, &arr[i].second);
    }
    qsort(arr, n, sizeof(pair), compare);
    ll j = n - 1;
    ll res = 0;
    MaxHeap *maxHeap = createMaxHeap(n);
    while (n) {
        while (j >= 0 && arr[j].first >= n) {
            push(maxHeap, arr[j].second);
            --j;
        }
        if (maxHeap->size > 0) {
            res += pop(maxHeap);
        }
        --n;
    }
    printf("%lld", res);
    free(arr);
    free(maxHeap->heapArr);
    free(maxHeap);
    return 0;
}
