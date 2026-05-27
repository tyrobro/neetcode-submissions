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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2){
            if(l1->val > l2->val){
                tail->next = l2;
                l2 = l2->next;
            }else {
                tail->next = l1;
                l1 = l1->next;
            }
            tail = tail->next;
        }
        tail->next = l1? l1 : l2;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        int n = lists.size();
        for(int i = 1; i < n; i++){
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }

        return lists[0];
    }
};
