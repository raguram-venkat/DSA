#include <bits/stdc++.h>
using namespace std;
void compute(int l1, int l2, int arr[]){
    while (l1!=l2)
    {
        if(l1>l2){
            l1/=2;
        }else{
            l2/=2;
        }
    }
    cout<<arr[l1];
}
int main()
{
    int n, x, y,l1,l2;
    cin >> n;
    cin >> x;
    cin >> y;
    int arr[n+1];
    for (int i = 0; i < n; i++)
    {
        
        cin >> arr[i+1];
        if(arr[i+1]==x){
            l1=i+1;
        }else if(arr[i+1] == y){
            l2=i+1;
        }
    }
    compute(l1,l2,arr);
    return 0;
}