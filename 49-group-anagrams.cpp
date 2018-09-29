class Solution {
public:
    int findGroup(vector<vector<string>> s, string str){
        sort(str.begin(), str.end());
        for(int i=0; i<s.size(); i++){
            string tmp = s[i][0];
            sort(tmp.begin(), tmp.end());
            if(tmp==str){
                return i;
            }
        }
        return -1;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        /*
		暴力方法遍历查找，时间复杂度为O(n2);
		
		for(int i=0; i<strs.size(); i++){
            int pos=findGroup(ans, strs[i]);
            if(pos==-1){
                vector<string> tmp;
                tmp.push_back(strs[i]);
                ans.push_back(tmp);
            }else{
                ans[pos].push_back(strs[i]);
            }
        }
        return ans;*/
		
		//使用map保存后，遍历复杂度降低了
        map<string, vector<string>> m;
        for(int i=0; i<strs.size(); i++){
            string tmp=strs[i];
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(strs[i]);
        }
        for(map<string, vector<string>>::iterator iter=m.begin(); iter!=m.end(); iter++){
            ans.push_back(iter->second);
        }
        return ans;
    }
};