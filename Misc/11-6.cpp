#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCoupons(int k, vector<int>& coupons) {
    int n = coupons.size();
    vector<int> dp(k+1, INT_MAX); // dp[i] stores minimum number of coupons needed to make value i
    dp[0] = 0; // base case: 0 coupons needed to make value 0
    
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (coupons[j] <= i) {
                int sub_res = dp[i - coupons[j]];
                if (sub_res != INT_MAX) {
                    dp[i] = min(dp[i], sub_res + 1);
                }
            }
        }
    }
    
    return (dp[k] == INT_MAX) ? -1 : dp[k];
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> coupons(n);
    for (int i = 0; i < n; i++) {
        cin >> coupons[i];
    }
    int ans = minCoupons(k, coupons);
    cout << ans << endl;
    return 0;
}