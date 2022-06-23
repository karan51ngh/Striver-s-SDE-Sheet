class Solution
{
public:
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
	{
		vector<int> sol(m + n);

		int j = 0;
		int k = 0;
		for (int i = 0; i < m + n; i++)
		{
			if (j == m)
			{
				sol[i] = nums2[k];
				++k;
				continue;
			}
			if (k == n)
			{
				sol[i] = nums1[j];
				++j;
				continue;
			}
			else
			{
				if (nums1[j] <= nums2[k])
				{
					sol[i] = nums1[j];
					j++;
				}
				else
				{
					sol[i] = nums2[k];
					k++;
				}
			}
		}
		nums1 = sol;
	}
};