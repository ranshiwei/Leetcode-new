class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
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
        int len=result.size();
        for(int i=0;i<len;i++)
        {
            s.push(result[i]);
        }
        while(!s.empty()){
            t.push_back(s.top());
            s.pop();
        }
        return t;
    }
private:
    vector<vector<int> > result,t;
    stack<vector<int> > s;
};
