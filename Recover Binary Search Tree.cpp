#include <iostream>
#include <limits.h>
using namespace std; 

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void swap(TreeNode *t1,TreeNode *t2){
	long tmp=t1->val;
	t1->val=t2->val;
	t2->val=tmp;
}
class Solution {
public:
    void recoverTree(TreeNode *root) {
        if(!root)
        	return;
        recursiveT(root);
        swap(mis1,mis2);
        return;
    }
    void recursiveT(TreeNode *root){
        if(!root)
            return;
        if(root->left)
            recursiveT(root->left);
        if(pre!=NULL&&root->val<pre->val){
            if(mis1==NULL){
                mis1=pre;
                mis2=root;
            }else{
                mis2=root;
            }
        }
        pre=root;
        if(root->right)
            recursiveT(root->right);
    }
private:
    TreeNode *mis1,*mis2;
    TreeNode *pre=NULL;
};

int main(){
	//TreeNode *roott=new TreeNode(2);
	TreeNode *root=new TreeNode(2);
	TreeNode *ll = new TreeNode(3);
	//TreeNode *llr = new TreeNode(5);
//	//TreeNode *llrl = new TreeNode(31);
	TreeNode *rr = new TreeNode(1);
//	//TreeNode *rrl = new TreeNode(2);
//	TreeNode *rrr = new TreeNode(2);
	root->left=ll;
	root->right=rr;
//	ll->right=llr;
//	//llr->left=llrl;
//	rr->right=rrr;
//	//rr->left=rrl;
	Solution s;
	s.recoverTree(root);
	
}
