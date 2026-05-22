class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        vector<ListNode*> nodes;
        ListNode* temp = head;
        while (temp) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        int l = 0;
        int r = nodes.size() - 1;

        while (l < r) {
            nodes[l]->next = nodes[r];
            l++;
            
            if (l == r) break;
            
            nodes[r]->next = nodes[l];
            r--;
        }

        nodes[l]->next = nullptr;
    }
};