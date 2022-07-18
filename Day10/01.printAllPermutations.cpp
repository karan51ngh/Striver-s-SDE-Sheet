class Solution
{
public:
	//     void f(vector<int> arr,vector<vector<int>> &sol)
	//     {
	//         if(arr.size() == 1)
	//         {
	//             psf.push_back(arr[0]);
	//             sol.push_back(psf);
	//             return;
	//         }
	//         for(int i=0; i < arr.size())
	//         {
	//             vector<int> t = psf;
	//             t.push_back(arr[i]);

	//         }

	//     }
	void swapp(vector<int> &arr, int &i, int &j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	void f(vector<int> arr, vector<vector<int>> &sol, int s)
	{
		if (s == arr.size() - 1)
		{
			sol.push_back(arr);
			return;
		}

		for (int i = s; i < arr.size(); i++)
		{
			swapp(arr, s, i);
			f(arr, sol, s + 1);
			swapp(arr, s, i);
		}
	}

	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<vector<int>> sol;
		vector<int> psf;
		f(nums, sol, 0);
		return sol;
	}
};