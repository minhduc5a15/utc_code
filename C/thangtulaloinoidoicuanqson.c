#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int **tree;
    int n, q;
} MergeSortTree;

void merge(int *left, int left_size, int *right, int right_size, int *arr) {
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }
    while (i < left_size) {
        arr[k++] = left[i++];
    }
    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

int *lower_bound(int *arr, int size, int value) {
    int *first = arr;
    int count = size;
    int step;
    while (count) {
        int *it = first;
        step = count / 2;
        it += step;
        if (*it < value) {
            first = ++it;
            count -= step + 1;
        }
        else {
            count = step;
        }
    }
    return first;
}

int *upper_bound(int *arr, int size, int value) {
    int *first = arr;
    int count = size;
    int step;
    while (count > 0) {
        int *it = first;
        step = count / 2;
        it += step;
        if (value >= *it) {
            first = ++it;
            count -= step + 1;
        }
        else {
            count = step;
        }
    }
    return first;
}

void init(MergeSortTree *tree) {
    scanf("%d %d", &(tree->n), &(tree->q));
    tree->arr = (int *) malloc((tree->n + 1) * sizeof(int));
    tree->tree = (int **) malloc((4 * tree->n + 1) * sizeof(int *));
    for (int i = 1; i <= tree->n; ++i) {
        scanf("%d", &(tree->arr[i]));
    }
}

void build(MergeSortTree *tree, int id, int l, int r) {
    if (l == r) {
        tree->tree[id] = (int *) malloc(sizeof(int));
        tree->tree[id][0] = tree->arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(tree, 2 * id, l, mid);
    build(tree, 2 * id + 1, mid + 1, r);
    int left_size = mid - l + 1;
    int right_size = r - mid;
    tree->tree[id] = (int *) malloc((left_size + right_size) * sizeof(int));
    merge(tree->tree[2 * id], left_size, tree->tree[2 * id + 1], right_size, tree->tree[id]);
}

int query(MergeSortTree *tree, int id, int l, int r, int x, int y, int u, int v) {
    if (y < l || x > r) return 0;
    if (x <= l && r <= y) {
        int *lb = lower_bound(tree->tree[id], r - l + 1, u);
        int *ub = upper_bound(tree->tree[id], r - l + 1, v);
        return ub - lb;
    }
    int mid = (l + r) / 2;
    return query(tree, 2 * id, l, mid, x, y, u, v) + query(tree, 2 * id + 1, mid + 1, r, x, y, u, v);
}

void solve(MergeSortTree *tree) {
    build(tree, 1, 1, tree->n);
    while ((tree->q)--) {
        int x, y, l, r;
        scanf("%d %d %d %d", &x, &y, &l, &r);
        printf("%d\n", query(tree, 1, 1, tree->n, x, y, l, r));
    }
}

int main() {
    MergeSortTree tree;
    init(&tree);
    solve(&tree);
    return 0;
}
