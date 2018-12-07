class Solution {
public:
    void reverseWords(string &s) {
        if(s.size()==0){
            return;
        }
        reverse(s.begin(), s.end());
        int tSpaceEnd=s.size()-1;
        int tSpaceBegin=tSpaceEnd;
        while(tSpaceBegin>=0 && s[tSpaceBegin]==' '){
            tSpaceBegin--;
        }
        tSpaceBegin++;
        if(tSpaceBegin==0){
            s="";
            return;
        }else{
            s.erase(s.begin()+tSpaceBegin, s.end());
        }
        int lSpaceBegin=0;
        int lSpaceEnd=0;
        while(s[lSpaceEnd]==' '){
            lSpaceEnd++;
        }
        s.erase(s.begin()+lSpaceBegin, s.begin()+lSpaceEnd);
        int wordBegin=0, wordEnd=0;
        while(wordEnd!=s.size()-1){
            if(s[wordEnd]!=' '){
                wordEnd++;
            }else{
                reverse(s.begin()+wordBegin, s.begin()+wordEnd);
                while(s[wordEnd]==' '){
                    wordEnd++;
                }
                wordBegin = wordEnd;
            }
        }
        reverse(s.begin()+wordBegin, s.end());
        int spaceEnd=s.size()-1;
        while(s[spaceEnd]!=' '){
            spaceEnd --;
        }
        int spaceBegin = spaceEnd;
        while(spaceEnd>0){
            spaceBegin = spaceEnd;
            while(s[spaceBegin]==' '){
                spaceBegin--;
            }
            spaceBegin++;
            if(spaceEnd!=spaceBegin){
                s.erase(spaceBegin, spaceEnd-spaceBegin);
            }
            spaceEnd=spaceBegin-1;
            while(s[spaceEnd]!=' '){
                spaceEnd --;
            }
        }
    }
};