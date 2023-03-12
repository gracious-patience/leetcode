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
        ListNode *result =  new ListNode;
        int digit = 0;
        auto p1 = l1;
        auto p2 = l2;
        auto currentNode = result;
        while (p1 != NULL || p2 != NULL) {
            if (p1 != NULL && p2 != NULL) {
                currentNode->val = (p1->val + p2->val + digit)%10;
                digit = (p1->val + p2->val  + digit)/10;
                p1 = p1->next;
                p2 = p2->next;
            } else {
                if (p1 != NULL) {
                    currentNode->val = (p1->val + digit)%10;
                    digit = (p1->val + digit)/10;
                    p1 = p1->next;
                } else {
                    currentNode->val = (p2->val + digit)%10;
                    digit = (p2->val + digit)/10;
                    p2 = p2->next;
                }
            }
            if (p1 != NULL || p2 != NULL) {
                ListNode *newNode = new ListNode;
                currentNode->next = newNode;
                currentNode = currentNode->next;
            } else {
                if (digit != 0) {
                    ListNode *newNode = new ListNode;
                    currentNode->next = newNode;
                    currentNode = currentNode->next;
                    currentNode->val = digit;
                }
            }
        }
        return result;
    }
};
