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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        
        while(head){
            ListNode*curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        ListNode*temp = head;
        int maxval = head->val;
        while(temp && temp->next){
            if(temp->next->val < maxval){
                temp->next = temp->next->next;
            }else{
                temp = temp->next;
                maxval = temp->val;
            }
        }
        return reverse(head);
    }
};