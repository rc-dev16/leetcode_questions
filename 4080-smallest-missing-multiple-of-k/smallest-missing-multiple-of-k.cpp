class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int currentMultiple = k;
        
        while (numSet.count(currentMultiple)) {
            currentMultiple += k;
        }

        return currentMultiple;
    }
};

