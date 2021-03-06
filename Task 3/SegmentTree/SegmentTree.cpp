#include<bits/stdc++.h>
using namespace std;

void segtree(vector<int> &seg,int n)
{   

    
    for(int i=n-1;i>0;i--)
    {
        seg[i]=seg[i<<1]+seg[i<<1|1];
    }
}

int query(vector<int> seg,int a,int b,int n)
{   int s=0;
    a+=n;
    b+=n;
    while(a<=b)
    {
        if(a&1)
        {
            s+=seg[a++];
        }
        if(!(b&1))
        {
            s+=seg[b--];
        }
        a>>=1;
        b>>=1;
    
    }
    return s;
}
int main()
{

    int n;
    cout<<"Enter N\n";
    cin>>n;
    vector<int> v;
    vector<int> seg(2*n);
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
        seg[i+n]=v[i];
    }
     
    segtree(seg,n);

    cout<<"Enter range\n";
    int l,r;
    cin>>l>>r;
    cout<<query(seg,l,r,n);
}