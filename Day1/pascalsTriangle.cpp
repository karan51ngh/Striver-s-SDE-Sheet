class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> sol;
		vector<int> row0;
		vector<int> row1;

		row0.push_back(1);
		if (numRows == 1)
		{
			sol.push_back(row0);
			return sol;
		}
		row1.push_back(1);
		row1.push_back(1);
		if (numRows == 2)
		{
			sol.push_back(row0);
			sol.push_back(row1);
			return sol;
		}
		sol.push_back(row0);
		sol.push_back(row1);
		for (int i = 2; i < numRows; i++)
		{
			vector<int> temp;
			temp.push_back(1);
			for (auto itr = sol[sol.size() - 1].begin(); itr < sol[sol.size() - 1].end() - 1; itr++)
			{
				temp.push_back(*(itr) + *(itr + 1));
			}
			temp.push_back(1);
			sol.push_back(temp);
		}
		return sol;
	}
};