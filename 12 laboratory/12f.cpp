#include <fstream>
#include <vector>
using namespace std;

const int INF = 1e9;
vector<pair<int, vector<int>>> g;
vector<int> used;

int max_set(int curr){
    if (used[curr] != -INF){
        return used[curr];
    };
    int ch_sum = 0;
    int gch_sum = 0;
    for (int ch : g[curr].second){
        ch_sum += max_set(ch);
    }

    for (int ch : g[curr].second)
        for (int gch : g[ch].second)
            gch_sum += max_set(gch);

    used[curr] = max(max(g[curr].first, 0) + gch_sum, ch_sum);
    return used[curr];
}

int main(){
    ifstream fin("selectw.in");
    ofstream fout("selectw.out");
    int n;
    fin >> n;
    g.resize(n);
    used.assign(n, -INF);
    int root;
    for (int i = 0; i < n; i++){
        int p, q;
        fin >> p >> q;
        p--;
        g[i].first = q;
        if (p == -1) {
            root = i;
            continue;
        }
        g[p].second.push_back(i);
    }
    fin.close();
    fout << max_set(root);
    fout.close();
}