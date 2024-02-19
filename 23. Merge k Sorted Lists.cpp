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
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        ListNode* head = NULL, *cur = NULL;
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i] != NULL)
                pq.push({lists[i]->val, lists[i]});
        }
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if(head == NULL) {
                cur = top.second;
                head = cur;
            }
            else {
                cur->next = top.second;
                cur = cur->next;
            }
            if(top.second->next != NULL) {
                pq.push({top.second->next->val, top.second->next});
            }
        }
        return head;
    }
};