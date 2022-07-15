class Solution {
public:
    void DFScheck(vector<int> graph[],int src,vector<int> &visited,vector<int> &visitedDFS,bool &ans)
    {
        if(ans)
            return;
        else if(visited[src] == 1 && visitedDFS[src] == 0)
            return;
        else if(visited[src] == 1 && visitedDFS[src] == 1)
        {    
            ans = true;
            return;
        }
        else if(!visited[src]) 
        {
            visited[src]  = 1;
            visitedDFS[src] = 1;

            for(auto v: graph[src])
            {
                DFScheck(graph,v,visited,visitedDFS,ans);
            }
            visitedDFS[src] = 0;
        }
    }
    bool cycleCheck(vector<int> graph[],int n)
    {
        vector<int> visited(n,0);
        vector<int> visitedDFS(n,0);
        bool ans = false;
        for(int i=0; i <n; i++)
        {
            DFScheck(graph,i,visited,visitedDFS,ans);
            if(ans)
                break;
        }
        return !ans;
    }
    bool canFinish(int n, vector<vector<int>>& prer)
    {
        int E = prer.size();
        vector<int> graph[n];
        for(int i=0; i < E; i++)
            graph[prer[i][1]].push_back(prer[i][0]);
        
        return cycleCheck(graph,n);
    }
};	