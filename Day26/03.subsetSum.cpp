class Solution
{
public:
	bool canPartition(vector<int> &nums)
	{
		int summ = accumulate(nums.begin(), nums.end(), 0);
		if (summ % 2 != 0)
			return false;
		int tar = summ / 2;
		int n = nums.size();

		bool dp[n + 1][tar + 1];

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= tar; j++)
			{
				if (i == 0 && j != 0)
					dp[i][j] = false;
				else if (j == 0)
					dp[i][j] = true;
				else if (j - nums[i - 1] >= 0)
					dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j];
			}

		return dp[n][tar];
	}
};