class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 3>> a;

        for(int i=0;i<n;i++){
            a.push_back({intervals[i][0], intervals[i][1], i});
        }

        sort(a.begin(),a.end());

        vector<long long> weight(n);
        for(int i=0;i<n;i++){
            weight[i]=intervals[a[i][2]][2];
        }

        vector<int> nxt(n);

        for(int i=0;i<n;i++){
            int l=i+1,r=n-1,ans=n;

            while(l<=r){
                int mid=(l+r)/2;

                if(a[mid][0]>a[i][1]){
                    ans=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }

            nxt[i]=ans;
        }

        vector<vector<pair<long long,vector<int>>>> dp(n+1,
            vector<pair<long long,vector<int>>>(5));

        for(int i=n-1;i>=0;i--){
            for(int k=1;k<=4;k++){
                dp[i][k]=dp[i+1][k];

                long long score=weight[i]+dp[nxt[i]][k-1].first;
                vector<int> cur=dp[nxt[i]][k-1].second;
                cur.push_back(a[i][2]);

                sort(cur.begin(),cur.end());

                if(score>dp[i][k].first ||
                   (score==dp[i][k].first && cur<dp[i][k].second)){
                    dp[i][k]={score,cur};
                }
            }
        }

        return dp[0][4].second;
    }
};