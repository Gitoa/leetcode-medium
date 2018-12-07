class Solution {
public:
    int toNum(string s){
        int p = 0;
        int ans=0;
        bool neg = false;
        if(s[0] == '-'){
            p = 1;
            neg = true;
        }
        for(; p<s.size(); p++){
            ans = ans*10 + s[p]-'0';
        }
        if(neg){
            ans = -ans;
        }
        return ans;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        map<string, int>m;
        m["+"]=1;
        m["-"]=2;
        m["/"]=3;
        m["*"]=4;
        for(int i=0; i<tokens.size(); i++){
            string str = tokens[i];
            int ans = m[str];
            int num1, num2;
            switch(ans){
                case 1:
                    num2 = s.top();
                    s.pop();
                    num1 = s.top();
                    s.pop();
                    s.push(num1+num2);
                    break;
                case 2:
                    num2 = s.top();
                    s.pop();
                    num1 = s.top();
                    s.pop();
                    s.push(num1-num2);
                    break;
                case 3:
                    num2 = s.top();
                    s.pop();
                    num1 = s.top();
                    s.pop();
                    s.push(num1/num2);
                    break;
                case 4:
                    num2 = s.top();
                    s.pop();
                    num1 = s.top();
                    s.pop();
                    s.push(num1*num2);
                    break;
                default:
                    s.push(toNum(str));     
            }
        }
        return s.top();
    }
};