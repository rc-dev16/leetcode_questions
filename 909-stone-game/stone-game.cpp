class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int total = accumulate(piles.begin(), piles.end(), 0);

        int alice = solve(0, piles.size() - 1, piles);

        int bob = total - alice;

        if(alice > bob) return alice;

        return bob;
        
    }

    int solve(int i , int j, vector<int>& piles){
        if(i < j) return 0;
        
        if(i == j) return piles[i];

        int take_i = piles[i] + min(solve(i+2, j, piles), solve(i+1, j-1, piles));
        int take_j = piles[j] + min(solve(i, j-2, piles), solve(i+1, j-1, piles));

        return max(take_i, take_j);

    }
};