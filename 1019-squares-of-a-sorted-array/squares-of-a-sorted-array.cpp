class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> neg, pos;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0)
                neg.push_back(nums[i] * nums[i]);
            else
                pos.push_back(nums[i] * nums[i]);
        }

        reverse(neg.begin(), neg.end());

        vector<int> ans;

        int i = 0, j = 0;

        while(i < neg.size() && j < pos.size()) {
            if(neg[i] < pos[j]) {
                ans.push_back(neg[i]);
                i++;
            } else {
                ans.push_back(pos[j]);
                j++;
            }
        }

        while(i < neg.size()) {
            ans.push_back(neg[i]);
            i++;
        }

        while(j < pos.size()) {
            ans.push_back(pos[j]);
            j++;
        }

        return ans;
    }
};