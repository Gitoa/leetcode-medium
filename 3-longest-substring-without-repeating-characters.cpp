class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int>M;
		int maxLen=0, len=0;
		for(int i=0; i<s.length(); i++){
			if(M.count(s[i])==0){
				M[s[i]]=i;
				len++;
			}else{
				maxLen = max(maxLen, len);
				int del_count=0;
                int pos = M[s[i]];
				for(map<char, int>::iterator iter=M.begin(); iter!=M.end();){
					if(iter->second<=pos){//用iter->second<=M[s[i]],注意到M[s[i]]会被删除
						M.erase(iter++);
						del_count++;
					}else{
						iter++;
					}	
				}
				len=len-del_count+1;
				M[s[i]]=i;
			}
		}
		maxLen = max(maxLen, len);
		return maxLen;
    }
};
