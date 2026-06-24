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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list1_curr = list1;
        ListNode* list2_curr = list2;
        ListNode* merged_list_head = nullptr;
        ListNode* merged_list_curr = nullptr;
        ListNode* tmp = nullptr;

        while (list1_curr != nullptr || list2_curr != nullptr) {
            if (list1_curr != nullptr && list2_curr != nullptr) {
                if (list1_curr->val <= list2_curr->val) {
                    tmp = list1_curr;
                    list1_curr = list1_curr->next;
                }
                else {
                    tmp = list2_curr;
                    list2_curr = list2_curr->next;
                }
                if (merged_list_curr == nullptr) {
                    merged_list_curr = tmp;
                    merged_list_head = merged_list_curr;
                }
                else {
                    merged_list_curr->next = tmp;
                    merged_list_curr = merged_list_curr->next;
                }
            }
            else if (list1_curr == nullptr && list2_curr != nullptr) {
                if (merged_list_curr == nullptr) {
                    merged_list_curr = list2_curr;
                    merged_list_head = merged_list_curr;
                }
                else {
                    merged_list_curr->next = list2_curr;
                    merged_list_curr = merged_list_curr->next;
                }
                list2_curr = list2_curr->next;
            }
            else {
                if (merged_list_curr == nullptr) {
                    merged_list_curr = list1_curr;
                    merged_list_head = merged_list_curr;
                }
                else {
                    merged_list_curr->next = list1_curr;
                    merged_list_curr = merged_list_curr->next;
                }
                list1_curr = list1_curr->next;
            }
        }
        return merged_list_head;
    }
};
