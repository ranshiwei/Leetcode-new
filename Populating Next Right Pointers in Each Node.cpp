/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL||root->left==NULL)
            return;
        root->left->next=root->right;
        if(root->next!=NULL)
            root->right->next=root->next->left;
        connect(root->left);
        connect(root->right);
    }
    void connect(TreeLinkNode *root) {
        if(root){
            q.push(root);
            int i=0;
            int mm=1;
            while(!q.empty()){
                TreeLinkNode *pre = q.front();
                q.pop();
                i++;
                if(pre->left)
                        q.push(pre->left);
                if(pre->right)
                        q.push(pre->right);
                
                if(i==mm){
                    pre->next=NULL;
                    i=0;
                    mm*=2;
                }else{
                    pre->next=q.front();        
                }    
            }
        }
    }
private:
    queue<TreeLinkNode *> q;
};
