#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, m;
    cin >> n >> m;
    int adjacency_matrix[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            adjacency_matrix[i][j] = 0;
        }
    }
    for (int i = 0, in1, in2; i < m; ++i) {
        cin >> in1 >> in2;
        if (adjacency_matrix[in1-1][in2-1]){
            cout << "YES";
            return 0;
        }
        adjacency_matrix[in1-1][in2-1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjacency_matrix[i][j] and adjacency_matrix[j][i] and i!=j){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}