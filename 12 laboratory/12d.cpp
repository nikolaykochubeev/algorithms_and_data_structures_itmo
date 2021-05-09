#include <fstream>
#include <vector>
using namespace std;
vector<vector<int>> dp;

void func(int i, int j){
    dp[i][j] += dp[i - 2][j - 1] + dp[i - 2][j + 1] + dp[i - 1][j - 2] + dp[i + 1][j - 2];
}

int main(){
    ifstream fin("knight2.in");
    ofstream fout("knight2.out");
    int n, m;
    fin >> n >> m;
    n += 2;
    m += 2;
    dp.resize(n + 1, vector<int> (m + 1, 0));
    dp[2][2] = 1;
    int i = 2, j = 2, x, y;
    while (i != n - 1 || j != m - 1){
        x = i, y = j;
        while (x >= 2 && y < m)
            func(x--, y++);
        i == n - 1 ? j++ : i++;
    }
    func(n - 1, m - 1);
    fout << dp[n - 1][m - 1];
    return 0;
}