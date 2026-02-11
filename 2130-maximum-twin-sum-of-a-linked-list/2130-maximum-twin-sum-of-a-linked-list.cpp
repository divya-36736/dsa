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
    int pairSum(ListNode* head) {
        // if(head == NULL) return 0;
        // int maxi = 0;
        // ListNode*slow = head;
        // ListNode* fast = head;
        // fast = head->next->next;
        // while(fast != NULL && fast->next!=NULL){
        //     slow = slow->next;
        //     fast = fast->next->next;
        // } 
        // int sum = slow->val + fast->val;
        // maxi = max(maxi, sum);
        // //ListNode*del1 = slow;
        // slow->next = slow->next->next;
        // //ListNode*del2 = 
        // fast->next = fast->next->next;
        // return maxi;

        //convert it in array
        vector<int>arr;
        ListNode*temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int l = 0;
        int r = arr.size()-1;
        int maxi = 0;
        while(l<r){
            int sum = arr[l]+arr[r];
            maxi = max(maxi, sum);
            l++;
            r--;
        }
        return maxi;
    }
};