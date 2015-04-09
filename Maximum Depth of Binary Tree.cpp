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
    int maxDepth(TreeNode *root) {
        if(root){
            kmax=depth;
            if(root->left){
                maxD(root->left,depth+1,kmax);
            }
            if(root->right)
                maxD(root->right,depth+1,kmax);
        }
        return kmax;
    }
    void maxD(TreeNode *root,int depth,int &kmax){
            if(root){
                if(depth>kmax)
                    kmax=depth;
                if(root->left){
                    maxD(root->left,depth+1,kmax);
                }
                if(root->right)
                    maxD(root->right,depth+1,kmax);
            }
        }
private:
    int depth=1;
    int kmax=0;
};
