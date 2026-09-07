class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0 ;
        int ans = 0;
        unordered_map<char, int>freq;

        for (int right = 0 ; right < s.size() ; right++){
            //add new character
            freq[s[right]]++;

            while (freq[s[right]] > 1){
                freq[s[left]]--;
                left++;
            }

            //current window is valid
            ans = max(ans , right - left + 1);
        }
        
        return ans;
    }
};