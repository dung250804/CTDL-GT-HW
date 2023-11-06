#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream inp;

int main() {
    inp.open("input.txt");
    if(inp.is_open()) {
        int maxVal, n;
        inp >> maxVal >> n;
        int v[n+1];
        int w[n+1];
        int dp[n+1][maxVal+1];
        for(int i = 1; i <= n; i++) {
            dp[i][0] = 0;
            inp >> w[i] >> v[i];
        }
        for(int i = 0; i <= maxVal; i++) {
            dp[0][i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= maxVal; j++) {
                dp[i][j] = dp[i-1][j];
                if(j - w[i] >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
                }
            }
        }
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= maxVal; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << dp[n][maxVal];
    }
}
