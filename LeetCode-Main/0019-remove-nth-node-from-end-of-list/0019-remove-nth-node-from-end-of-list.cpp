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

// one-pass

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = head;
        ListNode* reqNode = head;
        while (n > 0) {
            head = head->next;
            n--;
        }
        if (head == nullptr) {
            return start->next;
        }
        while (head->next != nullptr) {
            head = head->next;
            reqNode = reqNode->next;
        }
        reqNode->next = reqNode->next->next;
        return start;
    }
};

// first pass - learn length, second pass - find target

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* start = head;
//         size_t size = 1;
//         while (head->next != nullptr) {
//             size++;
//             head = head->next;
//         }
//         if (size == 1) {
//             return nullptr;
//         }
//         n = size - n;
//         if (n == 0) {
//             return start->next;
//         }
//         head = start;
//         while(n > 1) {
//             head = head->next;
//             n--;
//         }
//         head->next = head->next->next;
//         return start;
//     }
// };
