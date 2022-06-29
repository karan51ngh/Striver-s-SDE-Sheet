class Solution
{
public:
	void f(vector<int> &arr, int ssf, int ctr, int N, vector<int> &sol)
	{
		if (ctr == N)
			sol.push_back(ssf);
		else
		{
			f(arr, ssf, ctr + 1, N, sol);
			f(arr, ssf + arr[ctr], ctr + 1, N, sol);
		}
	}

	vector<int> subsetSums(vector<int> arr, int N)
	{
		// Write Your Code here
		vector<int> sol;
		f(arr, 0, 0, N, sol);
		sort(sol.begin(), sol.end());
		return sol;
	}
};