#include <fstream>
using namespace std;


int main(){
    ifstream cin("input.txt");
    ofstream cout(" qoutput.txt");
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
        adjacency_matrix[in1-1][in2-1] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adjacency_matrix[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}