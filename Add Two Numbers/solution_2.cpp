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
        int carry = 0;
        int sum = 0;
        ListNode* sumList = nullptr;
        ListNode* temp = nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            l1 = l1->next;
            l2 = l2->next;
            if (sumList == nullptr) {
                sumList = new ListNode(sum);
                temp = sumList;
            } else {
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = new ListNode(sum);
            }
        }
        while (l1!= nullptr) {
            sum = l1->val + carry;
            l1 = l1->next;
            carry = sum / 10;
            sum = sum % 10;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = new ListNode(sum);
        }
        while (l2!= nullptr) {
            sum = l2->val + carry;
            l2 = l2->next;
            carry = sum / 10;
            sum = sum % 10;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = new ListNode(sum);
        }
        if(carry == 1){
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = new ListNode(carry);
        }
        return sumList;
    }
};