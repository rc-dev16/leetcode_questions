class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> missing;
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        unordered_set<int> present(nums.begin(), nums.end());
        
        for (int i = min_val + 1; i < max_val; ++i) {
            if (!present.count(i)) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};