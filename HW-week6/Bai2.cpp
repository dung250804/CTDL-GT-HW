#include <iostream>
#include <vector>
using namespace std;

void dfs(int cur, bool visited[], vector<vector<int>> Ma_tran_ke) {
    visited[cur] = true;
    for(int s : Ma_tran_ke[cur]) {
        if(!visited[s])
            dfs(s, visited, Ma_tran_ke);
    }
}

int shortest_part(int start, int last, int n, vector<vector<int>> Ma_tran_ke) {
    bool visited[n + 1] = {false};
    dfs(start, visited, Ma_tran_ke);
    if(visited[last]) {
        for(int i = 0; i <= n; i++) {
            visited[i] = false;
        }
        int part[n+1];
        for(int i = 0; i <= n; i++) {
            part[i] = n+1;
        }
        part[start] = 0;
        for(int i = 1; i <= n; i++) {
            int cur = part[0];
            //tim min part
            for(int j = 1; j <= n; j++) {
                if(!visited[j])
                cur = min(cur, part[j]);
            }
            for(int j = n; j >= 1; j--) {
                if(part[j] == cur) {
                    cur = j;
                }
            }
            visited[cur] = true;
            //update part
            for(int s : Ma_tran_ke.at(cur)) {
                if(!visited[s]) {
                    part[s] = min(part[cur]+1, part[s]);
                }
            }
        }
        return part[last];
    }
    return -1;
}


int main() {
    int n, m, X, Y; cin >> n >> m >> X >> Y;
    vector<vector<int>> Ma_tran_ke(n+1);
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
        Ma_tran_ke.at(x).push_back(y);
        Ma_tran_ke.at(y).push_back(x);
    }
    cout << shortest_part(X, Y, n, Ma_tran_ke);
}
