class Solution {
public:
    long long getPerms(const vector<int>& cnt) {
        long long perms = 1;
        int cur_len = 0;
        for (int c = 0; c < 26; ++c) {
            for (int i = 1; i <= cnt[c]; ++i) {
                cur_len++;
                perms = perms * cur_len / i;
                if (perms > 1000000000LL) return 1000000001LL;
            }
        }
        return perms;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        
        int odd_c = -1;
        int half_len = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2 != 0) {
                odd_c = i;
            }
            cnt[i] /= 2;
            half_len += cnt[i];
        }
        
        if (getPerms(cnt) < k) {
            return "";
        }
        
        string half = "";
        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (cnt[c] > 0) {
                    cnt[c]--;
                    long long p = getPerms(cnt);
                    if (p < k) {
                        k -= p;
                        cnt[c]++;
                    } else {
                        half += (char)('a' + c);
                        break;
                    }
                }
            }
        }
        
        string ans = half;
        if (odd_c != -1) {
            ans += (char)('a' + odd_c);
        }
        reverse(half.begin(), half.end());
        ans += half;
        
        return ans;
    }
};