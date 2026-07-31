class Solution {
public:
    int minimumPushes(string word) {
        // we store frequency in map 
        vector<int> freq(26, 0);
        for(char ch : word){
            int idx = ch - 'a';
            freq[idx]++;
        }
        int res = 0;
        sort(freq.begin(), freq.end(), greater<int>());
        for(int i =0; i< freq.size(); i++){
            int temp = (i/ 8) + 1;
            res += temp * freq[i];
        }

        return res;   
    }
};