class Solution {
public:
    int minDepth(TreeNode *root) {
        return mind(root);
    }
    int mind(TreeNode *root){
        if(!root)
            return 0;
        if(!root->left&&!root->right){
            return   1;
        }
        if(root->left&&root->right){
            return   min(mind(root->left),mind(root->right))+1;
        }
        if(root->left)
            return mind(root->left)+1;
        if(root->right)
            return mind(root->right)+1;
    }
};
