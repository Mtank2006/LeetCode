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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* temp = nullptr;
        int carry = 0;
        int sum = 0;
        while(l1||l2||carry) {
            sum = carry;
            if (l1) {sum += l1->val; l1 = l1->next;}
            if (l2) {sum += l2->val; l2 = l2->next;}
            if (sum>9) {
                sum -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            if (!result) {
                result = new ListNode(sum);
                temp = result;
            }
            else {
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
        }
        return result;
    }
};
