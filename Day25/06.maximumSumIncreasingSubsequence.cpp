class Solution
{

public:
	int maxSumIS(int arr[], int n)
	{
		// Your code goes here
		vector<int> dp(n);
		for (int i = 0; i < n; i++)
		{
			dp[i] = arr[i];
			for (int j = 0; j < i; j++)
			{
				if (arr[i] > arr[j])
					dp[i] = max(dp[i], arr[i] + dp[j]);
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};