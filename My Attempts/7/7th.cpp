#include <bits/stdc++.h>
using namespace std;
void compute(int n, int k, priority_queue<int> pq)
{
    int result = 0;
    for (int i = 0, temp1, temp2; i < k; i++)
    {
        temp1 = pq.top();
        temp2 = temp1 / 2;
        result += temp1 - temp2;
        pq.pop();
        pq.push(temp2);
    }
    cout << result;
}
int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;
    for (int i = 0, temp; i < n; i++)
    {
        cin >> temp;
        pq.push(temp);
    }
    compute(n, k, pq);
    return 0;
}