class Solution {
public:
    bool canChanged(string s1, string s2){
        int num = 0;
        if(s1.size()!=s2.size()){
            return false;
        }else{
            for(int i=0; i<s1.size(); i++){
                if(s1[i]!=s2[i]){
                    num++;
                }
            }
        }
        if(num==1){
            return true;
        }else{
            return false;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans=0;
        bool flag = false;
        if(find(wordList.begin(), wordList.end(), endWord)==wordList.end()){
            return ans;
        }else{
            if(canChanged(beginWord, endWord)){
                ans = 1;
                flag = true;
            }else{
                ans = 1;
                vector<string> dic;
                vector<string> tmp;
                vector<string> next;
                dic.assign(wordList.begin(), wordList.end());
                dic.erase(find(dic.begin(), dic.end(), endWord));
                next.push_back(endWord);
                while(!flag && next.size()!=0){
                    ans++;
                    tmp.clear();
                    for(vector<string>::iterator iter = dic.begin(); iter!=dic.end();){
                        bool canChangedFlag = false;
                        for(int i=0; i<next.size(); i++){
                            if(canChanged(next[i], *iter)){
                                tmp.push_back(*iter);
                                iter = dic.erase(iter);
                                canChangedFlag = true;
                                break;
                            }
                        }
                        if(!canChangedFlag){
                            iter++;
                        }
                    }
                    next.clear();
                    next.assign(tmp.begin(), tmp.end());
                    for(int i=0; i<next.size(); i++){
                        if(canChanged(next[i], beginWord)){
                            flag = true;
                            break;
                        }
                    }
                }
            }
        }
        if(flag){
            return ans+1;
        }else{
            return 0;
        }
    }
};