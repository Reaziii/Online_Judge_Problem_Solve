class Solution {
public:
    string longestPalindrome(string s) {
        string long_p ="";
        for(int mid=0;mid<s.size();mid++){
            for(int x = 0;x<s.size();x++){
                if(mid-x<0) break;
                if(s[mid-x]!=s[mid+x]){
                    break;
                }
                int len = x*2+1;
                if(long_p.size()<len){
                    long_p=s.substr(mid-x,len);
                }
            }
        }

        for(int mid = 0; mid<s.size();mid++){
            for(int x = 0; x<s.size();x++){
                if(mid-x<0) break;
                if(s[mid-x]!=s[mid+x+1]) break;
                int len = x*2+2;
                if(long_p.size()<len) {
                    long_p = s.substr(mid-x,len);
                }
            }
        }

        return long_p;
    }
};
