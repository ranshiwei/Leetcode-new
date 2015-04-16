/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 //Fking the code
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* prev = nullptr;
        TreeLinkNode* next = nullptr;
        
        while(root) {
            prev = nullptr;
            next = nullptr;
            //if(next == nullptr) next = root->left ? root->left : root->right;
            for( ; root ; root = root->next) {
                if(next == nullptr) next = root->left ? root->left : root->right;
                if(root->left) {
                    if(prev) prev->next = root->left;
                    prev = root->left;
                }
                if(root->right) {
                    if(prev) prev->next = root->right;
                    prev = root->right;
                }
            }
            root = next;
        }
    }
};
