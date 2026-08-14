class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int n = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>> maxpq; // max heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq; // min heap

        int left =0;
        int maxLen = 0;

        // normal sliding window implementation

        for(int right = 0; right < n; right ++){
            maxpq.push({nums[right], right});
            minpq.push({nums[right], right});

            while(maxpq.top().first - minpq.top().first > limit){
                left = min(maxpq.top().second, minpq.top().second) + 1;

                while(maxpq.top().second < left){
                    maxpq.pop();
                }

                while(minpq.top().second < left){
                    minpq.pop();
                }
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};