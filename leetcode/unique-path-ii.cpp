class Solution {
public:
    long dp[1000][1000];
    long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        long n = obstacleGrid.size();
        long m = obstacleGrid[0].size();
        return sol(obstacleGrid,n-1,m-1);
    }
    
    long sol(vector<vector<int>> &obs,long n,long m){
        if(obs[0][0]==1) return 0;
        if(n==0 && m==0) return 1;
        if(obs[n][m]==1) return dp[n][m] = 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(n==0 || m==0){
            if(n==0) return sol(obs,n,m-1);
            else return sol(obs,n-1,m);
        }
        
        return dp[n][m] = sol(obs,n-1,m)+sol(obs,n,m-1);
        
    }
};
