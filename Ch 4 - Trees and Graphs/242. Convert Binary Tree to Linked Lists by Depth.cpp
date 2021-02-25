/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        // Write your code here
        if(root == NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        
        vector<ListNode*> ans;
        while(!q.empty()){
            
            int sz = q.size();// curr size of level
            ListNode* dummy = new ListNode(0);// head
            ListNode* curr = dummy;// curr iterator
          
            while(sz--){
                auto temp = q.front();
                q.pop();
                
                curr->next = new ListNode(temp->val);
                curr = curr->next;
                
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
            
            // 1 level done
            ans.push_back(dummy->next);
        }
        
        return ans;
    }
};
