#include<iostream>
using namespace std;

int partition(int array[], int left, int right) {
    int pivot = array[rand() % (right - left) + left];
    int left_c = left;
    int right_c = right;
    while (left_c <= right_c) {
        while (array[left_c] < pivot)
            left_c++;
        while (array[right_c] > pivot)
            right_c--;
        if (left_c >= right_c)
            break;
        swap(array[left_c++], array[right_c--]);

    }
    return right_c;
}


void quickSort(int array[], int left, int right, int k) {
    if (left < right) {
        int q = partition(array, left, right);
        if (k <= q)
            quickSort(array, left, q, k);
        if (k >= q)
            quickSort(array, q + 1, right, k);
    }

}


int main() {
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    int n, k, A, B, C;
    cin >> n >> k >> A >> B >> C;
    int *array = new int[n];
    cin >> array[0] >> array[1];

    for (int i = 2; i < n; i++)
        array[i] = A * array[i - 2] + B * array[i - 1] + C;
    quickSort(array, 0, n - 1, k - 1);
    cout << array[k - 1];

    return 0;
}