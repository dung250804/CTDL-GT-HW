#include <iostream>
#include <vector>

using namespace std;

int degree[1001];

void dfs(int cur, bool visited[], vector<vector<int>> Ma_tran_ke) {
    visited[cur] = true;
    for(int s : Ma_tran_ke[cur]) {
        if(!visited[s])
            dfs(s, visited, Ma_tran_ke);
    }
}

int countConnectedComponents(int n, vector<vector<int>> Ma_tran_ke, bool visited[]){
    int countt = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && Ma_tran_ke[i].size() != 0) {
            countt++;
            dfs(i, visited, Ma_tran_ke);
        }
    }
    return countt;
}

int main() {
    int n, m; cin >> n >> m;
    //setup bậc ra và vào
    for(int i = 0; i < n; i++) {
        degree[i] = 0;
    }

    vector<vector<int>> Ma_tran_ke(n+1);
    //da check dinh do' chua
    bool visited[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    //them dinh?
    for(int i = 0; i < n; i++) {
        vector<int> tmp;
        tmp.push_back(i);
        Ma_tran_ke.push_back(tmp);
    }
    //tao. ma tran ke
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        Ma_tran_ke.at(x).push_back(y);
        Ma_tran_ke.at(y).push_back(x);
        degree[x]++;
        degree[y]++;
    }
    int x = countConnectedComponents(n, Ma_tran_ke, visited);
    if(x == 1) {
        for(int i = 0; i < n; i++) {
            if(degree[i] % 2 != 0) {
                cout << "false";
                return 0;
            }
        }
        cout << "true";
        return 0;
    }
    cout << "false";
}
