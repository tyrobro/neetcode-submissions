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
        if(!head){
            return NULL;
        }

        int length = 0;
        ListNode* temp = head;

        while(temp){
            temp = temp->next;
            length++;
        }

        int m = length - n;

        if(m==0){
            return head->next;
        }

        temp = head;
        while(m > 1){
            m--;
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};
