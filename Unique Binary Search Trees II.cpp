//Reference code from discuss

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return genTree(n,0);
    }
    vector<TreeNode *> genTree(int n,int offset){
        vector<TreeNode *> ans;
        if(n==0){
            ans.push_back(nullptr);
            return ans;
        }
        int i,j,k;
        for(i=1;i<=n;i++){
            vector<TreeNode *> left=genTree(i-1,offset);
            vector<TreeNode *> right=genTree(n-i,i+offset);
            for(j=0;j<left.size();j++)
                for(k=0;k<right.size();k++){
                    TreeNode *root = new TreeNode(i+offset);
                    root->left=left[j];
                    root->right=right[k];
                    ans.push_back(root);
                }
        }
        return ans;
    }
private:
    vector<TreeNode *> result;
};
