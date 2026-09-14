class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();

        vector<int> answer(n,0);
        stack<int> st;

        for ( int  i = n-1 ; i>=0 ; i--){
            while ( !st.empty() && heights[i] > st.top()){
                answer[i]++;
                st.pop();
            }

            if(!st.empty()){
                answer[i]++;
            }
            st.push(heights[i]);
        }
        return answer;


        
    }
};