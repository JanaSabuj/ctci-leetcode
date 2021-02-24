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
    void flatten(TreeNode* root) {
        // base
        if(root == NULL)
            return;
        if(root->left == NULL and root->right == NULL)
            return;
        
        // main
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* temp = root->left;
        while(temp and temp->right != NULL){
            temp = temp->right;
        }
        
        if(temp != NULL){
            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};
