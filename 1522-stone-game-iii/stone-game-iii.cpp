class Solution {
public:
    int n;
    

    string stoneGameIII(vector<int>& stoneValue) {

        n = stoneValue.size();

        vector<int> dp(n+1, -1);

        int diff = solve(0, n, stoneValue, dp);

        if(diff > 0) 
            return "Alice";
        else if(diff < 0)
            return "Bob";
        else
            return "Tie";
        
    }

    
    int solve(int i, int n, vector<int>& stoneValue,  vector<int> &dp){

        if(i >= n)return 0;

        if(dp[i] != -1){
            return dp[i];
        }

        int res = stoneValue[i] - solve(i+1, n, stoneValue, dp);

        if(i+1 < n){
            res = max(res, stoneValue[i] + stoneValue[i+1] - solve(i+2, n, stoneValue, dp));
        }

        if(i+2 < n){
            res = max(res, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2]- solve(i+3, n, stoneValue, dp));
        }

        return dp[i] = res;
    }
};