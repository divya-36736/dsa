/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDiff(ListNode* headA, ListNode*headB){
        if(!headA || !headB) return 0;
        int len1 = 0;
        int len2 = 0;
        while(headA){
            ++len1;
            headA = headA->next;
        }
        while(headB){
            ++len2;
            headB = headB->next;
        }
        return len1-len2;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        int diff = getDiff(headA, headB);
        if(diff<0){
            while(diff++ != 0){
                headB = headB->next;
            }
        }
        else{
            while(diff-- != 0){
                headA = headA->next;
            }
        }
        while(headA){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};