class Solution {
public:
    int total=-1;
    
    bool vis[100000]={0};
    int ans[100000]={0};
    int am=0;
    int coinChange(vector<int>& coins, int amount) {
        int total_coin = coins.size();
        if(total==-1) total=total_coin;
        int n = amount;
        if(am==0)am=amount;
        if(n<0) return 100000000;
        
        if(n==0) return 0;
        
        if(vis[amount]==0){
            int x = 10000000;
            
            for(int i=0;i<total;i++){
                x = min(x,coinChange(coins,amount-coins[i]));
                
                
            }
            
            vis[amount]=true;
            ans[amount]=x;
            
            
            
        }
        
        if(amount!=am)return ans[amount]+1;
        else if(amount==am){
            if(ans[amount]>1000000) return -1;
            else return ans[amount]+1;
            
            
        }
        
        return 0;

        
        
        
        
        
        
        
        
    }
};
