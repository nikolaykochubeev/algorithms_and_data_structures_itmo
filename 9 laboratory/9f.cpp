#include <fstream>
#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<int> color;
vector<bool> used;


void dfs(int i) {
    used[i] = true;
    if (adj[i].empty()) {
        color[i] = 0;
        return;
    }
    for (auto item : adj[i]) {
        if (!used[item])
            dfs(item);
        if (!color[i] && !color[item])
            color[i] = 1;
    }
}

int main() {
    ifstream cin("game.in");
    ofstream cout("game.out");

    int n, m, s;
    cin >> n >> m >> s;
    adj.resize(n);
    color.assign(n, 0);
    used.assign(n, false);
    --s;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[--a].push_back(--b);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i])
            dfs(i);
    }
    if (color[s] == 1)
        cout << "First player wins";
    else
        cout << "Second player wins";
    return 0;
}