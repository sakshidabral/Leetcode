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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p=list1, *q=list2;
        ListNode* del;
        for(int i=1;i<a;i++) p=p->next;
        del=p->next;
        p->next=q;
        ListNode* d=del;
        for(int i=a;i<b;i++) d=d->next;
        while(q->next!=nullptr) q=q->next;
        q->next=d->next;
        d->next=nullptr;
        delete(del);
        return list1;
    }
};