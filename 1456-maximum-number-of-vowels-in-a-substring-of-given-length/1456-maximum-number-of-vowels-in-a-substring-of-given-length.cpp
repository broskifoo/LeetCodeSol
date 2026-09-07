class Solution {

public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int count  = 0;
        //initialise the window
        for ( int  i = 0 ; i< k ; i++){
            if(isVowel(s[i])){
                count++;
            }
        }

        int maxCount = count;

        // starting the sliding window
        for ( int right  = k ; right < s.size() ; right ++){
            if(isVowel(s[right])){
                count++;
            }

            // remove the character leaving the window
            if(isVowel(s[right - k])){
                count--;
            }

            maxCount = max(count , maxCount);
        }

        return maxCount;
        
        
    }
};