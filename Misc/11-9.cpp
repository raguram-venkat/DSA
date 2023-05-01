#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gameScore(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            int parity = (n - len) % 2;
            
            if (i == j) {
                dp[i][j] = parity ? -a[i] : a[i];
            } else if (parity) {
                dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j]);
            } else {
                dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j]);
            }
        }
    }
    
    return dp[0][n-1];
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int scoreDiff = gameScore(a);
    cout << scoreDiff << endl;
    
    return 0;
}