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
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* getkthNode(ListNode* head, int k){
        k -= 1;
        ListNode* temp  = head;
        while(temp != NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast =NULL;
        while(temp != NULL){
            ListNode* kthNode = getkthNode(temp , k);
            if(kthNode == NULL){
                if(prevLast) prevLast->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if(temp == head){
                head = kthNode;
            }else{
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        
        }
        return head;
        // ListNode* temp = head;
        // int cnt = 0;
        // while(cnt < k){
        //     if(temp == NULL){
        //         return head;
        //     }
        //     temp = temp ->next;
        //     cnt++;
        // }
        // ListNode* prevNode = reverseKGroup(temp, k);
        // temp = head;
        // cnt = 0;
        // while(cnt<k){
        //     ListNode* next = temp->next;
        //     temp->next = prevNode;
        //     prevNode = temp;
        //     temp = next;
        //     cnt++;
        // }
        // return prevNode;
    }
};