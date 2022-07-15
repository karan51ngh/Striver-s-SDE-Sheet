class Solution
{
public:
	void bfsCheck(vector<vector<int>> &graph, vector<int> &visited, bool &ans, int src)
	{
		queue<int> q;
		int flip = -1;
		unordered_set<int> s1;
		unordered_set<int> s2;
		s1.insert(src);
		q.push(src);
		queue<int> sq;
		queue<int> eq;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();

			if (s1.find(x) != s1.end() && s2.find(x) != s2.end())
			{
				ans = false;
				return;
			}

			if (!visited[x])
			{
				visited[x] = 1;

				for (auto v : graph[x])
				{
					if (flip == 1)
					{
						s1.insert(v);
						sq.push(v);
					}
					else if (flip == -1)
					{
						s2.insert(v);
						sq.push(v);
					}
				}
			}

			if (q.empty())
			{
				flip = flip * -1;
				q = sq;
				sq = eq;
			}
		}
	}
	bool isBipartite(vector<vector<int>> &graph)
	{
		int n = graph.size();

		vector<int> visited(n, 0);
		bool ans = true;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				bfsCheck(graph, visited, ans, i);
				if (ans == false)
					break;
			}
		}
		return ans;
	}
};