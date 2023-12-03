#include <iostream>
#include <queue>

using namespace std;

int image[1001][1001];

void flood_fill_BFS(int n, int m, int i, int j, int newColor) {
    int oldColor = image[i][j];
    if(oldColor == newColor) return;
    queue<pair<int, int>> Queue;
    Queue.push({i, j});
    while(!Queue.empty()) {
        pair<int, int> cur = Queue.front();
        Queue.pop();
        i = cur.first;
        j = cur.second;
        if(i < 0 || i >= n || j < 0 || j >= m || image[i][j] != oldColor) {
            continue;
        } else {
            image[i][j] = newColor;
            Queue.push({i+1, j});
            Queue.push({i, j+1});
            Queue.push({i-1, j});
            Queue.push({i, j-1});
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    int x, y, c; cin >> x >> y >> c;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> image[i][j];
        }
    }
    flood_fill_BFS(n,m,x,y,c);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

