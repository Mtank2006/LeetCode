/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    while (l1 != NULL) {
        printf("%d -> ", l1->val);
        l1 = l1->next;
    }
}