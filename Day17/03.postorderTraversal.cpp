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
	void f(TreeNode *root, vector<int> &sol)
	{
		if (root == nullptr)
			return;
		f(root->left, sol);
		f(root->right, sol);
		sol.push_back(root->val);
	}
	vector<int> postorderTraversal(TreeNode *root)
	{
		vector<int> sol;
		f(root, sol);
		return sol;
	}
};