#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, i;
    cin >> n >> m;
    string a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<string, int> freq;
    

    for (int i = 0; i < n; i++)
    {
        sort(a[i].begin(), a[i].end());

        freq[a[i]]++;
        cout<< freq[a[i]]<<endl;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}
