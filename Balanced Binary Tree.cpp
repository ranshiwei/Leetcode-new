class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int depth=0;
        return isBBT(root,&depth);
    }
    bool isBBT(TreeNode *root, int* depth){
        if(!root){
            *depth=0;
            return true; 
        }
            
        int left,right;
        if(isBBT(root->left,&left)&&isBBT(root->right,&right)){
            int d = left-right;
            if(d>1||d<-1)
                return false;
            *depth = 1+max(left,right);
            return true;
        }
        return false;
    }
};
