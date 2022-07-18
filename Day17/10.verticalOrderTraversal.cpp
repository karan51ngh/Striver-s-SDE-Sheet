/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
	vector<vector<int>> verticalTraversal(TreeNode *root)
	{
		map<int, map<int, multiset<int>>> nodes;
		queue<pair<TreeNode *, pair<int, int>>> q;
		q.push({root, {0, 0}});

		while (!q.empty())
		{
			auto p = q.front();
			q.pop();

			TreeNode *r = p.first;
			int x = p.second.first;
			int y = p.second.second;

			nodes[x][y].insert(r->val);
			if (r->left)
				q.push({r->left, {x - 1, y + 1}});
			if (r->right)
				q.push({r->right, {x + 1, y + 1}});
		}
		vector<vector<int>> sol;
		for (auto v : nodes)
		{
			vector<int> col;
			for (auto b : v.second)
			{
				col.insert(col.end(), b.second.begin(), b.second.end());
			}
			sol.push_back(col);
		}
		return sol;
	}
};