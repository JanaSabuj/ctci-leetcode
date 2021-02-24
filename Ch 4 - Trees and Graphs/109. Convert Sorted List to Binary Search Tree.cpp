/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
	ListNode* findMid(ListNode* head, ListNode* tail) {
		ListNode* p = head;
		ListNode* q = head;

		while (q != tail and q->next != tail) {
			p = p->next;
			q = q->next->next;
		}

		return p;
	}

	TreeNode* dfs(ListNode* head, ListNode* tail) {
		// base
		if (head == tail)
			return NULL;// empty LL

		// main
		ListNode* mid = findMid(head, tail);

		TreeNode* tn = new TreeNode(mid->val);
		tn->left = dfs(head, mid);// excluding mid, so mid is tail here [head, mid)
		tn->right = dfs(mid->next, tail);// [mid->next, tail)
		return tn;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		return dfs(head, NULL);// tail is excluded for this range, so tail = NULL
	}
};
