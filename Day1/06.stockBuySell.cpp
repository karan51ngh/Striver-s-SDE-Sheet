class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int minn = prices[0];
		int prof = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			minn = min(minn, prices[i]);
			prof = max(prof, prices[i] - minn);
		}
		return prof;
	}
};