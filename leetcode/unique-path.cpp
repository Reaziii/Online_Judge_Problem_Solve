class Solution {
public:
    int dp[2000][2000];
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return sol(n,m);
    }
    
    int sol(int n,int m){
        if(n==1 || m==1) return 1;
        if(dp[n][m]!=-1) return dp[n][m];
        return dp[n][m] = sol(n-1,m)+sol(n,m-1);
    }
};
