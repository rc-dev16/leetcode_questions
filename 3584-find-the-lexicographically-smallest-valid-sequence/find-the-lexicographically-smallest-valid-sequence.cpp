class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> match(n, 0);
        int rightMatch = 0;
        int i = n-1;
        int j = m-1;

        while(i >= 0){

            if(j>=0 && word1[i] == word2[j]){
                rightMatch++;
                j--;
            }

            match[i] = rightMatch;
            i--;
        }
        
        vector<int> res;
        bool changePower = true;

        i = 0;
        j = 0;

        while(i < n && j < m){
            if(word1[i] == word2[j]){
                res.push_back(i);
                j++;
            }else if(changePower == true && i+1 < n && match[i+1] >= m-j-1){
                res.push_back(i);
                j++;
                changePower = false;
            }
            i++;
        }

        return j == m ? res : vector<int>(); 
    }
};