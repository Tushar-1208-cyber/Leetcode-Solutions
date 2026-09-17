/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){  // agar curr node null hai ya p ya q me se hai to usi node ko return kr do
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);  // left and right subtree me recursive LCA dhundo
        TreeNode* right = lowestCommonAncestor(root->right, p, q);        

        if(left != NULL && right != NULL){  // p and q dono alag subtrees me mile hai to current root hi unnka LCA hai
            return root;
        }

        if(left != NULL && right == NULL){  // agar left subtree me p,q,LCA mila to usi me parent ko return kr do 
            return left;
        }

        if(left == NULL && right != NULL){  
            return right;
        }

        return NULL;  
    }
};