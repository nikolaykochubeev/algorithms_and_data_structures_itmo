#include <fstream>
#include <vector>
#include <set>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& g, int s) {
    ofstream cout("pathbgep.out");
    int n = g.size();
    vector<uint64_t> d (n, INT64_MAX);
    set<pair<uint64_t, int>> ss;
    ss.insert({0, s});
    d[s] = 0;

    while(!ss.empty()) {
        pair<uint64_t, int> v = *ss.begin();
        ss.erase(ss.begin());

        for (auto item : g[v.second])
            if (d[item.second] > v.first + item.first) {
                ss.erase({d[item.second], item.second});
                d[item.second] = v.first + item.first;
                ss.insert({d[item.second], item.second});
            }
    }
    for (auto item : d)
        cout << item << ' ';
}

int main() {
    ifstream cin("pathbgep.in");
    ofstream cout("pathbgep.out");
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;--b;
        g[a].emplace_back(c, b);
        g[b].emplace_back(c, a);
    }

    dijkstra(g, 0);
    return 0;
}