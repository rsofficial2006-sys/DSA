class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxSeen = INT_MIN;
        int minSeen = INT_MAX;

        int left = -1, right = -1;

        
        for (int i = 0; i < n; i++) {
            maxSeen = max(maxSeen, nums[i]);
            if (nums[i] < maxSeen) {
                right = i;
            }
        }

        // Right to Left
        for (int i = n - 1; i >= 0; i--) {
            minSeen = min(minSeen, nums[i]);
            if (nums[i] > minSeen) {
                left = i;
            }
        }

        if (right == -1)
            return 0;

        return right - left + 1;
    }
};