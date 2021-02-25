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
    
    node* prev = NULL;
    bool isValidBST(TreeNode* root) {
         // base
        if(root == NULL)
            return true;
        
        // main
        if (!isValidBST(root->left))
            return false;
        
        int curr = root->val;
        if(prev and curr <= prev->val){            
            return false;
        }
        prev = root;
        
        if (!isValidBST(root->right))
            return false;
        
        return true;
    }
};
-----------------------------------------
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
typedef long long ll;
class Solution {
public:
    bool isValidBST(TreeNode* root, ll minval = LLONG_MIN, ll maxval = LLONG_MAX) {
        if(root == NULL)
            return true;
        return minval < root->val and root->val < maxval and isValidBST(root->left, minval, root->val) and isValidBST(root->right, root->val, maxval);
    }
};
