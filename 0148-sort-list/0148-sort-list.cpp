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

    ListNode* merge(ListNode* list1, ListNode*list2){
        //create a dummy node for merge thema as a head
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(list1 != NULL && list2 != NULL){
            //ydi list one ki value choti hai toh usko dummnode s eadd kr femge other wise list2
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        //ydi abhi bhi list1 ke node rah rhe hai toh unko add krneg in temp me
        if(list1!=NULL){
            temp->next = list1;
        }else{
            temp->next = list2;
        }
        return dummyNode->next;
    }

    //finfd middle of the ll
    ListNode* findmiddle(ListNode*head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        // //brute force approach
        // //1) 1st convert it in arr
        // //2) sort them 
        // //3) agin in ll 
        // vector<int>arr;
        // ListNode*temp =head;

        // while(temp != NULL){
        //     arr.push_back(temp->val);
        //     temp = temp->next;
        // }
        // sort(arr.begin(), arr.end());

        // temp = head;

        // for(int i = 0; i<arr.size(); i++){
        //     temp ->val = arr[i];
        //     temp = temp->next;

        // }
        // return head;

        //optimal 
        //ll ko 2 half kro and phir usko sort kro 

        //if ek hi lement ho ya ek bhi nhi ho 
        if(head == NULL || head->next == NULL){
            return head;
        }

        //find middle node for divide in two halves
        ListNode* middle = findmiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode*left = head;

        // recursively dort left an dright phir ab ek ke part ko sort krenge
        left = sortList(left);
        right = sortList(right);

        //ab inko merge krenge
        return merge(left, right);
    }
};