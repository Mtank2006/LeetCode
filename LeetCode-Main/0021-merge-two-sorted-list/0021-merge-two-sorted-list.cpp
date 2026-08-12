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
        ListNode* PrevL = nullptr;
        ListNode* temp = nullptr;
        ListNode* L = list1;
        ListNode* R = list2;
        ListNode* head = L;
        if (L == nullptr) return R;
        if (R == nullptr) return L;
        while (L != nullptr && R != nullptr) {
            if (L->val <= R->val) {
                PrevL = L;
                L = L->next;
            }
            else {
                if (PrevL == nullptr) {
                    PrevL = R;
                    head = R;
                }
                else {
                    PrevL->next = R;
                }
                temp = R->next;
                R->next = L;
                PrevL = R;
                R = temp;
            }
        }
        if (L != nullptr) {
            PrevL->next = L;
        }
        else {
            PrevL->next = R;
        }
        return head;
    }
};
