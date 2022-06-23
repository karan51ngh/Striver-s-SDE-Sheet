class Solution
{
public:
	int findDuplicate(vector<int> &a)
	{
		unordered_map<int, int> m;
		for (int i = 0; i < a.size(); i++)
		{
			if (m[a[i]] == 1)
				return a[i];
			else
				m[a[i]] = 1;
		}
		return 0;
	}
};