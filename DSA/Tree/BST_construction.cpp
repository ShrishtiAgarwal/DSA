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
    
    void help(TreeNode* root , int x)
    {
        if(root->val>x )
        {
            if(root->left==NULL)
                root->left=new TreeNode(x);
            else
                help(root->left,x);
            
        }
        else
        {
             if(root->right==NULL)
                root->right=new TreeNode(x);
            else
                help(root->right,x);
        }
    
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode *root = new TreeNode(preorder[0]);
        
        for(int i=1;i<preorder.size();i++)
        {
            help(root,preorder[i]);
            
        }
        return root;
        
    }
};