#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min_edit_distance(string s, string t) {
    // Initialize the table with zeros
    int n = s.length(), m = t.length();
    vector<vector<int>> table(n+1, vector<int>(m+1, 0));
    
    // Fill in the table using the recurrence relation
    for (int i = 1; i <= n; i++) {
        table[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
        table[0][j] = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                table[i][j] = table[i-1][j-1];
            } else {
                table[i][j] = min({table[i-1][j], table[i][j-1], table[i-1][j-1]}) + 1;
            }
        }
    }
    
    // Return the final solution
    return table[n][m];
}

int main() {
    string s = "abc";
    string t = "defg";
    cout << min_edit_distance(s, t) << endl;  // Output: 3
    return 0;
}