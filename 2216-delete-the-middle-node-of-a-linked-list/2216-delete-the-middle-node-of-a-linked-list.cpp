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
    ListNode* deleteMiddle(ListNode* head) {
        // // brute approach
        // if(head == NULL || head->next == NULL) return NULL;
        // ListNode* temp = head;
        // int cnt = 0;

        // while (temp != NULL) {
        //     cnt++;
        //     temp = temp->next;
        // }
        // // res define krenge for middle node
        // int res = cnt / 2;
        // temp = head;
        // while (temp != NULL) {
        //     res--;
        //     if (res == 0) {
        //         ListNode* middle = temp->next;
        //         temp->next = temp->next->next;
        //         delete middle;
        //         break;
        //     }
        //     temp = temp->next;
        // }

        // return head;

        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        // Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        fast = head->next->next;

        // Move 'fast' pointer twice as fast as 'slow'
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node by skipping it
        slow->next = slow->next->next;
        return head;
    }
};