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
    ListNode* deleteMiddle(ListNode* head) {
        int cnt = 0;
        ListNode* ans = head, *tmp = NULL;
        while(head != NULL) {
            head = head->next;
            cnt++;
        }
        head = ans;
        for(int i = 0; i < cnt/2-1; i++) 
            head = head->next;
        tmp = head->next;
        if(tmp != NULL) {
            head->next = tmp->next;
            delete tmp;
        }
        else
            return NULL;
        return ans;
    }
};