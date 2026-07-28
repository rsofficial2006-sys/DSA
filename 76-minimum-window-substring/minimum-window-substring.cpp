class Solution {
public:

    bool fun(vector<int> &have, vector<int> &need)
    {
        for(int i=0;i<256;i++)
        {
            if(have[i]<need[i])
            return false;
        }
        return true;
    }
    string minWindow(string s, string t){
        int n=s.size();
        int m=t.size();

        vector<int>have(256,0);
        vector<int>need(256,0);

        if(n<m)
            return"";

        for(int i=0;i<m;i++)
        {
            need[t[i]]++;
        }

        int low = 0;
        int high = 0;

        int res = INT_MAX;
        int start = -1;

        while(high < n)
        {
            // character add karo window me
            have[s[high]]++;

            // jab tak valid window hai shrink karo
            while(fun(have,need))
            {
                int len = high - low + 1;

                if(len < res)
                {
                    res = len;
                    start = low;
                }

                // left character remove
                have[s[low]]--;
                low++;
            }

            high++;
        }

        if(start == -1)
            return "";

        return s.substr(start,res);
    }
};
