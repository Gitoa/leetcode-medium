class Solution {
public:
    struct sNode{
        int begin;
        int end;
        sNode(int a, int b) : begin(a), end(b){}
    };
    vector<vector<sNode>> ans;
    void dfs(int pos, map<int, vector<int>> m, int len, vector<sNode>path){
        if(pos == len){
            ans.push_back(path);
            return;
        }
        for(int i=0; i<m[pos].size(); i++){
            int nextPos = m[pos][i];
            sNode tmp(pos, nextPos);
            path.push_back(tmp);
            dfs(nextPos+1, m, len, path);
            path.erase(path.end()-1);
        }
    }
    vector<vector<string>> partition(string s) {
        map<int, vector<int>> m;
        int len = s.size();
        vector<sNode> two;
        for(int i=0; i<len-1; i++){
            if(s[i+1] == s[i]){
                sNode tmp(i, i+1);
                two.push_back(tmp);
            }
        }
        for(int i=0; i<len; i++){
            int begin = i;
            int end = i;
            while(begin>=0 && end<len){
                if(s[begin]==s[end]){
                    m[begin].push_back(end);
                    begin--;
                    end++;
                }else{
                    break;
                }
            }
        }
        for(int i=0; i<two.size(); i++){
            sNode tmp = two[i];
            int begin = tmp.begin;
            int end = tmp.end;
            while(begin>=0 && end<len){
                if(s[begin]==s[end]){
                    m[begin].push_back(end);
                    begin--;
                    end++;
                }else{
                    break;
                }
            }
        }
        vector<sNode> path;
        dfs(0, m, len, path);
        vector<vector<string>> ansS;
        for(int i=0; i<ans.size(); i++){
            vector<string> tmpS;
            for(int j=0; j<ans[i].size(); j++){
                sNode tmp = ans[i][j];
                tmpS.push_back(s.substr(tmp.begin, tmp.end-tmp.begin+1));
            }
            ansS.push_back(tmpS);
        }
        return ansS;
    }
};