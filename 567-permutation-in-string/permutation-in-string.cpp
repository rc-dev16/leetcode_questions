class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
      
        unordered_map<int, int> fqs1;
        unordered_map<int, int> fqs2;

        for(int i = 0; i<m; i++){
            fqs1[s1[i]]++;
        }

        int left = 0;
        for(int right =0; right < n; right++){
            fqs2[s2[right]]++;

            if(right - left + 1 == m){
                if(fqs1 == fqs2) return true;

                fqs2[s2[left]]--;
                if(fqs2[s2[left]] == 0){
                    fqs2.erase(s2[left]);
                }
                left++;
            }
        }

        return false;
    }
};