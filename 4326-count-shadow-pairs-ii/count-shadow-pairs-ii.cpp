class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();

        // Arrange slots by nums value.
        // Then all nums[i] < x form one prefix of slots.
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            if (nums[a] != nums[b])
                return nums[a] < nums[b];
            return a < b;
        });

        vector<int> slot(n);
        vector<int> sortedValues(n);

        for (int p = 0; p < n; p++) {
            slot[order[p]] = p;
            sortedValues[p] = nums[order[p]];
        }

        int B = 230;
        int blocks = (n + B - 1) / B;

        const long long INF = (1LL << 60);

        vector<long long> threshold(n, INF);
        vector<bool> active(n, false);

        // lazy[b] = cap applied to the whole block
        vector<long long> lazy(blocks, INF);

        // sorted thresholds of active elements in each block
        vector<vector<long long>> bucket(blocks);

        auto push = [&](int b) {
            if (lazy[b] == INF)
                return;

            int L = b * B;
            int R = min(n, L + B);

            for (int p = L; p < R; p++) {
                if (active[p])
                    threshold[p] = min(threshold[p], lazy[b]);
            }

            lazy[b] = INF;
        };

        auto rebuild = [&](int b) {
            bucket[b].clear();

            int L = b * B;
            int R = min(n, L + B);

            for (int p = L; p < R; p++) {
                if (active[p])
                    bucket[b].push_back(threshold[p]);
            }

            sort(bucket[b].begin(), bucket[b].end());
        };

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            long long y = nums[j];

            // All slots whose value is strictly smaller than nums[j]
            int R = lower_bound(
                sortedValues.begin(),
                sortedValues.end(),
                nums[j]
            ) - sortedValues.begin() - 1;

            if (R >= 0) {
                int lastBlock = R / B;

                // Complete blocks
                for (int b = 0; b < lastBlock; b++) {

                    if (lazy[b] >= y) {
                        auto it = lower_bound(
                            bucket[b].begin(),
                            bucket[b].end(),
                            y
                        );

                        ans += bucket[b].end() - it;
                    }

                    lazy[b] = min(lazy[b], y);
                }

                // Partial last block
                int b = lastBlock;

                push(b);

                int L = b * B;

                for (int p = L; p <= R; p++) {
                    if (active[p] && threshold[p] >= y) {
                        ans++;
                        threshold[p] = y;
                    }
                }

                rebuild(b);
            }

            // Current j becomes a possible i for future elements
            int p = slot[j];
            int b = p / B;

            push(b);

            active[p] = true;
            threshold[p] = INF;

            rebuild(b);
        }

        return ans;
    }
};