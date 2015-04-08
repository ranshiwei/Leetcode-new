class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root){
            return isChildSymmetric(root->left,root->right);
        }else
            return true;
    }
    bool isChildSymmetric(TreeNode* l,TreeNode* r){
        if(l==NULL&&r==NULL)
            return true;
        if(l==NULL||r==NULL||l->val!=r->val)
            return false;
        return isChildSymmetric(l->left,r->right)&&isChildSymmetric(l->right,r->left);
    }
};
