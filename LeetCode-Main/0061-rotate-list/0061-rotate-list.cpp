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
    ListNode* rotate(ListNode* head) {
        ListNode* start = head;
        ListNode* prev = nullptr;
        while (head->next != nullptr) {
            if (prev == nullptr) {
                prev = head;
            }
            else {
                prev = prev->next;
            }
            head = head->next;
        }
        head->next = start;
        prev->next = nullptr;
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int size = 1;
        ListNode* start = head;
        while (start->next != nullptr) {
            size++;
            start = start->next;
        }
        k = (k % size);
        for (int  i = 0; i < k; ++i) {
            head = rotate(head);
        }
        return head;
    }
};

// not using mod operator

// class Solution {
// public:
//     ListNode* rotate(ListNode* head) {
//         ListNode* start = head;
//         ListNode* prev = nullptr;
//         while (head->next != nullptr) {
//             if (prev == nullptr) {
//                 prev = head;
//             }
//             else {
//                 prev = prev->next;
//             }
//             head = head->next;
//         }
//         head->next = start;
//         prev->next = nullptr;
//         return head;

//     }
//     ListNode* rotateRight(ListNode* head, int k) {
//         if (head == nullptr || head->next == nullptr) {
//             return head;
//         }
//         for (int  i = 0; i < k; ++i) {
//             head = rotate(head);
//         }
//         return head;
//     }
// };
