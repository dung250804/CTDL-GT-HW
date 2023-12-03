#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int cur, bool visited[], vector<vector<int>> Ma_tran_ke) {
    visited[cur] = true;
    for(int s : Ma_tran_ke[cur]) {
        if(!visited[s])
            dfs(s, visited, Ma_tran_ke);
    }
}

int countConnectedComponents(int n, vector<vector<int>> Ma_tran_ke, bool visited[]){
    int countt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            countt++;
            dfs(i, visited, Ma_tran_ke);
        }
    }
    return countt;
}

 bool isEdgeConnected(int n, vector<vector<int>>& Ma_tran_ke, int x, int y, int before) {
    Ma_tran_ke[x].erase(remove(Ma_tran_ke[x].begin(), Ma_tran_ke[x].end(), y), Ma_tran_ke[x].end());
    Ma_tran_ke[y].erase(remove(Ma_tran_ke[y].begin(), Ma_tran_ke[y].end(), x), Ma_tran_ke[y].end());

    bool visited[n + 1];
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }

    int components = countConnectedComponents(n, Ma_tran_ke, visited);

    Ma_tran_ke[x].push_back(y);
    Ma_tran_ke[y].push_back(x);

    return components == before;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> Ma_tran_ke(n+1);
    vector<pair<int,int>> input;
    //da check dinh do' chua
    bool visited[n+1];
    for(int i = 0; i <= n; i++) {
        visited[i] = false;
    }
    //them dinh?
    for(int i = 0; i <= n; i++) {
        vector<int> tmp;
        tmp.push_back(i);
        Ma_tran_ke.push_back(tmp);
    }
    //tao. ma tran ke
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        input.push_back({x,y});
        Ma_tran_ke.at(x).push_back(y);
        Ma_tran_ke.at(y).push_back(x);
    }
    int before = countConnectedComponents(n, Ma_tran_ke, visited);

    for(auto& s : input) {
        if(!isEdgeConnected(n, Ma_tran_ke, s.first, s.second, before)) {
            cout << "true";
            return 0;
        }
    }

    cout << "false";
}
