#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjList;

    Graph(int V) {
        vertices = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool dfs(int startVertex) {
        vector<bool> visited(vertices, false);
        stack<int> s;

        s.push(startVertex);

        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();

            if (!visited[currentVertex]) {
                cout << currentVertex << " ";
                visited[currentVertex] = true;
            }

            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }


            bool allVisited = true;
            for (bool v : visited) {
                if (!v) {
                    allVisited = false;
                    break;
                }
            }

            if (allVisited) {
                for (int neighbor : adjList[currentVertex]) {
                    if (neighbor == startVertex) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    int n, m; cin >> n >> m;
    Graph g(n);

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }

    bool result = g.dfs(0);
    cout << endl << result;
}
