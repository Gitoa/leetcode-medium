class Solution {
public:
  const int cmp(string s1, string s2){
		//s1<s2 return -1; s1>s2 return 1; s1==s2 reutrn 0;
		if(s1.length()<s2.length()){
			return -1;
		}else if(s1.length()>s2.length()){
			return 1;
		}else{
			for(int i=0; i<s1.length(); i++){
				if(s1[i]>s2[i]){
					return 1;
				}else if(s1[i]<s2[i]){
					return -1;
				}
			}
		}
		return 0;
	}
    int myAtoi(string str) {
        int i=0, len=str.length();
        int pos1=0, pos2=0;
        string ans;
        bool flagNegative = false;
        bool zeroBefore = false;
        while(i<len && ((str[i]==' '||str[i]=='0'))){
        	if(str[i]=='0'){
        		zeroBefore = true;
        	}else if(str[i]==' ' && zeroBefore){
        		cout<<"here"<<endl;
        		return 0;
        	}
        	i++;
        }
        if(i==len){
            return 0;
        }
        if(str[i]<='9' && str[i] >= '0'){
        	pos1 = i;
        	while(i+1<len && str[i+1]<='9' && str[i+1]>='0'){
        		i++;
        	}
        	pos2 = i;
        }else if(str[i]=='-'){
        	if(zeroBefore){
        		return 0;
        	}
        	flagNegative = true;
        	i++;
            while(i<len&&str[i]=='0'){
                i++;
            }
            if(i<len&&(str[i]>'9'||str[i]<'0')){
            	return 0;
            }
            pos1=i;
        	while(i<len && str[i+1]<='9' && str[i+1]>='0'){
        		i++;
        	}
        	pos2 = i;
        }else if(str[i]=='+'){
        	if(zeroBefore){
        		return 0;
        	}
        	i++;
            while(i<len && str[i]=='0'){
                i++;
            }
            if(i<len&&(str[i]>'9'||str[i]<'0')){
            	return 0;
            }
            pos1 = i;
        	while(i<len && str[i+1]<='9' && str[i+1]>='0'){
        		i++;
        	}
        	pos2 = i;
        }else{
        	return 0;
        }     		
		ans = str.substr(pos1, pos2-pos1+1);
		int intAns = 0;
		if(flagNegative){
			int compare = cmp(ans, string("2147483648"));
			if(compare>=0){
				ans = "2147483648";
			}
			for(int i=0; i<ans.length(); i++){
				intAns *= 10;
				intAns += ans[i]-'0';
			}
			intAns = -intAns;
		}else{
			int compare = cmp(ans, string("2147483647"));
			if(compare>=0){
				ans = "2147483647";
			}
			for(int i=0; i<ans.length(); i++){
				intAns *= 10;
				intAns += ans[i]-'0';
			}
		}
		cout<<pos2<<" "<<pos1<<endl;
		cout<<ans<<endl;//"0  123"
		return intAns;		
    }
};
