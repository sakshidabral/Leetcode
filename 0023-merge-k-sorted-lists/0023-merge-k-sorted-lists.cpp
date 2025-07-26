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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, 
                       function<bool(ListNode*, ListNode*)>> pq([](ListNode* a, ListNode* b) {
                           return a->val > b->val;  // Min-heap based on node values
                       });
        
        for (auto node : lists) {
            if(node) pq.push(node);
        }

        ListNode* temp = new ListNode(0);
        ListNode* curr = temp;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            curr->next = node;
            curr = curr->next;

            if (node->next) pq.push(node->next);
        }

        return temp->next; 
    }
};