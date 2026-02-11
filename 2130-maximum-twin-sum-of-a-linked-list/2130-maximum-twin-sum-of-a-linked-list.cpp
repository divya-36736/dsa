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
    ListNode* reverse(ListNode* slow){
        if(slow == NULL || slow->next == NULL) return slow;
        ListNode* temp = slow->next;
        ListNode* prev = NULL;
        while(slow){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverse(slow);
        int ans = 0;
        while(slow){
            ans = max(ans, head->val+slow->val);
            slow = slow->next;
            head = head->next;
        }
        return ans;
    }
};