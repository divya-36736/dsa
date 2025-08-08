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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //brute force
        if(head == NULL && head->next == NULL) return NULL;
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        //if cnt == n matalb n head ko show  kr rha hai head ko delet rna hao
        if(cnt == n){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }

        //ydi esa nhi hai toh postion of node to delete is (cnt - n+1) but hame ek variable set krna padega joh us node se pahale ruk jae
        int res = cnt - n;
        temp = head;
        while(temp != NULL){
            res--;
            if(res == 0){
                break;
            }
            temp = temp->next;
        }

        ListNode* delnode = temp->next;
        temp->next = temp->next->next;
        delete delnode;
        return head;

        //optimal;
        // ListNode* fastp = head;
        // ListNode* slowp = head;

        // // Move the fastp pointer N nodes ahead
        // for (int i = 0; i < n; i++)
        //     fastp = fastp->next;

        // // If fastp becomes NULL,
        // // the Nth node from the end is the head
        // if (fastp == NULL)
        //     return head->next;

        // // Move both pointers until fastp reaches the end
        // while (fastp->next != NULL) {
        //     fastp = fastp->next;
        //     slowp = slowp->next;
        // }

        // // Delete the Nth node from the end
        // ListNode* delNode = slowp->next;
        // slowp->next = slowp->next->next;
        // delete delNode;
        // return head;
    }
};