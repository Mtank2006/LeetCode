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
    ListNode* swapNodes(ListNode* head) {
        ListNode* temp = head->next;
        head->next = temp->next;
        temp->next = head;
        return temp;
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = swapNodes(head);
        ListNode* Prev = head;
        head = head->next;
        while (head != nullptr && head->next != nullptr) {
            Prev->next = swapNodes(head);
            Prev = Prev->next->next;
            head = Prev->next;
        }
        return newHead;
    }
};



// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head) {
//         ListNode* temp = head->next;
//         head->next = head->next->next;
//         temp->next = head;
//         return temp;
//     }
//     ListNode* swapPairs(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) {
//             return head;
//         }
//         if (head->next->next == nullptr) {
//             return swapNodes(head);
//         }
//         ListNode* start = head->next;
//         ListNode* Prev = swapNodes(head)->next;
//         while (head != nullptr) {
//             if (head->next == nullptr) {
//                 break;
//             }
//             Prev->next = swapNodes(head);
//             Prev = Prev->next->next;
//             head = head->next;
//         }
//         return start;
//     }
// };



// class Solution {
// public:
//     void swapNodes(ListNode* head) {
//         ListNode* temp = head->next;
//         head->next = head->next->next;
//         temp->next = head;
//     }
//     ListNode* swapPairs(ListNode* head) {
//         if (head == nullptr || head->next == nullptr) {
//             return head;
//         }
//         ListNode* start = head->next;
//         while (head != nullptr) {
//             if (head->next == nullptr) {
//                 break;
//             }
//             swapNodes(head);
//             head = head->next;
//         }
//         return start;
//     }
// };
