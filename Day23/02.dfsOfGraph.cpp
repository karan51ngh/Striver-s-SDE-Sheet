
class Solution
{
public:
	// Function to return a list containing the DFS traversal of the graph.
	void dfs(vector<int> adj[], int src, vector<int> &visited, vector<int> &sol)
	{
		visited[src] = 1;
		sol.push_back(src);
		for (auto v : adj[src])
			if (!visited[v])
				dfs(adj, v, visited, sol);
	}
	vector<int> dfsOfGraph(int V, vector<int> adj[])
	{
		// Code here
		vector<int> sol;
		vector<int> visited(V, 0);

		dfs(adj, 0, visited, sol);

		return sol;
	}
};