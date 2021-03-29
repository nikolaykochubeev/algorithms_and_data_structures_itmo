#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Edge{
    long long to{};
    mutable long long weight{};
    Edge() = default;

    friend istream& operator>> (istream& is, Edge& edge){
        is >> edge.to >> edge.weight;
        edge.to--;
        return is;
    }
};

typedef vector<vector<pair<long long, long long>>> edges_lists;
const long long inf = LONG_LONG_MAX;

long long get_mst(long long root, const edges_lists& graph);
bool check_availability(long long from, const edges_lists& graph);
void count_vertex(long long from, const edges_lists& graph, vector<bool>& visited);
void get_condensation(const edges_lists& graph, vector<long long>& components);
void mark_components(long long from, const edges_lists& graph, vector<long long>& components, long long& component);
void get_top_sort(const edges_lists& graph, vector<long long>& top_sort);
void sort_by_time_out(long long from, const edges_lists& graph, vector<bool>& visited, vector<long long>& top_sort);

long long get_mst(long long root, const edges_lists& graph){
    long long result = 0;
    long long n = graph.size();
    vector<long long> min_in_edge = vector<long long>(n, inf);

    for (long long from = 0; from < n; ++from)
        for (auto edge : graph[from])
            min_in_edge[edge.first] = min(min_in_edge[edge.first], edge.second);

    for (long long i = 0; i < n; ++i)
        if (i != root)
            result += min_in_edge[i];

    edges_lists zero_graph = edges_lists(n);
    for (long long from = 0; from < n; ++from)
        for (auto edge : graph[from])
            if (edge.second == min_in_edge[edge.first]){
                edge.second = 0;
                zero_graph[from].push_back(edge);
            }

    if (check_availability(root, zero_graph))
        return result;

    vector<long long> components = vector<long long>(n);
    get_condensation(zero_graph, components);
    long long components_count = 0;
    for (auto component : components)
        components_count = max(components_count, component);
    components_count++;

    edges_lists new_graph = edges_lists(components_count);
    for (long long from = 0; from < n; ++from)
        for (auto edge : graph[from])
            if (components[from] != components[edge.first])
                new_graph[components[from]].emplace_back(components[edge.first], edge.second - min_in_edge[edge.first]);

    return result + get_mst(components[root], new_graph);
}

bool check_availability(long long from, const edges_lists& graph){
    long long n = graph.size();
    vector<bool> visited = vector<bool>(n);
    count_vertex(from, graph, visited);
    for (auto v : visited)
        if (!v)
            return false;

    return true;
}

void count_vertex(long long from, const edges_lists& graph, vector<bool>& visited){
    visited[from] = true;
    for (auto edge : graph[from])
        if (!visited[edge.first])
            count_vertex(edge.first, graph, visited);
}

void get_condensation(const edges_lists& graph, vector<long long>& components){
    long long n = graph.size();
    edges_lists graph_transposed = edges_lists(n);
    for (long long from = 0; from < n; ++from)
        for (auto edge : graph[from])
            graph_transposed[edge.first].emplace_back(from, edge.second);
    vector<long long> order;
    get_top_sort(graph, order);
    long long components_count = 0;

    for (auto from : order)
        if (components[from] == 0)
            mark_components(from, graph_transposed, components, ++components_count);

    for (auto& component : components)
        component--;
}

void get_top_sort(const edges_lists& graph, vector<long long>& top_sort){
    long long n = graph.size();
    vector<bool> visited = vector<bool>(n);

    for (long long from = 0; from < n; ++from)
        if (!visited[from])
            sort_by_time_out(from, graph, visited, top_sort);

    reverse(top_sort.begin(), top_sort.end());
}

void sort_by_time_out(long long from, const edges_lists& graph, vector<bool>& visited, vector<long long>& top_sort){
    visited[from] = true;
    for (auto& edge : graph[from])
        if (!visited[edge.first])
            sort_by_time_out(edge.first, graph, visited, top_sort);
    top_sort.push_back(from);
}

void mark_components(long long from, const edges_lists& graph, vector<long long>& components, long long& component){
    components[from] = component;
    for (auto& edge : graph[from])
        if (components[edge.first] == 0)
            mark_components(edge.first, graph, components, component);
}

int main(){
    ifstream cin("chinese.in");
    ofstream сout("chinese.out");
    long long n, m;
    cin >> n;
    cin >> m;
    edges_lists graph = edges_lists(n);
    long long from;
    pair<long long, long long> edge;
    for (long long i = 0; i < m; ++i){
        cin >> from >> edge.first >> edge.second;
        graph[from - 1].emplace_back(edge.first - 1, edge.second);
    }

    if (check_availability(0, graph)){
        сout << "YES\n";
        сout << get_mst(0, graph) << "\n";
    }
    else
        сout << "NO\n";
    return 0;
}