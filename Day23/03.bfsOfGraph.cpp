class Solution
{
public:
	void bfs(vector<int> adj[], int src, vector<int> &visited, vector<int> &sol)
	{
		queue<int> q;
		q.push(src);

		while (!q.empty())
		{
			int x = q.front();
			q.pop();

			if (!visited[x])
			{
				visited[x] = 1;
				sol.push_back(x);
				for (auto v : adj[x])
					q.push(v);
			}
		}
	}
	// Function to return Breadth First Traversal of given graph.
	vector<int> bfsOfGraph(int V, vector<int> adj[])
	{
		// Code here
		vector<int> sol;
		vector<int> visited(V, 0);
		bfs(adj, 0, visited, sol);
		return sol;
	}
};