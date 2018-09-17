#include<iostream>
#include<string>
using namespace std;
int cmp(string s1, string s2){
		//s1<s2 return -1; s1>s2 return 1; s1==s2 reutrn 0;
		if(s1.length()<s2.lenght()){
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
        while(i<len && str[i]==' '){
        	i++;
        }
        if(str[i]<='9' && str[i] >= '0'){
        	pos1 = i;
        	while(i<len && str[i]<='9' && str[i]>='0'){
        		i++;
        	}
        	pos2 = i;
        }else if(str[i]=='-'){
        	flagNegative = true;
        	i++;
        	pos1 = i;
        	while(i<len && str[i]<='9' && str[i]>='0'){
        		i++;
        	}
        	pos2 = i;
        }else if(str[i]=='+'){
        	i++;
        	pos1 = i;
        	while(i<len && str[i]<='9' && str[i]>='0'){
        		i++;
        	}
        	pos2 = i;
        }else{
        	return 0;
        }
		if(pos2==pos1){
			return 0;
		}
		ans = str.substr(pos1, pos2);
		int compare = cmp(ans, string("2147483648"));
		if(compare>=0){
			ans = "2147483648";
		}
		int intAns = 0;
		for(int i=0; i<ans.length(); i++){
			intAns *= 10;
			intAns += ans[i];
		}
		if(flagNegative){
			intAns = -intAns;
		}
		return intAns;		
    }
/*class Solution {
public:
	const int cmp(string s1, string s2){
		//s1<s2 return -1; s1>s2 return 1; s1==s2 reutrn 0;
		if(s1.length()<s2.lenght()){
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
        while(i<len && str[i]==' '){
        	i++;
        }
        if(str[i]<='9' && str[i] >= '0'){
        	pos1 = i;
        	while(i<len && str[i]<='9' && str[i]>='0'){
        		i++;
        	}
        	pos2 = i;
        }else if(str[i]=='-'){
        	flagNegative = true;
        	i++;
        	pos1 = i;
        	while(i<len && str[i]<='9' && str[i]>='0'){
        		i++;
        	}
        	pos2 = i;
        }else if(str[i]=='+'){
        	i++;
        	pos1 = i;
        	while(i<len && str[i]<='9' && str[i]>='0'){
        		i++;
        	}
        	pos2 = i;
        }else{
        	return 0;
        }
		if(pos2==pos1){
			return 0;
		}
		ans = str.substr(pos1, pos2);
		int compare = cmp(ans, string("2147483648"));
		if(compare>=0){
			ans = "2147483648";
		}
		int intAns = 0;
		for(int i=0; i<ans.length(); i++){
			intAns *= 10;
			intAns += ans[i];
		}
		if(flagNegative){
			intAns = -intAns;
		}
		return intAns;		
    }
};*/
int main(){
	string str;
	while(cin >> str){
		int ans = myAtoi(str);
		cout << ans << endl;
	}
	return 0;
}
	 
