#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int inlen=inorder.size();
        int postlen=postorder.size();
        
        return buildTree(inorder,0,inlen,postorder,0,postlen);
    }
    TreeNode *buildTree(vector<int> &inorder,int ll,int lr,vector<int> &postorder,int pl,int pr){
        int inlen=lr-ll;
        int postlen=pr-pl;
        if(inlen != postlen)
            throw;
        if(inlen==0)
            return NULL;
        TreeNode *root=new TreeNode(postorder[pr-1]);
        if(inlen==1)
            return root;
        int index=0;
        for(;inorder[index+ll]!=postorder[pr-1] && index+ll<lr;++index)
        {}
        if(ll+index>=lr)
            throw;
        int leftinorderleft=ll;
        int leftinorderright=ll+index;
        int leftpostorderleft=pl;
        int leftpostorderright=pl+index;
        
        int rightinorderleft=ll+index+1;
        int rightinorderright=lr;
        int rightpostorderleft=pl+index;
        int rightpostorderright=pr-1;
        
        root->left=buildTree(inorder,leftinorderleft,leftinorderright,postorder,leftpostorderleft,leftpostorderright);
        root->right=buildTree(inorder,rightinorderleft,rightinorderright,postorder,rightpostorderleft,rightpostorderright);
        return root;
    }
};
int main(){
	int p[]={3,2,1};
	int i[]={1,3,2};
	vector<int> pre(p,p+(sizeof(p)/sizeof(int)));
	vector<int> in(i,i+(sizeof(i)/sizeof(int)));

	Solution s;
	TreeNode *result=s.buildTree(in,pre);
	cout<<result->val<<endl;
	
}
