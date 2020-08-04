/*
# Dijkastra Implementation

Question:https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/

*/
// Write your code here
#include <iostream>
#include<bits/stdc++.h>
# define ll long long int
using namespace std;


    vector<pair<int,int>>q[100000];
    
    vector<int> dijkastra(int n)
    {
        bool vis[n+1];
        vector<int> dist(n+1);
        for(int i=0;i<=n;i++)
        {
            dist[i]=100000;
            vis[i]=false;
        }
        dist[1]=0;
        multiset<pair<int,int>>s;
        s.insert({0,1});
        
        while(!s.empty())
        {
            pair<int,int> t= *s.begin();
            s.erase(s.begin());
            int e=t.second;
            
            if(vis[e]==true)
                continue;
                
            vis[e]=true;
            
            for(int i=0;i<q[e].size();i++)
            {
                int w=q[e][i].first;
                int x=q[e][i].second;
                if(dist[x]>dist[e]+w)
                {
                    dist[x]=dist[e]+w;
                    s.insert({dist[x],x});
                }
            }
        }
        return dist;
        
    }
    
    
    int main()
    {
        ll nodes, edges;
        cin>>nodes>>edges;
        for(ll i=0;i<edges;i++)
        {
            ll a,b,w;
            cin>>a>>b>>w;
            q[a].push_back({w,b});
        }
        vector<int> dist=dijkastra(nodes);
        for(ll i=2;i<dist.size();i++)
        cout<<dist[i]<<" ";
    }