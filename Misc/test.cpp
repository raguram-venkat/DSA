#include<bits/stdc++.h>
using namespace std;

int fun3(string s,string t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<int>>(n+1,vector<int>(m+1,0)) t;
    for(int i=0;i<=n;i++)
    t[i][0]=i;
    for(int i=0;j<=n;j++)
    t[0][j]=j;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            t[i][j]=t[i-1][j-1];
            else
            t[i][j]=min({t[i][j],t[i][j-1],t[i-1][j]})+1;
        }
    }

    return t[n][m];
}

int fun2(vector<int> &a,vector<int> &b)
{
    int n=a.size();
    int m=b.size();
    vector<vector<int>>(n+1,vector<int>(m+1,0))t;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                t[i][j]=t[i-1][j-1]+1;
                max_element=max(max_element,t[i][j]);

            }
           
        }
    }

    return max_element;
}

int fun1(int n,int k,vector<int> &weight,vector<int> &value)
{
    vector<vector<int>>(n+1,vector<int>(k+1,0)) t;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(weight[i-1]>j)
            {
               t[i][j]=t[i-1][j];
            }
            else
             t[i][j]=max(t[i-1][j],values[i-1]+t[i-1][j-weight[i-1]]);
        }
    }
}


int fun5(vector<int> &p)
{
    int n=p.size()-1;
    vector<vector<int>>t(n,vector<int>(n,0)) t;
    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            int j=i-1+len;
            t[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                t[i][j]=min(t[i][j],t[i][k]+t[k+1][j]+p[i]*p[j+1]*p[k+1])
            }


        }
    }

    return t[0][n-1];
}


int fun6(vector<int> & a,int k)
{
    vector<int>(k+1,INT_MAX)t;
    t[0]=0;
    int n=a.size();
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]<=i)
            {
                int sub_res=t[i-a[j]];
                if(sub_res!=INT_MAX)
                t[i]=
            }
        }

    }

}

int fun9(vector<int> &a)
{
    int n=a.size();
    vector<vector<int>>(n,vector<int>(n,0)) t;

    for(int len=1;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            int j=i-1+len;
            int parity=(n-len)%2;
            if(i==j)
            t[i][j]=(parity?-a[i]:a[i]);
            else if(parity)
            t[i][j]=min(a[i+1][j]-a[i],a[i][j-1]-a[j]);
            else
            t[i][j]=max(a[i+1][j]-a[i],a[i][j-1]-a[j]);
        }
    }

    return t[0][n-1];
}


int fun6(vector<int> &coupons,int k)
{
    
    vector<int>(k+1,INT_MAX)t;
    t[0]=0;

    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coupons[j]<=i)
            {
                t[i][j]=
            }
        }
    }
}