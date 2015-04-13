class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int len=num.size();
        if(len==0)
            return root;
        return childBST(num,0,len-1);
    }
    TreeNode *childBST(vector<int> &num,int l,int r){
        if(l>r)
            return NULL;
        int mid=(l+r)/2;
        TreeNode *root=new TreeNode(num[mid]);
        root->left=childBST(num,l,mid-1);
        root->right=childBST(num,mid+1,r);
        return root;
    }
private:
    TreeNode *root;
};
