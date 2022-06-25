class Solution
{
public:
	int f(vector<vector<int>> &dp, int i, int j)
	{
		int n = dp.size();
		int m = dp[0].size();

		if (i >= 0 && i < n && j >= 0 && j < m)
			return dp[i][j];
		return 1000000007;
	}

	int minPathSum(vector<vector<int>> &grid)
	{
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m));

		for (int i = n - 1; i >= 0; i--)
			for (int j = m - 1; j >= 0; j--)
			{
				if (i == n - 1 && j == m - 1)
					dp[i][j] = grid[i][j];
				else
					dp[i][j] = grid[i][j] + min(f(dp, i + 1, j), f(dp, i, j + 1));
			}
		return dp[0][0];
	}
};