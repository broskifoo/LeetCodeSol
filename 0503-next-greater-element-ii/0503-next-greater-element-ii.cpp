class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n , -1);
        stack<int> st;

        for ( int i = 0 ; i < 2*n ; i++){
            int currentindex = i % n;
            while ( !st.empty() && nums[currentindex] > nums[st.top()]){
                answer[st.top()] = nums[currentindex];
                st.pop();
            }
            if(i < n){
                st.push(currentindex);
            }

        }
        return answer;
        
    }
};