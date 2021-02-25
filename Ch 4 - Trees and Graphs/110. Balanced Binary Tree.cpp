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
class Solution {
public:
    int func(TreeNode* root){
        // base
        if(root == NULL)
            return 0;
        
        // main
        int left = func(root->left);
        if(left == -1) return -1;
        
        int right = func(root->right);
        if(right == -1) return -1;
        
        if(abs(left - right) > 1)
            return -1;
        
        return 1 + max(left,right);
    }
    
    bool isBalanced(TreeNode* root) {
        if(func(root) != -1)
            return true;
        return false;
    }
};

// T(n) = 2T(n/2) + O(1) 
