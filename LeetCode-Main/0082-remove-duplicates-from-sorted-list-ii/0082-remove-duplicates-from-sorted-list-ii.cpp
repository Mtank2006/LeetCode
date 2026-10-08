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
    ListNode* skipDup(ListNode* head) {
        while ((head != nullptr) && (head->next) && (head->val == head->next->val)) {
            while ((head != nullptr) && (head->next) && (head->val == head->next->val)) {
                head = head->next;
            }
            head = head->next;
        }
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* start = skipDup(head);
        if (start == nullptr) {
            return start;
        }
        head = start;
        while ((head != nullptr) && (head->next != nullptr)) {
            head->next = skipDup(head->next);
            head = head->next;
        }
        return start;
    }
};

// class Solution {
// public:
//     ListNode* skipDup(ListNode* head) {
//         while ((head != nullptr) && (head->next) && (head->val == head->next->val)) {
//             while ((head != nullptr) && (head->next) && (head->val == head->next->val)) {
//                 head = head->next;
//             }
//             head = head->next;
//         }
//         return head;
//     }
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode* start = skipDup(head);
//         if (start == nullptr) {
//             return start;
//         }
//         head = start;
//         while ((head != nullptr) && (head->next != nullptr)) {
//             head->next = skipDup(head->next);
//             head = head->next;
//         }
//         return start;
//     }
// };

// Works but still a meh!

// class Solution {
// public:
//     ListNode* skipDup(ListNode* head) {
//         // ListNode* start = head;
//         // removeFirst = false;
//         // if (head->val == head->next->val) {
//         //     removeFirst = true;
//         // }
//         // // see by removing
//         // else {
//         //     head = head->next;
//         // }
//         while ((head != nullptr) && (head->next) && (head->val == head->next->val)) {
//             while ((head != nullptr) && (head->next) && (head->val == head->next->val)) {
//                 head = head->next;
//             }
//             head = head->next;
//         }
//         return head;
//     }
//     ListNode* deleteDuplicates(ListNode* head) {
//         // ListNode* prev = nullptr;
//         ListNode* start = skipDup(head);
//         if (start == nullptr) {
//             return start;
//         }
//         head = start;
//         while ((head != nullptr) && (head->next != nullptr)) {
//             head->next = skipDup(head->next);
//             head = head->next;
//         }
//         return start;
//     }
// };

// Meh Version

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* start = head;
//         // while (head->val == head->next->val) {
//         //     head
//         // }
//         while (head->next != nullptr) {
//             if (head->val == head->next->val) {
//                 while ((head->next) && (head->val == head->next>val)) {
//                     head = head->next;
//                 }
//                 head = head->next;
//                 if (prev != nullptr) {
//                     prev->next = head;
//                 }
//                 else {

//                 }
//             }
//             else {
//                 prev = head;
//                 head = head->next;
//             }
//         }
//     }
// };
