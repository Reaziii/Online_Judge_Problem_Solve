class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int a = nums[0];
        int b = nums[0];
        for(int i=1;i<nums.size();i++){
            if(b+nums[i]<nums[i]){
                a = max(a,b);
                b=nums[i];
            }
            else b+=nums[i];
            a = max(a,b);
        }
        return max(a,b);
        
    }
};
