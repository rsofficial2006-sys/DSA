class Solution {
public:

    int findMaxFreq(vector<int> &freq)
    {
        int maxFreq = 0;

        for (int i = 0; i < 256; i++)
        {
            maxFreq = max(maxFreq, freq[i]);
        }

        return maxFreq;
    }

    int characterReplacement(string s, int k)
    {
        int n = s.size();

        vector<int> freq(256, 0);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++)
        {
            freq[s[right]]++;

            int maxFreq = findMaxFreq(freq);

            int windowSize = right - left + 1;

            while (windowSize - maxFreq > k)
            {
                freq[s[left]]--;
                left++;

                maxFreq = findMaxFreq(freq);
                windowSize = right - left + 1;
            }

            ans = max(ans, windowSize);
        }

        return ans;
    }
};