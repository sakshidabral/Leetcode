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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* p=head;
        while(p!=nullptr){
            v.push_back(p->val);
            p=p->next;
        }
        sort(v.begin(),v.end());
        p=head;
        int i=0;
        while(p!=nullptr){
            p->val=v[i++];
            p=p->next;
        }
        return head;
    }
};