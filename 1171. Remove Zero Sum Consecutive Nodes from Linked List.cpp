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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> prefix;
        int prefixSum = 0;
        for(ListNode* cur = dummy; cur != nullptr; cur = cur->next) {
            prefixSum += cur->val;
            prefix[prefixSum] = cur;
        }
        prefixSum = 0;
        for(ListNode* cur = dummy; cur != nullptr; cur = cur->next) {
            prefixSum += cur->val;
            cur->next = prefix[prefixSum]->next;
        }
        return dummy->next;
    }
};