class Solution
{
public:
	void sortColors(vector<int> &nums)
	{
		vector<int> ref(3, 0);
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
				ref[0] += 1;
			if (nums[i] == 1)
				ref[1] += 1;
			if (nums[i] == 2)
				ref[2] += 1;
		}
		for (int i = 0; i < ref[0]; i++)
			nums[i] = 0;
		for (int i = ref[0]; i < ref[0] + ref[1]; i++)
			nums[i] = 1;
		for (int i = ref[0] + ref[1]; i < ref[0] + ref[1] + ref[2]; i++)
			nums[i] = 2;
	}
};