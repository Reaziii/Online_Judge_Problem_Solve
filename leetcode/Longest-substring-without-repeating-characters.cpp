class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        set<int> inside;
        int end = 0;
        inside.insert(s[0]);
        for(int i=0;i<s.size();i++){
            while(end+1<s.size() && !inside.count(s[end+1])){
                end++;
                inside.insert(s[end]);
            }
            
            ans = max(end-i+1,ans);
            inside.erase(s[i]);
        }
        
        return ans;
    }
};
