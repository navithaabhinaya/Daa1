//Topological sorting
#include<iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX = 20;

vector<int> adj[MAX];
bool visited[MAX];
stack<int> topoOrder;

void dfs(int vertex) {
    visited[vertex] = true;
    for (int i = 0; i < adj[vertex].size(); i++) {
        int neighbor = adj[vertex][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
    topoOrder.push(vertex);
}

int main() 
{
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter edge " << i + 1 << " (u v): ";
        cin >> u >> v;
        adj[u].push_back(v); // Assuming the graph is directed
    }

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    cout << "Topological ordering of vertices: ";
    while (!topoOrder.empty()) {
        cout << topoOrder.top() << " ";
        topoOrder.pop();
    }
    cout << endl;

    return 0;
}
