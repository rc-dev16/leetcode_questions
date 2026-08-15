class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int resXor = 0;
        bool allZero = true;
        for(int i=0; i < n; i++){
            resXor = (nums[i] ^ resXor);

            if(nums[i ] != 0){
                allZero = false;
            }
        }

        if(allZero == true) return 0;

        if(resXor == 0) return n- 1;

        return n;
    }
};