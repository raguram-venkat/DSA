#include <iostream>
#include <vector>
using namespace std;

int max_value_dumbbells(int n, int w, vector<int>& weights, vector<int>& values) {
    // Initialize the table with zeros
    vector<vector<int>> table(n+1, vector<int>(w+1, 0));
    
    // Fill in the table using the recurrence relation
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (weights[i-1] > j) {
                table[i][j] = table[i-1][j];
            } else {
                table[i][j] = max(table[i-1][j], table[i-1][j-weights[i-1]] + values[i-1]);
            }
        }
    }
    
    // Return the final solution
    return table[n][w];
}

int main() {
    int n = 3;
    int w = 8;
    vector<int> weights = {3, 4, 5};
    vector<int> values = {30, 50, 60};
    cout << max_value_dumbbells(n, w, weights, values) << endl; 
    return 0;
}