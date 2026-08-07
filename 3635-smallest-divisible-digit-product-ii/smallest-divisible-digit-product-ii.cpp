class Solution {
    inline static string dp[55][35];
    inline static bool initialized = false;
public:
    string smallestNumber(string num, long long t) {
        if (!initialized) {
            for (int i = 0; i <= 50; ++i) {
                for (int j = 0; j <= 30; ++j) {
                    dp[i][j] = string(100, '9');
                }
            }
            dp[0][0] = "";
            
            for (int i = 0; i <= 50; ++i) {
                for (int j = 0; j <= 30; ++j) {
                    if (i == 0 && j == 0) continue;
                    for (int d = 2; d <= 9; ++d) {
                        if (d == 5 || d == 7) continue;
                        int c2 = 0, c3 = 0, temp = d;
                        while (temp % 2 == 0) { c2++; temp /= 2; }
                        while (temp % 3 == 0) { c3++; temp /= 3; }
                        
                        int pi = max(0, i - c2);
                        int pj = max(0, j - c3);
                        
                        string cand = dp[pi][pj] + to_string(d);
                        sort(cand.begin(), cand.end());
                        
                        if (cand.length() < dp[i][j].length() || 
                           (cand.length() == dp[i][j].length() && cand < dp[i][j])) {
                            dp[i][j] = cand;
                        }
                    }
                }
            }
            initialized = true;
        }

        int target2 = 0, target3 = 0, target5 = 0, target7 = 0;
        long long temp_t = t;
        while (temp_t % 2 == 0) { target2++; temp_t /= 2; }
        while (temp_t % 3 == 0) { target3++; temp_t /= 3; }
        while (temp_t % 5 == 0) { target5++; temp_t /= 5; }
        while (temp_t % 7 == 0) { target7++; temp_t /= 7; }
        
        if (temp_t != 1) return "-1";
        
        int n = num.length();
        vector<int> pref2(n + 1, 0), pref3(n + 1, 0), pref5(n + 1, 0), pref7(n + 1, 0);
        int z = n;
        
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0' && z == n) z = i;
            pref2[i+1] = pref2[i];
            pref3[i+1] = pref3[i];
            pref5[i+1] = pref5[i];
            pref7[i+1] = pref7[i];
            int d = num[i] - '0';
            if (d > 0) {
                int temp = d;
                while (temp % 2 == 0) { pref2[i+1]++; temp /= 2; }
                while (temp % 3 == 0) { pref3[i+1]++; temp /= 3; }
                while (temp % 5 == 0) { pref5[i+1]++; temp /= 5; }
                while (temp % 7 == 0) { pref7[i+1]++; temp /= 7; }
            }
        }
        
        if (z == n) {
            if (pref2[n] >= target2 && pref3[n] >= target3 && 
                pref5[n] >= target5 && pref7[n] >= target7) {
                return num;
            }
        }
        
        int start_i = min(n - 1, z);
        for (int i = start_i; i >= 0; --i) {
            int start_d = (num[i] - '0') + 1;
            for (int d = start_d; d <= 9; ++d) {
                int c2 = 0, c3 = 0, c5 = 0, c7 = 0, temp = d;
                while (temp % 2 == 0) { c2++; temp /= 2; }
                while (temp % 3 == 0) { c3++; temp /= 3; }
                while (temp % 5 == 0) { c5++; temp /= 5; }
                while (temp % 7 == 0) { c7++; temp /= 7; }
                
                int rem2 = max(0, target2 - (pref2[i] + c2));
                int rem3 = max(0, target3 - (pref3[i] + c3));
                int rem5 = max(0, target5 - (pref5[i] + c5));
                int rem7 = max(0, target7 - (pref7[i] + c7));
                
                string req23 = dp[rem2][rem3];
                int total_needed = rem5 + rem7 + req23.length();
                int available = n - 1 - i;
                
                if (total_needed <= available) {
                    string prefix = num.substr(0, i) + to_string(d);
                    string suffix = string(available - total_needed, '1') + 
                                    string(rem5, '5') + string(rem7, '7') + req23;
                    sort(suffix.begin(), suffix.end());
                    return prefix + suffix;
                }
            }
        }
        
        string req23 = dp[target2][target3];
        int min_len = target5 + target7 + req23.length();
        int final_len = max(n + 1, min_len);
        string ans = string(final_len - min_len, '1') + string(target5, '5') + 
                     string(target7, '7') + req23;
        sort(ans.begin(), ans.end());
        return ans;
    }
};