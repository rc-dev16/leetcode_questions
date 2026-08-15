class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {

        int n = nums.size();

        vector<int> res;

        vector<int> fq(51, 0);

        int left = 0;

        for(int right =0; right < n; right++){
            
            if(nums[right] < 0){
                fq[abs(nums[right])]++;
            }

            while(right - left +1 > k){
                if(nums[left] < 0){
                    fq[abs(nums[left])]--;
                }    
                left++;
            }

            if(right - left + 1 == k){
                int count = 0;
                int beauty = 0;

                for(int i =50; i > 0; i--){
                    count += fq[i];

                    if(count >= x){
                        beauty = -i;
                        break;
                    }
                }

                res.push_back(beauty);
            }
        }

        return res;

        
    }
};