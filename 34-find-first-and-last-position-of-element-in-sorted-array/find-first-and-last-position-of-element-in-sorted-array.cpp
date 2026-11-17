
class Solution {
public:
    vector<int> searchRange(vector<int>& a, int x) {
        int n = a.size();
        int first = -1, last = -1;

        int low = 0;
        int high = n - 1;

        
        while(low <= high) {
            int guess = (low + high) / 2;

            if(a[guess] < x) {
                low = guess + 1;
            }
            else if(a[guess] > x) {
                high = guess - 1;
            }
            else {
                first = guess;
                high = guess - 1;
            }
        }

        low = 0;
        high = n - 1;

        
        while(low <= high) {
            int guess = (low + high) / 2;

            if(a[guess] < x) {
                low = guess + 1;
            }
            else if(a[guess] > x) {
                high = guess - 1;
            }
            else {
                last = guess;
                low = guess + 1;
            }
        }

        return {first, last};
    }
};
