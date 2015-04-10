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
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int preSize = preorder.size();
        int inSize = inorder.size();
        TreeNode *root = buildTree(preorder,0,preSize,inorder,0,inSize);

    }

private:
    TreeNode *buildTree(vector<int> &preorder,int preorderL,int preorderR,
                        vector<int> &inorder, int inorderL,int inorderR)
    {
        //base line
        int preSize = preorderR-preorderL;
        int inSize = inorderR-inorderL;
        if(preSize!=inSize)
            throw;
        if(preSize==0)
            return NULL;

        int root_val = preorder[preorderL];
        TreeNode *root = new TreeNode(root_val);

        if(preSize==1)
            return root;

        //利用根节点的数值找出左子树和右子树的范围
        int index = 0;
        for(;inorder[index+inorderL]!=root_val && index+inorderL<inorderR;++index)
        {}
        if(index>=inorderR)
            throw;

        //左子树前序遍历和中序遍历的范围
        int leftSubtreePreorderL = preorderL+1;
        int leftSubtreePreorderR = preorderL+index+1;
        int leftSubtreeInorderL = inorderL;
        int leftSubtreeInorderR = inorderL + index;


        //右子树前序遍历和中序遍历的范围
        int rightSubtreePreorderL = preorderL+index+1;
        int rightSubtreePreorderR = preorderR;
        int rightSubtreeInorderL = inorderL+index+1;
        int rightSubtreeInorderR = inorderR;


        //递归调用
        TreeNode *leftSubtree = buildTree(preorder,leftSubtreePreorderL,leftSubtreePreorderR,
                                      inorder,leftSubtreeInorderL,leftSubtreeInorderR);
        TreeNode *rightSubtree = buildTree(preorder,rightSubtreePreorderL,rightSubtreePreorderR,
                                       inorder,rightSubtreeInorderL,rightSubtreeInorderR);

        root->left = leftSubtree;
        root->right = rightSubtree;

        return root;
    }
};
int main(){
	int p[]={-1};
	int i[]={-1};
	vector<int> pre(p,p+(sizeof(p)/sizeof(int)));
	vector<int> in(i,i+(sizeof(i)/sizeof(int)));
	//TreeNode *roott=new TreeNode(2);
	//TreeNode *root=new TreeNode(87);
//	TreeNode *ll = new TreeNode(-57);
//	TreeNode *llr = new TreeNode(58);
//	TreeNode *llrl = new TreeNode(31);
	//TreeNode *rr = new TreeNode(5);
//	TreeNode *rrl = new TreeNode(4);
//	TreeNode *rrr = new TreeNode(6);
//	root->left=ll;
	//root->right=rr;
//	ll->right=llr;
//	llr->left=llrl;
//	rr->right=rrr;
//	rr->left=rrl;
	Solution s;
	TreeNode *result=s.buildTree(pre,in);
	cout<<result->val<<endl;
	
}
