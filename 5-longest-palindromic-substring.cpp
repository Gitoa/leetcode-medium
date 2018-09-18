class Solution {
public:
    string longestPalindrome(string s) {
        int pos1=0, pos2=0;
        int len = s.length();
        int maxLen = 0;
        int posBegin=0;
        for(int i=0; i<len; i++){
            pos1=i;
            pos2=i;
            while(pos2+1<len && s[pos2+1]==s[pos1]){
                pos2++;
            }
            while(pos1>0&&pos2<len-1&&s[pos1-1]==s[pos2+1]){
                pos1--;
                pos2++;
            }
            if(pos2-pos1+1>maxLen){
                maxLen = pos2-pos1+1;
                posBegin = pos1;
            }
        }
        return s.substr(posBegin, maxLen);
    }
};