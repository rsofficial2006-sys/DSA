class Solution {
public:
    long long shadowPairs(vector<int>& nums) {

        int n = nums.size();

        // next smaller element
        vector<int> nextSmaller(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() &&
                   nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (!st.empty())
                nextSmaller[i] = st.top();

            st.push(i);
        }

        // Store positions of every value
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            int r = nextSmaller[i];

            // j can be from i+1 to r-1
            long long total = r - i - 1;

            // Remove elements equal to nums[i]
            auto &v = pos[nums[i]];

            auto it1 = upper_bound(v.begin(), v.end(), i);
            auto it2 = lower_bound(v.begin(), v.end(), r);

            long long equalCount = it2 - it1;

            ans += total - equalCount;
        }

        return ans;
    }
};