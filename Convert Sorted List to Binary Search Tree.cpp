#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
    	
    	if(!head)
            return root;
        if(head->next==NULL)
            return new TreeNode(head->val);
        ListNode *post=head;
        ListNode *pre=head;
        ListNode *pp,*postpp;
        while(post!=NULL){
        	postpp=post;
            post=post->next;
            if(post!=NULL){
                postpp=post;
				post=post->next;
				pp=pre;
            	pre=pre->next;
            }
        }
        root= new TreeNode(pre->val);
        root->left=childBST(head,pp);
        root->right=childBST(pre->next,postpp);
        return root;
    }
    TreeNode *childBST(ListNode *start,ListNode *finish){
    	TreeNode *curroot;
        ListNode *post=start;
        ListNode *pre=start;
        ListNode *pp;
        if(start==NULL||finish==NULL||start->val>finish->val)
        	return NULL;
        if(start==finish)
        	return new TreeNode(start->val);
        while(post!=finish){
            post=post->next;
            if(post!=finish){
                post=post->next;
            }
            pp=pre;
            pre=pre->next;
        }
        curroot= new TreeNode(pre->val);
        curroot->left=childBST(start,pp);
        curroot->right=childBST(pre->next,finish);
        return curroot;
    }
private:
    TreeNode *root;
};
int main(){
	ListNode *head=new ListNode(3);
	ListNode *s1=new ListNode(5);
	ListNode *s5=new ListNode(8);
//	ListNode *s2=new ListNode(2);
//	ListNode *s3=new ListNode(5);
	//ListNode *s4=new ListNode(2);
	
	head->next=s1;
	s1->next=s5;
//	s5->next=s2;
//	s2->next=s3;
	//s3->next=s4;
	Solution s;
	TreeNode *result=s.sortedListToBST(head);
	cout<<result->val<<endl;
	cout<<result->right->val<<endl;
//	while(result!=NULL){
//		cout<<result->val<<endl;
//		result=result->next;
//	}
}
