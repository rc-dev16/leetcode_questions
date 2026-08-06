class Solution {
public:
    int smallestNumber(int n, int t) {

        int res = INT_MAX;

        for(int i = n; i <= n+10; i++){

            int curr = i;
            int prod = 1;
            
            while(curr > 0){
                int lastDigit = curr % 10;
                prod *= lastDigit;
                curr = curr/10;
            }

            if(prod % t == 0){
                return i;
            }
        }

        return -1;   
    }
};