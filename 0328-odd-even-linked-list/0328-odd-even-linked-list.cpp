class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* evenHead = new ListNode(-1);
        ListNode* oddHead = new ListNode(-1);

        ListNode* even = evenHead;
        ListNode* odd = oddHead;

        ListNode* curr = head;
        int cnt = 0;

        while (curr) {
            ListNode* nextNode = curr->next;   
            curr->next = nullptr;             

            if (cnt % 2 == 0) {
                even->next = curr;
                even = curr;
            } else {
                odd->next = curr;
                odd = curr;
            }

            curr = nextNode;   
            cnt++;
        }

        even->next = oddHead->next;

        return evenHead->next;
    }
};