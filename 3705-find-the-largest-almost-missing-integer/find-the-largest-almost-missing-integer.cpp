class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> counts;
        
        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> unique_in_subarray;
            for (int j = 0; j < k; ++j) {
                unique_in_subarray.insert(nums[i + j]);
            }
            
            for (int x : unique_in_subarray) {
                counts[x]++;
            }
        }
        
        int largest_almost_missing = -1;
        for (const auto& [x, count] : counts) {
            if (count == 1 && x > largest_almost_missing) {
                largest_almost_missing = x;
            }
        }
        
        return largest_almost_missing;
    }
};