class Solution {
public:
    int maxSubArray(vector<int>& a) {
       int i=0;
       int  best_ending=a[0];
       int  ans=a[0];
       int n=a.size();

        for(i=1;i<n;i++)
{
    int v1=best_ending +a[i];
    int v2= a[i];
    best_ending = max(v1,v2);
   
ans=max(ans,best_ending);
}
return ans;   
    }
};