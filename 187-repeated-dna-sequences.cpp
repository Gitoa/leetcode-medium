class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        set<string> ansSet;
        int left=0, right=10;
        while(right<s.size()){
            string str = s.substr(left, right-left);
            if(ansSet.count(str)==0){
                if(s.find(str, left+1)!=string::npos){
                    ansSet.insert(str);
                }
            }
            left++;
            right++;
        }
        for(set<string>::iterator iter = ansSet.begin(); iter!=ansSet.end(); iter++){
            ans.push_back(*iter);
        }
        return ans;
    }
};


//AC:
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        set<string> ansSet, resSet;
        int left=0, right=9;
        while(right<s.size()){
            string str = s.substr(left, 10);
            if(ansSet.count(str)==0){
                ansSet.insert(str);
            }else{
                resSet.insert(str);
            }
            left++;
            right++;
        }
        for(set<string>::iterator iter = resSet.begin(); iter!=resSet.end(); iter++){
            ans.push_back(*iter);
        }
        return ans;
    }
};