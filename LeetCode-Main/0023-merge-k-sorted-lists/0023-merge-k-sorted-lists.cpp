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
    void split(vector<ListNode*>& lists, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start) / 2;
        split(lists, start, mid);
        split(lists, mid + 1, end);
        lists[start] = merge(lists[start], lists[mid+1]);
        return;
    }
    ListNode* merge(ListNode* L, ListNode* R) {
        ListNode* PrevL = nullptr;
        ListNode* temp = nullptr;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        int size = lists.size();
        split(lists, 0, size-1);
        return lists[0];
    }
};

    // void merge(ListNode* L, ListNode* R) {
    //     while (L != nullptr && R != nullptr) {
    //         if (L->val <= R->val) {
    //             L = L->next;
    //         }
    //         else {
    //             ListNode temp(R->val, L);
    //             R = R->next;
    //         }
    //     }
    //     if (R != nullptr) {
    //         L->next = R;
    //     }
    // }

    //     void merge(ListNode* L, ListNode* R) {
    //     ListNode* PrevL = nullptr;
    //     while (L != nullptr && R != nullptr) {
    //         if (L->val <= R->val) {
    //             PrevL = L;
    //             L = L->next;
    //         }
    //         else {
    //             ListNode temp(R->val, R);
    //             R = R->next;
    //             if (PrevL == nullptr) {
    //                 PrevL = temp;
    //             }
    //             else {
    //                 PrevL->next = temp;
    //             }
    //         }
    //     }
    // }
