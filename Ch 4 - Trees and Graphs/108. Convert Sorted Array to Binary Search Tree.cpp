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
typedef struct TreeNode node;
class Solution {
public:
	node* func(vector<int>& nums, int l, int r) {
		if (l > r)
			return NULL;

		int mid = (l + r) / 2;

		node* root = new node(nums[mid]);
		root->left = func(nums, l, mid - 1);
		root->right = func(nums, mid + 1, r);
		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int n = nums.size();
		return func(nums, 0, n - 1);
	}
};
