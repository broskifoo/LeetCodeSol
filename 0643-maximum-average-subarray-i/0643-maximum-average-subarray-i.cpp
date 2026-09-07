class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;

//initialise the first window
        for ( int  i = 0 ; i < k ; i++){
            sum += nums[i];
        }
        int maxSum = sum;
        // sliding the window
        for ( int right =k ; right < nums.size() ; right++){
            sum += nums[right]; // add new elements
            sum -= nums[right - k];

            maxSum = max(maxSum , sum);
        }
        return (double)maxSum/k;
    }
};