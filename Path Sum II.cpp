class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(!root)
            return result;
        vector<int> path;
        pathS(root,sum,result,path);
        return result;
    }
    void pathS(TreeNode *root,int sum,vector<vector<int> > &result, vector<int> path){
        if(!root)
            return;
        path.push_back(root->val);
        sum-=root->val;
        if(!root->left && !root->right && sum==0)
            result.push_back(path);
        if(root->left){
            pathS(root->left,sum,result,path);
        }
        if(root->right){
            pathS(root->right,sum,result,path);
        }
        sum+=root->val;
        path.pop_back();
    }
private:
    vector<vector<int> > result;
};
