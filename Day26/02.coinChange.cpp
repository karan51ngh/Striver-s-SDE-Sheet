class Solution
{
public:
	long coinChange(vector<int> &coins, int amount)
	{
		int n = coins.size();
		long dp[n + 1][amount + 1];

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= amount; j++)
			{
				if (i == 0 && j != 0)
					dp[i][j] = 1000000007;
				else if (j == 0)
					dp[i][j] = 0;
				else if (j - coins[i - 1] >= 0)
					dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		if (dp[n][amount] >= 1000000007)
			return -1;
		else
			return dp[n][amount];
	}
};