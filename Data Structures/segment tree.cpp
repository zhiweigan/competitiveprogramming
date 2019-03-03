#include <iostream>

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1 /* 2*i */] + t[i<<1|1 /* 2*i + 1 */];
}

void modify(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p /= 2 /*p >>= 1*/) t[p/2] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l % 2 == 1 /*l&1*/) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
    build();
    modify(0, 1);
    printf("%d\n", query(0, 5));
    return 0;
}
