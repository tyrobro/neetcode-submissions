class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        } 

        Node* l1 = head;
        while (l1) {
            Node* l2 = new Node(l1->val);
            l2->next = l1->random;
            l1->random = l2;
            l1 = l1->next;
        }

        Node* newHead = head->random;

        l1 = head;
        while (l1) {
            Node* l2 = l1->random;
            l2->random = (l2->next != nullptr) ? l2->next->random : nullptr;
            l1 = l1->next;
        }

        l1 = head;
        while (l1) {
            Node* l2 = l1->random;
            l1->random = l2->next;
            l2->next = (l1->next != nullptr) ? l1->next->random : nullptr;
            l1 = l1->next;
        }

        return newHead;
    }
};