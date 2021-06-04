#include <iostream>
#include <vector>

using namespace std;

int get_height(vector<vector<int>>& v, int i) {
    int max_height = 0;
    if (i < 0) {
        return 0;
    }
    for (auto it : v[i]) {
        max_height = max(get_height(v, it), max_height);
    }
    return max_height + 1;
}

int main() {
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    vector<vector<int>> tree;
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    tree.resize(n);
    for (int i = 0; i < n; ++i) {
        int value,left,right;
        cin >> value >> left >> right;

        tree[i].push_back(left - 1);
        tree[i].push_back(right - 1);
    }

    cout << get_height(tree, 0);
    return 0;
}