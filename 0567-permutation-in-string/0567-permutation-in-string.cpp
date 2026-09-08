class Solution{
    public:

    bool checkInclusion(string s1 , string s2){
        if (s1.size() > s2.size()){
            return false;
        }

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        // Frequenxy of character in s1
        for (char c : s1){
            freq1[c - 'a']++;
        }

        int k = s1.size();

        //first window
        for(int  i = 0 ; i < k ; i++){
            freq2[s2[i] - 'a']++;


        }
        if (freq1 == freq2){
            return true;
        }

        //Slide the window
        for ( int right = k ; right < s2.size() ; right++){
            //add new charaters
            freq2[s2[right] - 'a']++;

            //remove the old character
            freq2[s2[right - k] - 'a']--;

            if(freq1 == freq2){
                return true;
            }
        }
        return false;


    }
};