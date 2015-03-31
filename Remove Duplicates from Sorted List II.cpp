#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode fakeHead(0);
        fakeHead.next = head;
        ListNode* pre = &fakeHead;
        ListNode* p = pre->next;
        while (p ) {
            ListNode* pn = p->next;

            if (pn && p->val == pn->val) {
                while (pn && p->val == pn->val) {
                    pn = pn->next;
                }

                p = pn;
                pre->next = p;
            }
            else {
                pre = p;
                p = p->next;
            }
        }
        return fakeHead.next;
    }
};
int main(){
	ListNode *head=new ListNode(1);
	ListNode *s1=new ListNode(1);
	//ListNode *s5=new ListNode(2);
//	ListNode *s2=new ListNode(2);
//	ListNode *s3=new ListNode(3);
//	ListNode *s4=new ListNode(4);
	head->next=s1;
	
//	s1->next=s5;
//	s5->next=s2;
//	s2->next=s3;
//	s3->next=s4;
	Solution s;
	ListNode *result=s.deleteDuplicates(head);
	while(result!=NULL){
		cout<<result->val<<endl;
		result=result->next;
	}
}
