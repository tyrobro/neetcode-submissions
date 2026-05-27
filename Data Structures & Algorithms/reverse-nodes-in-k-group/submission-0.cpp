class Solution {
public:
    ListNode* reverseKNodes(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        
        for (int i = 0; i < k; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupTail = &dummy;
        ListNode* curr = head;

        while (curr) {
            ListNode* kNode = curr;
            for (int i = 1; i < k && kNode; ++i) {
                kNode = kNode->next;
            }

            if (!kNode) break;

            ListNode* nextGroupHead = kNode->next;

            ListNode* newGroupHead = reverseKNodes(curr, k);

            prevGroupTail->next = newGroupHead;
            curr->next = nextGroupHead;

            
            prevGroupTail = curr;
            curr = nextGroupHead;
        }

        return dummy.next;
    }
};