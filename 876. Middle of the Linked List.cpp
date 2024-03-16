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
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* mid = head;
        while(mid != NULL) {
            cnt++;
            mid = mid->next;
        }
        mid = head;
        for(int i = 0; i < cnt/2; i++) {
            mid = mid->next;
        }
        return mid;
    }
};