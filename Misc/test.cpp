#include<vector>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int n,int k,int *a)
{
    int left=0;
    int right=n-1;
    int mid;
    while(left<right)
    {
         mid=(right+left)/2;

        if(a[mid]==k)
        {
            return mid;
        }

        if(a[mid]<k)
        {
            left=mid+1;
        }

        if(a[mid]>k)
        {
            right=mid;
        }

    }

    return mid;
}

void merge(int a[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;

    int l[n1];
    int m[n2];

    for(int i=0;i<n1;i++)
    {
        l[i]=a[p+i];
    }

    for(int i=0;i<n2;i++)
    {
        m[i]=a[q+i+1];
    }

    int mp=0;
    int lp=0;
    int ap=p;

    while(lp<n1 && mp<n2)
    {
        if(l[lp]<=m[mp])
        {
            a[ap]=l[lp];
            ap++;
            lp++;
        }

        else
        {
            a[ap]=m[mp];
            ap++;
            mp++;
        }

    }

        while(mp<(n2))
        {
            a[ap]=m[mp];
            ap++;
            mp++;
        }
    

     while(lp<(n1))
        {
            a[ap]=l[lp];
            ap++;
            lp++;
        }
   
}


void mergeSort(int *a,int l,int r)
{
    if(l<r)
    {
        int mid= (l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

int main()
{
    
    int a[100]={56,84,1,2,43,8,9,34,32,45};
    int c=binarySearch(6,9,a);
    mergeSort(a,0,9);
    for(int i=0;i<9;i++)
    cout<<a[i];


}