#include <fstream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> v;
vector<int> color;
stack<int> s;

bool dfs(int n) {
    color[n] = 1;
    bool b = true;
    for (auto item : v[n]) {
        if (color[item] == 0) {
            b &= dfs(item);
        } else if (color[item] == 1) {
            return false;
        } else if (color[item] == 2) {
            continue;
        }
    }
    color[n] = 2;
    s.push(n);
    return b;
}


int main() {
    ifstream cin("topsort.in");
    ofstream cout("topsort.out");
    int n, m;
    cin >> n >> m;
    v.resize(n);
    color.resize(n);
    int a,b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[--a].push_back(--b);
    }
    bool pos = true;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0)
            pos &= dfs(i);
    }
    if (pos) {
        while (!s.empty()) {
            cout << s.top() + 1 << ' ';
            s.pop();
        }
    }
    else
        cout << -1 << "\n";
    return 0;
}