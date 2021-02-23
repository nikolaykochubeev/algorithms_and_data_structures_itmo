#include <fstream>
#include <vector>
using namespace std;

vector<int> adjacency_matrix[100001];
int cmp[100001];
bool usd[100001];

void dfs(int current) {
    usd[current] = true;
    for (int i = 0; i < adjacency_matrix[current].size(); ++i) {
        int nxt = adjacency_matrix[current][i];
        if (!usd[nxt]) {
            cmp[nxt] = cmp[current];
            dfs(nxt);
        }
    }
}

int main() {
    int n,m;
    int b,e;
    ifstream cin("components.in");
    ofstream cout("components.out");
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b >> e;
        adjacency_matrix[b - 1].push_back(e - 1);
        adjacency_matrix[e - 1].push_back(b - 1);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!usd[i]) {
            ++cnt;
            cmp[i] = cnt;
            dfs(i);
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; i++) {
        cout << cmp[i] << " ";
    }
    return 0;
}