class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> ps;
        int count =0;
        int currSum = 0;

        ps[0] = 1;

        for(int i =0; i < n; i++){
            currSum += nums[i];

            int reqPrefix = currSum - k;
            if(ps.find(reqPrefix) != ps.end()){
                count +=  ps[reqPrefix];
            }

            ps[currSum]++;
        }
        return count;
    }
};