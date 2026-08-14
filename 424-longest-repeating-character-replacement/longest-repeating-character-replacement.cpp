class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        vector<int> fq(26, 0);

        int maxLen = 0;
        int maxFreq = 0;

        int left = 0;

        for(int right =0; right<n; right++){
            fq[s[right] - 'A']++;

            maxFreq = max(maxFreq, fq[s[right] - 'A']);

            while((right - left + 1) -  maxFreq > k){
                fq[s[left] - 'A']--;
                left ++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
        
    }
};