#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<int> d;
struct Point {
    int x,y;
};

void prim(int start, int n) {
    d[start] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || d[j] < d[v]))
                v = j;
        used[v] = true;
        for (int j = 0; j < n; j++)
            if (!used[j] && g[v][j] < d[j] && v != j)
                d[j] = g[v][j];
    }
}

int main() {
    ifstream cin("spantree.in");
    ofstream cout("spantree.out");
    int n;
    cin >> n;

    g.assign(n, vector<int>(n));
    used.assign(n, false);
    d.assign(n, INT32_MAX);
    vector<Point> p(n);

    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;

    auto distance = [](Point a, Point b) -> double {
        return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = distance(p[i], p[j]);

    prim(0, n);
    double res = 0;
    for (auto item : d)
        res += sqrt(item);

    cout.precision(10);
    cout << res;
    return 0;
}