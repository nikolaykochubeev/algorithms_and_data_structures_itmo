#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("input.txt", "w", stdout);
    double n;
    cin >> n;
    vector <vector<int>> adjacency_matrix(n);
    for (auto &string: adjacency_matrix){
        string.resize(n);
        for (auto &element: string){
            cin >> element;
        }
    }
}