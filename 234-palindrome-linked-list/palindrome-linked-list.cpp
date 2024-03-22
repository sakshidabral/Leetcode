/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* newHead=NULL;
        ListNode* p=head;
        while(p!=NULL){
            ListNode* temp=new ListNode();
            temp->val=p->val;
            temp->next=newHead;
            newHead=temp;
            p=p->next;
        }
        while(head!=NULL &&newHead!=NULL){
            if(head->val!=newHead->val) return false;
            head=head->next;
            newHead=newHead->next;
        }
        return true;
    }
};