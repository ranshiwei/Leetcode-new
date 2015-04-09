/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        if(!root)
            return result;
            
        vector<TreeNode *> tmp;
        tmp.push_back(root);
        while(tmp.size()>0){
            vector<int> vi;
            vector<TreeNode *> vt;
            for(int i=0;i<tmp.size();i++){
                TreeNode *root = tmp[i];
                vi.push_back(root->val);
                if(root->left)
                    vt.push_back(root->left);
                if(root->right)
                    vt.push_back(root->right);
            }
            result.push_back(vi);
            tmp.clear();
            tmp=vt;
        }
        for(int i=1;i<result.size();i=i+2){
            int len=result[i].size();
            for(int j=0;j<len/2;j++){
                swap(result[i][j],result[i][len-j-1]);
            }
        }
        return result;
    }
private:
    vector<vector<int> > result;
};
