#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ifstream cin("pathbge1.in");
    ofstream cout("pathbge1.out");
    int n, m;
    cin >> n >> m;
    vector<int> adjacency_vector[n];

    for (int i = 0; i < m; i++) {
        int b, e;
        cin >> b >> e;
        adjacency_vector[b - 1].push_back(e - 1);
        adjacency_vector[e - 1].push_back(b - 1);
    }

    queue<int> bfs_queue;
    bfs_queue.push(0);
    vector<int> distance_vector(n, 400001);
    distance_vector[0] = 0;

    while (!bfs_queue.empty()) {
        int v = bfs_queue.front();
        bfs_queue.pop();
        for (auto item : adjacency_vector[v]) {
            if (distance_vector[item] == 400001) {
                distance_vector[item] = distance_vector[v] + 1;
                bfs_queue.push(item);
            }
        }
    }

    for (auto item : distance_vector) {
        cout << item << ' ';
    }
    return 0;
}