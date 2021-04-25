#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int array[n];
    int prefix[n];
    for (int i = 0; i < n; i++) {
        array[i] = 1;
        prefix[i] = -1;
        for (int j = 0; j < i; j++) {
            if(a[j] < a[i]) {
                if (array[i] < array[j] + 1) {
                    array[i] = array[j] + 1;
                    prefix[i] = j;
                }
            }
        }
    }
    int ans = 0, t;
    for (int i = 0; i < n; i++) {
        if (array[i] > ans) {
            ans = array[i];
            t = i;
        }
    }
    cout << ans << "\n";
    vector <int> array1;
    while (t != -1) {
        array1.push_back(a[t]);
        t = prefix[t];
    }
    for (int i = array1.size() - 1; i >= 0; i--)
        cout << array1[i] << ' ';
}
