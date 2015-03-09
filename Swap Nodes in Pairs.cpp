#include <iostream>
#include <string>
#include <vector> 
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL)  return result;
        fnode=snode=head;
        while(fnode!=NULL){
            if(fnode==head){
                if(fnode->next==NULL)
                    return head;
                else{
                    snode = fnode->next;
                    cnode = snode;
                    result= cnode;
                    
                    snode=snode->next; 
                    
                    cnode->next=fnode;
                    cnode=cnode->next;
                    
                    fnode=snode;
                    if(fnode==NULL){
                    	cnode->next=NULL;
                    	break;
                    }
                       
                    else
                        snode=fnode->next;
                    
                    cnode->next=NULL;
                }
            }
            else if(fnode!=NULL){
            	if(snode==NULL){
            		cnode->next = fnode;
            		cnode=cnode->next;
            		cnode->next=NULL;
            		fnode=NULL;
            	}
            	else{
            		cnode->next = snode;
	                cnode=cnode->next;
	                
	                snode=snode->next;
	                
	                cnode->next=fnode;
	                cnode=cnode->next;
	                
	                fnode=snode;
	                 if(fnode==NULL){
	                    	cnode->next=NULL;
	                    	break;
	                    }
	                    else
	                        snode=fnode->next;
	                
	                cnode->next=NULL;	
            	}
                
                
            }
        }
        return result;
    }
private:
    ListNode *result,*fnode,*snode,*cnode;
};

int main(){
	ListNode *first=new ListNode(1);
	ListNode *second=new ListNode(2);
	ListNode *third=new ListNode(3);
	first->next=second; 
	second->next=third;
	Solution s;
	ListNode *result = s.swapPairs(first);
	while(result){
		cout<<result->val<<endl;
		result=result->next; 
	}
}
