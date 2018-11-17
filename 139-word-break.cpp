class Solution {
private:
    bool flag=false;
    vector<string> dict;
    static bool cmp(string s1, string s2){
        return s1.size() < s2.size();
    }
    vector<bool> vis;
public:
    void dfs(map<int, vector<int>>&m, int len, int pos){
        if(!flag){
            if(pos==len){
                flag=true;
                return;
            }else{
                if(vis[pos] == true){
                    return;
                }
                vis[pos]=true;
                vector<int> tmp = m[pos];
                for(int i=0; i<tmp.size(); i++){
                    dfs(m, len, tmp[i]);
                }
            }
        }
    }
    bool wordBreakTmp(string s, vector<string>& wordDict) {
        flag = false;
        vis.clear();
        for(int i=0; i<s.size(); i++){
            vis.push_back(false);
        }
        map<int, vector<int>> m;
        for(int i=0; i<wordDict.size(); i++){
            string str = wordDict[i];
            int beginPos = s.find(str, 0);
            int endPos = beginPos;
            while(beginPos != string::npos){
                endPos = beginPos + str.size();
                m[beginPos].push_back(endPos);
                beginPos = s.find(str, beginPos+1);
            }
        }
        dfs(m, s.size(), 0);
        return flag;
    }
    void wordBreakDict(vector<string>&wordDict){
        sort(wordDict.begin(), wordDict.end(), cmp);
        dict.push_back(wordDict[0]);
        for(int i=1; i<wordDict.size(); i++){
            string s = wordDict[i];
            if(!wordBreakTmp(s, dict)){
                dict.push_back(s);
            }
        }
    }
    bool wordBreak(string s, vector<string>&wordDict){
        if(wordDict.size()==0){
            return false;
        }
        wordBreakDict(wordDict);
        for(int i=0; i<dict.size(); i++){
            cout<<dict[i]<<endl;
        }
        return wordBreakTmp(s, dict);
    }
};