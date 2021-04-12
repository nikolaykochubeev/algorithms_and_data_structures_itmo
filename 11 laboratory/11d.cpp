#include <bits/stdc++.h>
using namespace std;

const long long INF = 8e18;

struct Edge{
    pair<int,int> vertex;
    long long weight{};

};

struct Vertex{
    vector<int> neigh;
    bool used = false;
};

void dfs(int v, vector<Vertex>& V) {
    for (int i = 0; i < V[v].neigh.size(); i++)
        if (!V[V[v].neigh[i]].used) {
            V[V[v].neigh[i]].used = true;
            dfs(V[v].neigh[i], V);
    }
}


void ford(vector<long long>& dist, int s, const vector<Edge>& graph, int n, vector<Vertex>& V) {
    dist[s] = 0;
    for (int i = 0; i < n-1; i++) {
        for (auto edge : graph) {
            int to = edge.vertex.second;
            int from = edge.vertex.first;
            long long weight = edge.weight;
            if(dist[from] < LONG_LONG_MAX)
                if (dist[to] > dist[from] + weight)
                    dist[to] = max(-INF, dist[from] + weight);
        }
    }
    for (auto edge : graph){
        int to = edge.vertex.second;
        int from = edge.vertex.first;
        long long weight = edge.weight;
        if (!V[from].used && dist[from] < LONG_LONG_MAX && (dist[from] < -INF || dist[to] > dist[from] + weight)){
            V[from].used = true;
            dfs(from , V);
        }
    }

}

int main() {
    ifstream in("path.in");
    ofstream out("path.out");
    int n , m , s;
    in >> n >> m >> s;
    s--;
    vector<Edge> graph;
    vector<Vertex> V(n);
    for(int i = 0; i < m; i++){
        int start , end;
        long long weight;
        in >> start >> end >> weight;
        start--;
        end--;
        Edge tmp;
        tmp.vertex = make_pair(start,end);
        tmp.weight = weight;
        graph.push_back(tmp);
        V[start].neigh.push_back(end);
    }
    vector<long long> dist(n, LONG_LONG_MAX);
    ford(dist, s, graph, n, V);

    for (int i = 0; i < n ; i++) {
        if(dist[i] == LONG_LONG_MAX)
            out << "*";
        else if(V[i].used)
            out << "-";
        else
            out << dist[i];
        out << '\n';
    }
    return 0;
}