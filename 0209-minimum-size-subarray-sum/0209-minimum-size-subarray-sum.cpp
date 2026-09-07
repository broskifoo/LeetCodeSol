class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left  = 0;
        int sum = 0 ;
        int ans = INT_MAX;

        for ( int right = 0 ; right < nums.size() ; right ++){
            //add new element 
            sum += nums[right];

            //shrink while window is valid
            while ( sum >= target){
                ans = min(ans , right - left +1);

                //remove the left element
                sum -= nums[left];
                left++;
            }
        }
        if (ans == INT_MAX){
            return 0;
        }

    return ans;
        
    }
};