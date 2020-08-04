/*
Question: https://leetcode.com/problems/maximum-depth-of-binary-tree/

Solution:


*/
class Solution 
{

    public:
        int maxDepth(TreeNode* root) 
        {
            if(root==NULL)
                return 0;
            //Calling Recursion
            int h=(maxDepth(root->left)+1);
            int z=maxDepth(root->right)+1;
            return max(h,z);
            
        }
};