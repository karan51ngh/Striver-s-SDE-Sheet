class Solution
{
public:
	// Function to find minimum number of attempts needed in
	// order to find the critical floor.
	int eggDrop(int n, int k)
	{
		// your code here
		int dp[n + 1][k + 1];

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= k; j++)
			{
				if (i == 0)
					dp[i][j] = 1000000007;
				else if (i == 1)
					dp[i][j] = j;
				else if (j == 0)
					dp[i][j] = 0;
				else if (j == 1)
					dp[i][j] = 1;
				else
				{
					int minn = 1000000007;
					for (int k = 1; k <= j; k++)
						minn = min(minn, 1 + max(dp[i - 1][k - 1], dp[i][j - k]));

					dp[i][j] = minn;
				}
			}

		return dp[n][k];
	}
};