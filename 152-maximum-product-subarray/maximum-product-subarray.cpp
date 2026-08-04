class Solution {
public:
    int maxProduct(vector<int>& a) {
        int i=0;
        int min_ending =a[0];
        int max_ending =a[0];
        int res=a[0];
        int n =a.size();

        for(i=1;i<n;i++){
            int v1=a[i];
            int v2= min_ending*a[i];
            int v3= max_ending*a[i];

            max_ending=max(v1,max(v2,v3));
            min_ending=min(v1,min(v2,v3));
            res=max(res,max(max_ending,min_ending));        
    }
    return res;
    }
};