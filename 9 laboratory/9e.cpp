#include <fstream>
#include <stack>
#include <vector>
using namespace std;

void dfs(int x, int n, vector<vector<int>> &graph, vector<int> &color, stack<int> &sort) {
    color[x] = 1;
    for (auto i : graph[x])
        if (color[i] == 0)
            dfs(i, n, graph, color, sort);
    color[x] = 2;
    sort.push(x);
}

int main() {
    ifstream cin("hamiltonian.in");
    ofstream cout("hamiltonian.out");
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[--a].push_back(--b);
    }
    vector<int> color(n, 0);

    stack<int> sort;

    for (int i = 0; i < n; i++)
        if (color[i] != 2)
            dfs(i, n, graph, color, sort);

    bool flag = false;
    int x, y;

    if (!sort.empty()) {
        x = sort.top();
        sort.pop();
        flag = true;
    }

    while (!sort.empty() && flag) {
        y = sort.top();
        sort.pop();
        flag = false;

        for (auto i : graph[x])
            if (i == y)
                flag = true;
        x = y;
    }

    if (flag)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}