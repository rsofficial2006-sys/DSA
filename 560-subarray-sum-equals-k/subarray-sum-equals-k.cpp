class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        unordered_map<int,int>f;
        int sum=0;
        int n=a.size();
        int res=0;
        f[0]=1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        int ques=(sum-k);
        int freq=f[ques];
        res+=freq;
        f[sum]++;
    }
    return res;
    }
};