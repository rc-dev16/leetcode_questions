class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }
        
        int first_crit = -1;
        int prev_crit = -1;
        int min_dist = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;
        
        while (curr->next) {
            ListNode* next = curr->next;
            
            if ((curr->val > prev->val && curr->val > next->val) || 
                (curr->val < prev->val && curr->val < next->val)) {
                
                if (first_crit == -1) {
                    first_crit = idx;
                } else {
                    min_dist = min(min_dist, idx - prev_crit);
                }
                prev_crit = idx;
            }
            
            prev = curr;
            curr = next;
            idx++;
        }
        
        if (min_dist == INT_MAX) {
            return {-1, -1};
        }
        
        return {min_dist, prev_crit - first_crit};
    }
};