class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int in_degree[numCourses];
        for(int i=0;i<numCourses;i++)
            in_degree[i]=0;
        vector<int>q[numCourses];
        vector<int>t;
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            in_degree[u]++;
            q[v].push_back(u);
        }
        queue<int>qp;
        for(int i=0;i<numCourses;i++)
        {
            if(in_degree[i]==0)
                qp.push(i);
        }
        if(qp.empty()==true)
        {
            vector<int>o;
            return o;
        }
        while(!qp.empty())
        {
            int j=qp.front();
            qp.pop();
            t.push_back(j);
           
            for(int i=0;i<q[j].size();i++)
            {
                in_degree[q[j][i]]--;
                
                if(in_degree[q[j][i]]==0)
                    qp.push(q[j][i]);
            }
        }
        if(t.size()==numCourses)
            return t;
        else
            {
            vector<int>o;
            return o;
        }
    }
};