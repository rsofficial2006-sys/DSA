class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0;
        int best_ending = nums[0];
        int maxSum=nums[0];
        int worst_ending =nums[0];
        int minSum=nums[0];

        for(int i=0;i<nums.size();i++){
            total+=nums[i];

            if(i>0){
                best_ending=max(nums[i],best_ending+nums[i]);
                maxSum=max(maxSum,best_ending);

                worst_ending=min(nums[i],worst_ending+nums[i]);
                minSum=min(minSum,worst_ending);
            }
    }
    if(maxSum<0)
        return maxSum;

    return max(maxSum,total-minSum);
    }
};