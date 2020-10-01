 /*
Question: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/?track=SPC-Graph&batchId=145

Solution:

using namespace std;


/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/


void dfs(int s, vector<int> g[], bool vis[])
{
    vis[s] = true;
    //list adjList = adjLists[vertex];
    
    cout << s << " ";
 
    ///list::iterator i;
    for(u:g[s])
        if(!vis[u])
            dfs(u,g,vis);

}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0,g,vis);
        
        cout<<endl;

    }
}