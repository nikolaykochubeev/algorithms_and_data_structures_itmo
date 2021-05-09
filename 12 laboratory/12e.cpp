#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<int> used;

int max_set(int curr){
    if (used[curr] != -1)
        return used[curr];

    int ch_sum = 0;
    int gch_sum = 0;
    for (int ch : g[curr])
        ch_sum += max_set(ch);
    for (int ch : g[curr])
        for (int gch : g[ch])
            gch_sum += max_set(gch);
    used[curr] = max(1 + gch_sum, ch_sum);
    return used[curr];
}

int main(){
    int n;
    cin >> n;
    g.resize(n);
    used.assign(n, -1);
    int root;
    for (int i = 0; i < n; i++){
        int p;
        cin >> p;
        p--;
        if (p == -1) {
            root = i;
            continue;
        }
        g[p].push_back(i);
    }
    cout << max_set(root);
}