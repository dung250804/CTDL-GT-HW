#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m, countt = 0;
    cin >> n >> m;
    map<pair<int, int>, int> parallel_edges;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        pair<int, int> pair1 = make_pair(x, y);
        pair<int, int> pair2 = make_pair(y, x);
        parallel_edges[pair1]++;
        parallel_edges[pair2]++;
    }

    for (const auto& s : parallel_edges) {
        countt += s.second - 1;
    }
    countt /= 2;
    cout << countt;
}
