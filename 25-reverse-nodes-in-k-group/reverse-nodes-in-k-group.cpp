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
    ListNode* reverseKGroup(ListNode* head, int k) {

        

        if(head == nullptr || head->next == nullptr) return head;

        ListNode* curr = head;

        int count = 0;

        while(curr != nullptr && count < k){
            count++;
            curr = curr->next;
        }

        if(count < k) return head;


        curr = head;
        ListNode * prev = nullptr, *next = nullptr;

        for(int i =0; i<k; i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = reverseKGroup(curr, k);

        return prev;     
    }
};