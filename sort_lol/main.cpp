#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <assert.h>

using namespace std;

typedef int value_type;

void quick_sort(vector<value_type> &array, size_t const &l, size_t const &r) {
    value_type m = array[l + (r == l ? rand() % (r - l) : 0)];
    size_t i = l;
    size_t j = r;
    while (i <= j) {
        for (; array[i] < m; i++);
        for (; array[j] > m; j--);
        if (i <= j) {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    if (l < j) {
        quick_sort(array, l, j);
    }
    if (i < r) {
        quick_sort(array, i, r);
    }
}

int main() {
    for (int t = 0; t < 10000; t++) {
        srand(time(NULL));
        vector<value_type> a;
        vector<value_type> b;
        size_t n = rand() % 50000;
        for (int i = 0; i < n; i++) {
            int x = rand() % 1000;
            a.push_back(x);
            b.push_back(x);
            //printf("%d ", a[i]);
        }
        //printf("\n");
        quick_sort(a, 0, n - 1);
        for (int i = 0; i < n; i++) {
            //printf("%d ", a[i]);
        }
        sort(b.begin(), b.end());
        assert(a == b && "NOT SORTED");
        printf("Test %d: OK\n", t + 1);
    }
    return 0;
}