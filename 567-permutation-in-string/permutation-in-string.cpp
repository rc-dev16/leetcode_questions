class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> s2freq(26, 0);
        vector<int> s1freq(26,0);

        for(int i = 0; i < n; i++){
            int idx = s1[i] - 'a';
            s1freq[idx]++;
        }

        int i =0;
        int j =0;

        while(j < m){
            
            s2freq[s2[j] - 'a']++;

            if(j - i + 1 > n){
                s2freq[s2[i] - 'a']--; // yaha pe window shrink karni hai. kyuki window ka size badh gaya hai.
                i++;
            }

            if(s1freq == s2freq){  // yaha pe dono freq vector compare karenge barabr hai toh true return kar denge
                return true;
            }
            
            j++; // normal window aage bade gi
        } 

        return false;
    }
};