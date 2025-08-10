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
        // Dummy node banaya, jisse result list ka head store ho sake
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy; // temp pointer list banane ke liye
        int carry = 0;          // carry ko store karega

        // Jab tak dono list me nodes bachi ho ya carry bacha ho
        while (l1 != NULL || l2 != NULL || carry) {
            int sum = 0; // current digits ka sum store karega

            // Agar l1 ka current node hai, to uska value sum me add karo
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next; // l1 ko aage badhao
            }

            // Agar l2 ka current node hai, to uska value sum me add karo
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next; // l2 ko aage badhao
            }

            sum += carry;     // pichle step ka carry add karo
            carry = sum / 10; // naya carry calculate karo

            // sum ka last digit nayi list me node banake add karo
            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next; // temp pointer ko aage badhao
        }

        // dummy ka next hi actual result ka head hoga
        return dummy->next;
    }
};
