/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopy(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }
    }

    void connectRandom(Node* head) {
        Node* temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
    }

    Node* extractCopy(Node* head) {
        Node* dummy = new Node(0);
        Node* curr = dummy;
        Node* temp = head;

        while (temp) {
            curr->next = temp->next;
            curr = curr->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        insertCopy(head);
        connectRandom(head);
        return extractCopy(head);
    }
};
