class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root)
            return false;
        return hasPath(root,sum,0);
}
    bool hasPath(TreeNode *root,int sum,int cur){
        if(!root)
            return false;
        if(!root->left&&!root->right)
            return cur+root->val==sum;
        return hasPath(root->left,sum,cur+root->val)||hasPath(root->right,sum,cur+root->val);
    }
};
