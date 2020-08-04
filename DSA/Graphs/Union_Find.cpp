

/*
Quuestion:

https://practice.geeksforgeeks.org/problems/union-find/1



Solution:

*/

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
© 2020 GitHub, Inc.