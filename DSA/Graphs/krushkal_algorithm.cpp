
// Write your code here
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
int par[MAX];
pair <int, pair<int, int> > pp[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        par[i] = i;

}
int root(int x)
{
  while(par[x] != x)
    {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

void union_(int x,int y)
{
    int h=root(x);
    int p=root(y);
    par[h]=par[p];
}
void krushkal(pair<int,pair<int,int>>pp[MAX],int edges)
{
    int minimum_cost=0,x,y,cost;
	for(int i=0;i<edges;i++)
	{
		cost=pp[i].first;
		 x=pp[i].second.first;
		 y=pp[i].second.second;
        if(root(x)!=root(y))
        {
            minimum_cost=minimum_cost+cost;
            union_(x,y);
        }
		
	}
    cout<<minimum_cost;
}

int main(){
	int nodes,edges;
	cin>>nodes>>edges;
	initialize();
	//pair<int,pair<int,int>>pp;
    int edge=0;
	while(edge<edges)
	{
		int x,y,c;
		cin>>x>>y>>c;
		pp[edge]=make_pair(c,make_pair(x,y));
		edge++;
	}
	sort(pp,pp+edges);
	krushkal(pp,edges);
}