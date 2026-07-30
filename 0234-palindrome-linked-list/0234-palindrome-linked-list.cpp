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
    ListNode*reverseList(ListNode*head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode*temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode*newHead = reverseList(slow);

        ListNode* st = head;
        ListNode* newHead1 = newHead;

        while(newHead1 != NULL){
            if(st->val != newHead1->val){
                return false;
            }
            st = st->next;
            newHead1 = newHead1->next;
        }
        return true;
    }
};