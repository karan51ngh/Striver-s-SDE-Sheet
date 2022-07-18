class Solution
{
public:
	bool isValid(int i, int j, vector<string> &psf, int n)
	{
		int I = i;
		while (I >= 0)
		{
			if (psf[I][j] == 'Q')
				return false;
			I--;
		}

		I = i;
		int J = j;
		while (I >= 0 && J >= 0)
		{
			if (psf[I][J] == 'Q')
				return false;
			I--;
			J--;
		}

		I = i;
		J = j;
		while (I >= 0 && J < n)
		{
			if (psf[I][J] == 'Q')
				return false;
			I--;
			J++;
		}
		return true;
	}
	void f(int n, int ctr, vector<string> &psf, vector<vector<string>> &sol)
	{
		if (ctr == n)
		{
			sol.push_back(psf);
		}

		else
		{
			for (int i = 0; i < n; i++)
			{
				if (isValid(ctr, i, psf, n))
				{
					psf[ctr][i] = 'Q';
					f(n, ctr + 1, psf, sol);
					psf[ctr][i] = '.';
				}
			}
		}
	}

	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> sol;
		vector<string> psf;
		string temp;
		for (int i = 0; i < n; i++)
			temp.push_back('.');
		for (int i = 0; i < n; i++)
			psf.push_back(temp);
		f(n, 0, psf, sol);
		return sol;
	}
};