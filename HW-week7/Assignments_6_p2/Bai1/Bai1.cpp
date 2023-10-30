#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

ifstream input;
ofstream output;
char path[100] = "jobs.txt";


int findUnsignedMin(int f[], int length) {
    int a = INT_MAX;
    for(int i = 1; i <= length; i++) {
        if(f[i] >= 0) a = min(a, f[i]);
    }
    return a;
}

void job_sort(int *cmd[2], vector<int>& res,int n, int m) {
    int priority_level[n+1];
    priority_level[0] = -1;
    for(int i = 1; i <= n; i++) {
        priority_level[i] = 0;
    }
    unordered_map<int, vector<int>> graph;
    for(int i = 0; i < m; i++) {
        int u = cmd[i][0];
        int v = cmd[i][1];
        graph[u].push_back(v);
        priority_level[v] += priority_level[u] + 1;
    }
    //for(int i = 0; i <= n; i++) {
    //    cout << priority_level[i] << " ";
    //}
    //cout << endl;
    for(int i = 1; i <= n; i++) {
        int x = findUnsignedMin(priority_level, n);
        for(int j = 1; j <= n; j++) {
            if(x == priority_level[j]) {
                priority_level[j] = -1;
                res.push_back(j);
            }
        }
    }
}

int main() {
    input.open(path);
    output.open("jobs.out");
    if(input.is_open() && output.is_open()) {
        int n, m;
        input >> n >> m;
        int** cmd = new int*[m];

        for (int i = 0; i < m; i++) {
            cmd[i] = new int[2];
            input >> cmd[i][0] >> cmd[i][1];
        }

        vector<int> res;
        job_sort(cmd, res, n, m);

        for (int job : res) {
            cout << job << " ";
            output << job << " ";
        }
        input.close();
        output.close();
    }
}
