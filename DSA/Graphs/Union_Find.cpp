#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

int findroot(int a,int par[])
{
    if(par[a]==a)
    return a;
    else
    {
        int z=findroot(par[a],par);
        par[a]=z;
        return z;
    }
}


/* This function does union of 2 nodes a and b */
// a : node 1 
// b : node 2
// par : empty array (n+1) size with all elements as i
// rank1 : empty array (n+1) size with all elements as 1
void union_( int x, int y, int par[], int rank1[]) 
{
    int a=findroot(x,par);
    int b=findroot(y,par);
    if(a!=b)
    {
        if(rank1[a]<rank1[b])
        {
            int c=a;
            a=b;
            b=c;
        }
        par[b]=a;
        if(rank1[a]==rank1[b])
        rank1[a]++;
    }
    
}

/* This function checks whether 2 nodes x and y are connected or not */
// x : node 1 
// y : node 2
// par : empty array (n+1) size with all elements as i
// rank1 : empty array (n+1) size with all elements as 1
bool isConnected(int x,int y, int par[], int rank1[]) {
    int xx=findroot(x,par);
    int yy=findroot(y,par);
    if(xx==yy)
    return true;
    else
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        int par[n+1];
        int rank1[n+1];

        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    int q;
    cin>>q;
    while(q--) {
        int a,b;
        char c;
        cin>>c>>a>>b;
        if(c=='U')
        {
            union_(a,b, par, rank1);
        }
        else
        cout<<isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
  // } Driver Code Ends
