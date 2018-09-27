class Solution {
public:
    string add(string num1, string num2){
        string s1=num1;
        string s2=num2;
        string ans;
        int carry=0;
        int i;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        for(i=0; i<s1.length()&&i<s2.length(); i++){
            int tmp=s1[i]-'0'+s2[i]-'0'+carry;
            carry = tmp/10;
            tmp %= 10;
            ans.push_back('0'+tmp);
        }
        while(i<s1.length()){
            int tmp = s1[i]-'0'+carry;
            carry=tmp/10;
            tmp%=10;
            ans.push_back('0'+tmp);
            i++;
        }
        while(i<s2.length()){
            int tmp = s2[i]-'0'+carry;
            carry=tmp/10;
            tmp%=10;
            ans.push_back('0'+tmp);
            i++;
        }
        if(carry>0){
            ans.push_back('0'+carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string multiplyInt(string num, int n){
        string s=num;
        string ans;
        int carry=0;
        reverse(s.begin(), s.end());
        for(int i=0; i<s.length(); i++){
            int tmp=n*(s[i]-'0')+carry;
            carry=tmp/10;
            tmp%=10;
            ans.push_back('0'+tmp);
        }
        if(carry>0){
            ans.push_back('0'+carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0"){
            return "0";
        }
        string sum="0";
        string carry="";
        if(num2.length()>num1.length()){
            swap(num1, num2);
        }
        int len=num2.length();
        for(int i=0; i<len; i++){
            string tmp = multiplyInt(num1, num2[len-1-i]-'0');
            tmp+=carry;
            sum = add(sum, tmp);
            carry+="0";
        }
        return sum;
    }
};