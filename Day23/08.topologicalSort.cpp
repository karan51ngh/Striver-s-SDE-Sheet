class Solution
{
public:
	// Function to return list containing vertices in Topological order.
	void dfs(vector<int> *adj, int src, vector<int> &vis, stack<int> &st)
	{
		if (vis[src])
			return;
		vis[src] = 1;
		for (auto v : adj[src])
			dfs(adj, v, vis, st);
		st.push(src);
	}
	vector<int> topoSort(int V, vector<int> adj[])
	{
		// code here
		vector<int> sol;
		vector<int> vis(V, 0);
		stack<int> st;
		for (int i = 0; i < V; i++)
		{
			if (!vis[i])
				dfs(adj, i, vis, st);
		}

		while (!st.empty())
		{
			sol.push_back(st.top());
			st.pop();
		}
		return sol;
	}
};
