#include <fstream>
#include <vector>
using namespace std;

int main(){

    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;
    cin >> n;
    vector <vector<int>> adjacency_matrix(n);
    for (auto &string: adjacency_matrix){
        string.resize(n);
        for (auto &element: string){
            cin >> element;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((adjacency_matrix[i][j]) and (adjacency_matrix[j][i] and (i=!j))){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}