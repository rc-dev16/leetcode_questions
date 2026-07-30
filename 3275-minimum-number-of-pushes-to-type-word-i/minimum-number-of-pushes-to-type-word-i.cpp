class Solution {
public:
    int minimumPushes(string word) {

        int n = word.size();

        int res = 0;

        unordered_map<int, int> mp;
        int assignKey = 2;

        for(char &ch : word){
            if(assignKey > 9){
                assignKey = 2;
            }

            mp[assignKey]++;
            res += mp[assignKey];

            assignKey++;
        } 

        return res;  
    }
};