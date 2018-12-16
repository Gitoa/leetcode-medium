class Solution {
public:
    int toNumber(string str){
        int ans = 0;
        for(int i=0, len=str.size(); i<len; i++){
            ans *= 10;
            ans += str[i] - '0';
        }
        return ans;
    }
    bool isNumber(char s){
        if('0'<=s && s<='9'){
            return true;
        }
        return false;
    }
    int calculate(string s) {
        stack<int> st;
        stack<int> sOperator;
        string str;
        int left=0, right=0, len=s.size();
        while(s[left]==' '){
            left++;
        }
        right = left;
        while(right<len){
            if(isNumber(s[right])){
                right++;
            }else{
                if(s[right]==' '){
                    str = s.substr(left, right-left);
                    st.push(toNumber(str));
                }else if(s[right]=='+'){
                    str = s.substr(left, right-left);
                    if(str.size()!=0){
                        st.push(toNumber(str));
                    }
                    if(sOperator.empty()){
                        sOperator.push(-4);
                    }else{
                        while(!sOperator.empty()){
                            st.push(sOperator.top());
                            sOperator.pop();
                        }
                        sOperator.push(-4);
                    }
                        
                }else if(s[right]=='-'){
                    str = s.substr(left, right-left);
                    if(str.size()!=0){
                        st.push(toNumber(str));
                    }
                    if(sOperator.empty()){
                        sOperator.push(-3);
                    }else{
                        while(!sOperator.empty()){
                            st.push(sOperator.top());
                            sOperator.pop();
                        }
                        sOperator.push(-3);
                    }
                }else if(s[right]=='*'){
                    str = s.substr(left, right-left);
                    if(str.size()!=0){
                        st.push(toNumber(str));
                    }
                    if(sOperator.empty() || sOperator.top()<-2){
                        sOperator.push(-2);
                    }else{
                        while(!sOperator.empty() && sOperator.top()>=-2){
                            st.push(sOperator.top());
                            sOperator.pop();
                        }
                        sOperator.push(-2);
                    }
                }else if(s[right]=='/'){
                    str = s.substr(left, right-left);
                    if(str.size()!=0){
                        st.push(toNumber(str));
                    }
                    if(sOperator.empty() || sOperator.top()<-2){
                        sOperator.push(-1);
                    }else{
                        while(!sOperator.empty() && sOperator.top()>=-2){
                            st.push(sOperator.top());
                            sOperator.pop();
                        }
                        sOperator.push(-1);
                    }
                }
                left = right + 1;
                while(left<len && s[left]==' '){
                    left ++;
                }
                right = left;
            }
        }
        if(left != len){
            st.push(toNumber(s.substr(left, right-left)));
        }
        while(!sOperator.empty()){
            st.push(sOperator.top());
            sOperator.pop();
        }
        vector<int> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        stack<int> ans;
        for(int i=0; i<v.size(); i++){
            if(v[i]>=0){
                ans.push(v[i]);
            }else{
                int num1 = ans.top();
                ans.pop();
                int num2 = ans.top();
                ans.pop();
                switch(v[i]){
                    case -4:
                        ans.push(num1+num2);
                        break;
                    case -3:
                        ans.push(num2-num1);
                        break;
                    case -2:
                        ans.push(num2*num1);
                        break;
                    case -1:
                        ans.push(num2/num1);
                        break;
                    default:
                        break;
                }
            }
        }
        return ans.top();
    }
};