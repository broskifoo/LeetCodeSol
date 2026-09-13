class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for(char digit : num){
            while ( !st.empty() && k>0 && st.back() > digit){
                st.pop_back();
                k--;
            }
            st.push_back(digit);

        }

        // if removals are still left
        while( k > 0 ){
            st.pop_back();
            k--;
        }

        //Remove leading zeros
        int start = 0;
        while ( start < st.size() && st[start] == '0'){
            start ++;
        }
        string result = st.substr(start);

        // Return "0" if no digits remain
        if (result.empty()) {
            return "0";
        }

        return result;
        
    }
};