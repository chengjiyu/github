/*
Construct Binary Tree from Preorder and Inorder Traversal Total Accepted: 1324 Total Submissions: 5287 My Submissions
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* run(vector<int>& pre, int pb, int pe, vector<int>& inorder, int ib, int ie){
        if(pb > pe  || ib > ie) return NULL;
        int lpb = 0 , lpe = 0, rpb = 0, rpe = 0;
        int lib = 0 , lie = 0, rib = 0, rie = 0;
        TreeNode* root = new TreeNode(pre[pb]);
        int i = 0;
        for(i = ib; i <= ie; i++){
            if(inorder[i] == pre[pb]) break;
        }
        root -> left = run(pre, pb + 1,pb + i - ib, inorder, ib, i - 1);
        root -> right = run(pre, pb + i - ib + 1, pe, inorder, i + 1, ie);
		/*
			用root的值来表示每个点， 然后边界条件用第一个if判断就可以了
		*/
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int size = preorder.size();
        return run(preorder, 0, size - 1, inorder, 0, size - 1);
    }
};