#include<iostream>

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&q,vector<bool>&vis,int i,stack<int>&s)
{
	vis[i]=true;
    for(int j=0;j<q[i].size();j++)
    {
        if(!vis[q[i][j]])
        dfs(q,vis,q[i][j],s);
    }
    s.push(i);
}

void dfss(int i,vector<vector<int>>&d,vector<bool>&vis)
{
    vis[i]=true;
    cout<<i;
    for(int j=0;j<d[i].size();j++)
    {
        if(vis[d[i][j]]==false)
        {
            dfss(d[i][j],d,vis);
        }
    }
}

void kosaraju(vector<vector<int>>&q,int n)
{
	vector<bool>vis(n+1);
	for(int i=0;i<=n;i++)
		vis[i]=false;
	stack<int>s;

	for(int i=0;i<=n;i++)
	{
		if(!vis[i])
			dfs(q,vis,i,s);
	}

    vector<vector<int>>d(n+1);
 
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<q[i].size();j++)
        {
           d[q[i][j]].push_back(i);
        }
    }
    for(int i=0;i<=n;i++)
		vis[i]=false;

   
 while(!s.empty())
    {
        int u=s.top();
        
        s.pop();
       if(u==0)
       continue;
            if(vis[u]==true)
            continue;
            else
            {dfss(u,d,vis);
        
        cout<<endl;}
    }
}


int main()
{
	int n,m,j=0;
		int a,b;
	cin>>n>>m;
	vector<vector<int>>q(n+1);
	
	while(j<m)
	{
	
		cin>>a>>b;

		
		q[a].push_back(b);

		j++;
	
	}

	kosaraju(q,n);
}