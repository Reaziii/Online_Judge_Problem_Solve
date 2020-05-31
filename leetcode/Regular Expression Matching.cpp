class Solution {
public:
    bool isMatch(string s, string p) {
        return match(p,s);
    }
    bool match(string &exp,string &s){
        exp.insert(exp.begin(),'?');
        s.insert(s.begin(),'?');
        int n = exp.size()-1;
        int m = s.size()-1;

        bool dp[m+3][n+3];
        memset(dp,0,sizeof(dp));

        dp[0][0] = 1;
        for(int i= 1;i<=n;i++) if(exp[i]=='*') dp[0][i]=dp[0][i-2]; 

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i]==exp[j] || exp[j]=='.') dp[i][j]=dp[i-1][j-1];
                else if(exp[j]=='*') dp[i][j] = (dp[i][j-2] | ((s[i]==exp[j-1] | exp[j-1]=='.') && dp[i-1][j])) ;
                else dp[i][j]=false;
            }
        }
        return dp[m][n];
    }

};
