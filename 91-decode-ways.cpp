class Solution {
public:
    bool isLetter(char a, char b){
        if(a=='1'){
            return true;
        }else if(a=='2'){
            if(b-'0'<=6){
                return true;
            }
        }else if(a=='0'){
            if(b=='0'){
                return false;
            }else{
                return true;
            }
        }
        return false;
    }
    int numDecodings(string s) {
        int f0=1, f1=1, f2;
        if(s.size()==0 || s[0]=='0'){
            f2 = 0;
        }
        if(s.size()==1 && s!="0"){
            f2 = 1;
        }
        if(s[0]=='0'){
            f0 = 0;
            f1 = 0;
        }
        for(int i=0; i<s.size()-1; i++){
            if(s[i+1]=='0'){
                if(isLetter(s[i], s[i+1])){
                    f2 = f0;
                    f0 = f1;
                    f1 = f2;
                }else{
                    return 0;
                }
            }else{
                if(isLetter(s[i], s[i+1])){
                    f2 = f1+f0;
                    f0 = f1;
                    f1 = f2;
                }else{
                    f2 = f1;
                    f0 = f1;
                    f1 = f2;
                }
            }
        }
        return f2;
    }
};