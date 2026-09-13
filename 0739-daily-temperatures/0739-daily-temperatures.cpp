class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int>answer(n,0);
        stack<int> days;

        for(int currentday = 0 ; currentday < n ; currentday++){
            while ( !days.empty() && temperatures[currentday] > temperatures[days.top()]){
                int previousday = days.top();
                days.pop();
                answer[previousday] = currentday - previousday;
            }
            days.push(currentday);
        }
        return answer;
        
    }
};