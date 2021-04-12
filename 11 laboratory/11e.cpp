#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int64_t INF = INT64_MAX;

struct edge {
    int from, to;
    int64_t cost;
    edge(int from, int to, int64_t cost) : from(from), to(to), cost(cost) {};
    edge() = default;
};

void ford(vector<edge>& e, int n) {
    vector<int64_t> d (n, 0);
    vector<int> p (n, -1);
    int x = -1;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (auto &ee : e) {
            if (d[ee.from] < INF)
                if (d[ee.to] > d[ee.from] + ee.cost) {
                    d[ee.to] = max(-INF, d[ee.from] + ee.cost); // от переполнения вниз
                    p[ee.to] = ee.from;
                    x = ee.to;
                }
        }
    }

    if (x == -1) {
        cout << "NO";
        return;
    }
    int y = x;
    for (int i = 0; i < n; ++i)
        y = p[y];

    vector<int> path;
    x = y;
    do {
        path.push_back(x);
        x=p[x];
    } while (x!=y);
    path.push_back(x);
    reverse (path.begin(), path.end());
    cout << "YES" << endl << path.size() << endl;
    for (int i : path)
        cout << i + 1 << ' ';
}

int main() {
    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w", stdout);
    int n;
    cin >> n;
    vector<edge> e;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            int64_t a;
            cin >> a;
            if (a != 1e9)
                e.emplace_back(i, j, a);
        }
    }

    ford(e, n);
    return 0;
}