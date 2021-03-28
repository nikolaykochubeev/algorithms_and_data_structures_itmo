#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a-1]++;
        v[b-1]++;
    }
    for (auto item : v)
        cout << item << ' ';

    return 0;
}