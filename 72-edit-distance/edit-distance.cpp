class Solution {
public:
    int minDistance1(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return solve(word1, word2, m, n, dp);
    }

    int solve(string &word1, string &word2, int m, int n, vector<vector<int>> &dp){
        if(n == 0){
            return m;
        }

        if(m == 0){
            return n;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        if(word1[m-1] == word2[n-1]) return solve(word1, word2, m-1, n-1, dp);

        int insert = 1 + solve(word1, word2, m, n-1, dp);

        int del = 1 + solve(word1, word2, m-1, n, dp);

        int replace = 1 + solve(word1, word2, m-1, n-1, dp);

        return dp[m][n] = min({insert, del, replace});
    }

     int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1));

        for(int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++ ){

                if(word1[i-1] == word2[j-1]){
                   dp[i][j] = dp[i-1][j-1];
                }else{
                    int insert = 1 + dp[i][j-1];
                    int del = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];
                    dp[i][j] = min({insert, del, replace});
                }
            }
        } 

        return dp[m][n];       
                   
    }
};