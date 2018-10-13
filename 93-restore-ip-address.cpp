class Solution {
private:
    string tmp;
    vector<string> ans;
public:
    bool isIP(string s){
        if(s.size()==3){
            if(s[0]>'2'){
                return false;
            }else if(s[0]=='2'){
                if(s[1]>'5'){
                    return false;
                }else if(s[1]=='5'){
                    if(s[2]>'5'){
                        return false;
                    }
                }
            }
        }
        if(s.size()!=1 && s[0]=='0'){
            return false;
        }
        return true;
    }
    void addIP(int pos, int block, int resLen, string s){
        cout<< tmp <<endl;
        if(block==4){
            string str = s.substr(pos, resLen);
            if(isIP(str)){
                tmp += (str);
                ans.push_back(tmp);
                tmp = tmp.substr(0, s.size()-resLen + block - 1);
            }
        }
        int least = resLen - (4-block) * 3;
        int most = resLen - (4-block) * 1;
        least = least>1?least:1;
        most = most<3?most:3;
        for(int i=least; i<=most; i++){
            string str = s.substr(pos, i);
            if(isIP(str)){
                tmp += (str + ".");
                addIP(pos+i, block+1, resLen-i, s);
                tmp = tmp.substr(0, s.size() - resLen + block - 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int resLen = s.size();
        addIP(0, 1, resLen, s);
        return ans;
        
    }
};