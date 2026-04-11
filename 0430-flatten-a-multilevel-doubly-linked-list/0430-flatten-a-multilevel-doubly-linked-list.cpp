/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr) {
            if (curr->child) {
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                Node* temp = curr->next;

                while (temp->next) {
                    temp = temp->next;
                }

                if (next) {
                    temp->next = next;
                    next->prev = temp;
                }
            }
            curr = curr->next;
        }

        return head;
    }
};