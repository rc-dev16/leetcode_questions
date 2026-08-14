class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();

        unordered_map<int, int> mp;
        int maxLen = INT_MIN;

        int left = 0;
        for(int right = 0; right < n; right++){
            mp[s[right]]++;

            while(mp[s[right]] > 2){
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