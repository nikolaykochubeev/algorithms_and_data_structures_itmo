#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<vector<long long>> d;
    d.assign(n, vector<long long>(n, INT32_MAX));

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[--a].emplace_back(--b, c);
        d[a][b] = c < d[a][b] ? c : d[a][b];
    }

    for (int i = 0; i < n; ++i)
        d[i][i] = 0;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

    for (auto& it: d) {
        for (auto item : it)
            cout << item << ' ';
        cout << endl;
    }

    return 0;
}