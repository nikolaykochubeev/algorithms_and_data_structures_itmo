#include <fstream>
#include <vector>
using namespace std;

void dfs1(vector <vector<int> > &a, vector <bool> &used, vector <int> &ans, int v){
    used[v] = true;
    for (int i = 0; i < a[v].size(); i++){
        if (!used[a[v][i]]){
            dfs1(a, used, ans, a[v][i]);
        }
    }
    ans.push_back(v);
}

void dfs2(vector <vector <int> > &a_t, vector <int> &comp, int v, int num){
    comp[v] = num;
    for (int i = 0; i < a_t[v].size(); i++){
        if (comp[a_t[v][i]] == -1){
            dfs2(a_t, comp, a_t[v][i], num);
        }
    }
}

int main()
{
    ifstream cin("cond.in");
    ofstream cout("cond.out");

    int n, m, x, y;
    cin >> n >> m;
    vector <vector <int> > a(n, vector <int> ());
    vector <vector <int> > a_t(n, vector <int> ());
    vector <bool> used(n, false);
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        a[--x].push_back(--y);
        a_t[y].push_back(x);
    }
    vector <int> ans;
    for (int i = 0; i < n; i++){
        if (!used[i]){
            dfs1(a, used, ans, i);
        }
    }
    vector <int> comp(n, -1);
    int num = 1;
    for (int i = ans.size() - 1; i >= 0; i--){
        if (comp[ans[i]] == -1){
            dfs2(a_t, comp, ans[i], num);
            num++;
        }
    }
    cout << num - 1 << std::endl;
    for (int i = 0; i < n; i++){
        cout << comp[i] << ' ';
    }
    return 0;
}