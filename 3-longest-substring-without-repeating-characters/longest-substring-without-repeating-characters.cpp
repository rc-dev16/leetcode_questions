class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<int, int> mp;

        int left = 0;
        int maxLen = INT_MIN;

        if (n == 0) return  0;

        for(int right = 0; right < n; right++){
            mp[s[right]]++;

            while(mp[s[right]] > 1){
                mp[s[left]]--;

                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
        
    }
};