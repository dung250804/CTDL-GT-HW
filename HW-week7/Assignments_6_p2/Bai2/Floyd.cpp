#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream input;
char inputPath[100] = "connection.txt";
ofstream output;
char outputPath[100] = "connection.out";
const int INF = INT_MAX; // Giá trị vô cùng đại diện cho khoảng cách vô hạn

struct edge {
    int u, v, w;

    edge(int x, int y, int z) {
        u = x;
        v = y;
        w = z;
    }
};

vector<edge> edgeList;
const int maxComputer = 1000;
int parent[maxComputer];
int n, m;
void set_default() {
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }
}

int findParent(int a) {
    if(a == parent[a]) return a;
    return parent[a] = findParent(parent[a]);
}

bool isUnion(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a == b) return false;
    parent[b] = a;
    return true;
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

void kruskal() {
    int totalCost = 0;
    vector<edge> mst;
    sort(edgeList.begin(), edgeList.end(), cmp);
    for(int i = 0; i < m; i++) {
        if(mst.size() >= n-1) break;
        edge tmp = edgeList[i];
        if(isUnion(tmp.u, tmp.v)) {
            mst.push_back(tmp);
            totalCost += tmp.w;
        }
    }
    output << totalCost << endl;
    for(edge tmp : mst) {
        output << tmp.u << " " << tmp.v << " " << tmp.w << endl;
    }
}

int main() {
    input.open(inputPath);
    output.open(outputPath);
    if(input.is_open() && output.is_open()) {

        input >> n >> m;

        for (int i = 0; i < m; i++) {
            int u, v, w;
            input >> u >> v >> w;
            edge a = edge(u, v, w);
            edgeList.push_back(a);
        }
        set_default();
        kruskal();
        output.close();
        input.close();
    }
}

