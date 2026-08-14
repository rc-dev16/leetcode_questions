class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq;

        vector<int> res;

        for(int i=0; i<n; i++){
            // make space for new ele
            while(!deq.empty() && deq.front() <= i-k){
                deq.pop_front();
            }

            // check new element if bigger then pop small elements from deq
            while(!deq.empty() && nums[i] > nums[deq.back()]){
                deq.pop_back();
            }
            
            // push the current ele idx into deq
            deq.push_back(i);

            // 
            if(i >= k-1){
                res.push_back(nums[deq.front()]);
            }
        }
        return res;

    }
};