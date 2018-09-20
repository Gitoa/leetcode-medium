class Solution {
public:
    string toString(char s){
        string str;
        str.push_back(s);
        return str;
    }
    vector<string> letterCombinations(string digits) {
        //tree node
        vector<string> v;
        vector<string> ans;
        map<char, string>m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        string tmp = m[digits[0]];
        for(int i=0; i<tmp.length(); i++){
            v.push_back(toString(tmp[i]));
        }
        if(digits.size()==1){
            return v;
        }
        for(int i=1; i<digits.length(); i++){
            string str=m[digits[i]]; 
            ans.clear();
            for(int j=0; j<v.size(); j++){             
                for(int k=0; k<str.length(); k++){
                    string tmpStr = v[j];
                    tmpStr.push_back(str[k]);
                    ans.push_back(tmpStr);
                }
            }
            v=ans;
        }
        return ans;
    }
};
