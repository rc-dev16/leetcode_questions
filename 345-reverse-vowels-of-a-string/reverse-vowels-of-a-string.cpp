class Solution {
public:
    string reverseVowels(string s) {

        int i = 0;
        int j = s.size() -1;

        while(i < j){
            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(isVowel(s[i])){
                j--;
            }
            else{
                i++;
            }
        }  

        return s;
    }
    
    bool isVowel(char c){
        if (c == 'A'||  c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i'
        || c == 'O' || c == 'o' || c == 'U' || c == 'u'){
            return true;
        }
        return false;
    }
};