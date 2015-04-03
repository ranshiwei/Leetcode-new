#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head==NULL)
            return head;
        bool flag=true;
        ListNode *cur = new ListNode(0);
        if(head->val<x){
        	cur=head;
        	flag=false;
        }else{
        	cur->next=head;
        	flag=true;
        }
        ListNode *h=cur;
        ListNode *p=cur->next,*pp=cur;
        while(p!=NULL){
            if(p->val>=x){
                pp=p;
                p=p->next;
            }else{
            	if(p->next==NULL){
            		pp->next=NULL;
	                p->next=cur->next;
	                cur->next = p;
	                break;
            	}else{
            		pp->next=p->next;
	                p->next=cur->next;
	                cur->next = p;
	                if(pp==cur){
	                	cur=p;
	                	pp=p;
	                }else{
	                	cur=p;
	                }
	                
	                p=pp->next;
            	}
            }
        }
        return flag?h->next:h;
    }
};
int main(){
	ListNode *head=new ListNode(2);
	ListNode *s1=new ListNode(1);
//	ListNode *s5=new ListNode(3);
//	ListNode *s2=new ListNode(2);
//	ListNode *s3=new ListNode(5);
//	ListNode *s4=new ListNode(2);
	
	head->next=s1;
//	s1->next=s5;
//	s5->next=s2;
//	s2->next=s3;
//	s3->next=s4;
	Solution s;
	ListNode *result=s.partition(head,2);
	while(result!=NULL){
		cout<<result->val<<endl;
		result=result->next;
	}
}
