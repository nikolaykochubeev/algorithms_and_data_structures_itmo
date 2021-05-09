#include <iostream>
#include <vector>
using namespace std;

vector<long long> numbers;
long long diff_ways(int n, int i, int j, long long ** array){
    if (i > j)
        return 0;
    if (i == j)
        return array[i][j] = 1;
    if (array[i][j] == -1) {
        if (numbers[i] == numbers[j])
            array[i][j] = diff_ways(n, i + 1, j, array) + diff_ways(n, i, j - 1, array) + 1;
        else
            array[i][j] = diff_ways(n, i + 1, j, array) + diff_ways(n, i, j - 1, array) - diff_ways(n, i + 1, j - 1, array);
    }
    return (array[i][j] + 1000000000) % 1000000000;
}


int main() {
    int n;
    cin >> n;
    numbers.resize(n);
    auto **all_palindromes = new long long *[n];

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    for (int i = 0; i < n; i++) {
        all_palindromes[i] = new long long[n];
        for (int j = 0; j < n; j++)
            all_palindromes[i][j] = -1;
    }
    cout << diff_ways(n, 0, n - 1, all_palindromes);
}