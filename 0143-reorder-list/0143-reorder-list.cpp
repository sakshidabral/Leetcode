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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        int count = 0;
        ListNode *temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }

        stack<ListNode*> st;
        int i = 0;
        temp = head;
        while(i < (count+1)/2){ // go till mid
            i++;
            temp = temp->next;
        }

        while(temp){
            st.push(temp); // push after mid values in stack
            temp = temp->next;
        }
        
        temp = head;
        ListNode *curr = head;
        int loop = (count+1)/2 - 1;
        for(int k=0; k<loop; k++){
            curr = curr->next;
        }
        curr->next = nullptr;

        ListNode *p = head;
        while(!st.empty()){
            ListNode *temp2 = st.top();
            st.pop();

            ListNode *next = p->next;
            p->next = temp2;
            temp2->next = next;
            p = next;
        }

    }
};