class Solution
{
public:
	void DFS(vector<vector<char>> &grid, int i, int j, int &n, int &m)
	{
		if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1')
		{
			grid[i][j] = 'v';
			DFS(grid, i, j + 1, n, m);
			DFS(grid, i + 1, j, n, m);
			DFS(grid, i, j - 1, n, m);
			DFS(grid, i - 1, j, n, m);
		}
	}
	int numIslands(vector<vector<char>> &grid)
	{
		int n = grid.size();
		int m = grid[0].size();

		int count = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == '1')
				{
					count += 1;
					DFS(grid, i, j, n, m);
				}
			}
		}
		return count;
	}
};