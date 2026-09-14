class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1000000007;

        vector<int> previousSmaller(n);
        vector<int> nextSmallerOrEqual(n);

        stack<int> st;

        // Find the previous strictly smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                previousSmaller[i] = -1;
            } else {
                previousSmaller[i] = st.top();
            }

            st.push(i);
        }

        // Empty the stack before using it again
        while (!st.empty()) {
            st.pop();
        }

        // Find the next smaller or equal element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                nextSmallerOrEqual[i] = n;
            } else {
                nextSmallerOrEqual[i] = st.top();
            }

            st.push(i);
        }

        long long answer = 0;

        for (int i = 0; i < n; i++) {
            long long leftChoices = i - previousSmaller[i];
            long long rightChoices = nextSmallerOrEqual[i] - i;

            long long contribution =
                arr[i] * leftChoices * rightChoices;

            answer = (answer + contribution) % MOD;
        }

        return answer;
    }
};