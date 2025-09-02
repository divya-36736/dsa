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
    // Helper function: find the k-th node in the linked list
    ListNode* findNthNode(ListNode* temp, int k) {
        int cnt = 1;
        while (temp != NULL) {
            if (cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp; // if k > length, returns NULL
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;

        // Step 1: find length and tail
        ListNode* tail = head;
        int len = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;   // ✅ increment instead of resetting
        }

        // Step 2: handle cases where k is multiple of len
        k = k % len;
        if (k == 0) return head;

        //connect tail to head to form circular list
        tail->next = head;

        //find new last node (len - k)-th node
        ListNode* newLastNode = findNthNode(head, len - k);

        //new head is after newLastNode
        head = newLastNode->next;

        //break the circle
        newLastNode->next = NULL;

        return head;
    }
};
