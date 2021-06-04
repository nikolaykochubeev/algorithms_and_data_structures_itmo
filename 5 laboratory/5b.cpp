#include <iostream>
#include <vector>

using namespace std;

bool check_tree(vector<vector<int>>& tree, int i, int left, int right) {
    if (i < 0)
        return true;
    if (tree[i][0] <= left || tree[i][0] >= right)
        return false;
    return (check_tree(tree, tree[i][1], left, tree[i][0]) && check_tree(tree, tree[i][2], tree[i][0], right));
}

int main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);

    vector<vector<int>> tree;

    int n;
    cin >> n;

    if (not n) {
        cout << "YES";
        return 0;
    }
    tree.resize(n);

    for (int i = 0; i < n; ++i) {
        int t,l,r;
        cin >> t >> l >> r;
        tree[i].push_back(t);
        tree[i].push_back(l - 1);
        tree[i].push_back(r - 1);
    }

    if (check_tree(tree, 0, -1000000001, 1000000001)) {
        cout << "YES"<<endl;
    } else {
        cout << "NO"<<endl;
    }

    return 0;
}