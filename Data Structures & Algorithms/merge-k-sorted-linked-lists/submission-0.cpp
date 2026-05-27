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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        vector<int> storage;
        for(int i = 0; i < n; i++){
            ListNode* temp = lists[i];
            while(temp){
                storage.push_back(temp->val);
                temp = temp->next;
            }
        }

        sort(storage.begin(), storage.end());

        ListNode dummy(0);
        ListNode* tail = &dummy;

        for(int val: storage){
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy.next;
    }
};
