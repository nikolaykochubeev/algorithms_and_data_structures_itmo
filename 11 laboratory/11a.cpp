#include <iostream>
#include <vector>
#include <set>
using namespace std;

int64_t dijkstra(vector<vector<pair<uint64_t, int>>>& g, int s, int f) {
    int n = g.size();
    vector<uint64_t> d (n, INT64_MAX);
    set<pair<uint64_t, int>> set_e;
    set_e.insert({0, s});
    d[s] = 0;

    while(!set_e.empty()) {
        pair<uint64_t, int> v = *set_e.begin();
        set_e.erase(set_e.begin());

        for (auto item : g[v.second]) {
            if (d[item.second] > v.first + item.first) {
                set_e.erase({d[item.second], item.second});
                d[item.second] = v.first + item.first;
                set_e.insert({d[item.second], item.second});
            }
        }
    }
    return d[f] == INT64_MAX ? -1 : d[f];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);
    int n,s,f;
    cin >> n >> s >> f;
    vector<vector<pair<uint64_t, int>>> g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int64_t a;
            cin >> a;
            if (a > 0) {
                g[i].emplace_back(a, j);
            }
        }
    }
    cout << dijkstra(g, --s, --f);

    return 0;
}