class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {

        int n = a.size();

        int best_ending = a[0];
        int best = a[0];

        int worst_ending = a[0];
        int worst = a[0];

        for(int i = 1; i < n; i++) {

            int v1 = best_ending + a[i];
            int v2 = a[i];

            best_ending = max(v1, v2);
            best = max(best, best_ending);

            int v3 = worst_ending + a[i];
            int v4 = a[i];

            worst_ending = min(v3, v4);
            worst = min(worst, worst_ending);
        }

        return max(abs(best), abs(worst));
    }
};
