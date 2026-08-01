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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;

        unordered_set<ListNode*>st;
        while(d1){
            st.insert(d1);
            d1 = d1->next;
        }

        while(d2){
            if(st.find(d2) != st.end()){
                return d2;
            }
            d2 = d2->next;
        }
        return NULL;
    }
};