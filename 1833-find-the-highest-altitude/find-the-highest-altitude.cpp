class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int altitude = 0;
        int ans = 0;

        for(int x : gain) {
            altitude += x;
            ans = max(ans, altitude);
        }

        return ans;
    }
};