#include <iostream>
#include <limits.h>
using namespace std; 

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(!root)
            return true;
        return validb(root->left,LONG_MIN,root->val)&&validb(root->right,root->val,LONG_MAX);
    }
    bool validb(TreeNode *root,long kmin,long kmax){
        if(!root)
            return true;
        long value = root->val;
        if(value >= kmax)   return false;
        if(value <= kmin)   return false;
        if(validb(root->left,kmin,min(kmax,value))&&validb(root->right,max(kmin,value),kmax))
            return true;
        else
            return false;
    }
};

int main(){
	//TreeNode *roott=new TreeNode(2);
	TreeNode *root=new TreeNode(87);
	TreeNode *ll = new TreeNode(-57);
	TreeNode *llr = new TreeNode(58);
	TreeNode *llrl = new TreeNode(31);
	//TreeNode *rr = new TreeNode(5);
//	TreeNode *rrl = new TreeNode(4);
//	TreeNode *rrr = new TreeNode(6);
	root->left=ll;
	//root->right=rr;
	ll->right=llr;
	llr->left=llrl;
//	rr->right=rrr;
//	rr->left=rrl;
	Solution s;
	bool result=s.isValidBST(root);
	cout<<result<<endl;
	
}
