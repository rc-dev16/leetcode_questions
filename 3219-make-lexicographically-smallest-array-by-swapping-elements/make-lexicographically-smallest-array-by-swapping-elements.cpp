
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = {nums[i], i};
        }
        
        sort(v.begin(), v.end());
        
        vector<int> res(n);
        int i = 0;
        
        while (i < n) {
            int j = i + 1;
            while (j < n && v[j].first - v[j - 1].first <= limit) {
                j++;
            }
            
            vector<int> indices;
            for (int k = i; k < j; ++k) {
                indices.push_back(v[k].second);
            }
            
            sort(indices.begin(), indices.end());
            
            for (int k = i; k < j; ++k) {
                res[indices[k - i]] = v[k].first;
            }
            
            i = j;
        }
        
        return res;
    }
};