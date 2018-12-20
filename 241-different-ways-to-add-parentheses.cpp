class Solution {
public:
    vector<vector<int>> diffRePolish;
    void  createPolish(vector<int> input, int pos, stack<int> s, vector<int> output){
        if(pos == input.size()){
            while(!s.empty()){
                output.push_back(s.top());
                s.pop();
            }
            diffRePolish.push_back(output);
            return;
        }
        int current = input[pos];
        if(current>=0){
            output.push_back(current);
            createPolish(input, pos+1, s, output);
        }else{
            if(s.empty()){
                s.push(current);
                createPolish(input, pos+1, s, output);
            }else{
                stack<int> sTmp=s;
                while(!s.empty()){
                    sTmp = s;
                    sTmp.push(current);
                    createPolish(input, pos+1, sTmp, output);
                    output.push_back(s.top());
                    s.pop();
                }
                sTmp = s;
                sTmp.push(current);
                createPolish(input, pos+1, sTmp, output);
            }
        }
    }
    int calRePolish(vector<int> input){
        stack<int> sAns;
        for(int i=0; i<input.size(); i++){
            if(input[i]>=0){
                sAns.push(input[i]);
            }else{
                int num1 = sAns.top();
                sAns.pop();
                int num2 = sAns.top();
                sAns.pop();
                switch(input[i]){
                    case -1:
                        sAns.push(num1+num2);
                        break;
                    case -2:
                        sAns.push(num2-num1);
                        break;
                    case -3:
                        sAns.push(num1*num2);
                        break;
                    default:
                        break;
                }
            }
        }
        return sAns.top();
    }
    int toInt(string str){
        int ans = 0;
        for(int i=0; i<str.size(); i++){
            ans *= 10;
            ans += str[i] - '0';
        }
        return ans;
    }
    bool isNum(char s){
        if('0'<=s && s<='9'){
            return true;
        }
        return false;
    }
    vector<int> diffWaysToCompute(string input) {
        int left = 0, right = 0;
        vector<int> intInput;
        vector<int> output;
        stack<int> s;
        vector<int> ans;
        while(right<input.size()){
            if(isNum(input[right])){
                right ++;
            }else{
                string str = input.substr(left, right-left);
                intInput.push_back(toInt(str));
                if(input[right] == '+'){
                    intInput.push_back(-1);
                }else if(input[right] == '-'){
                    intInput.push_back(-2);
                }else if(input[right] == '*'){
                    intInput.push_back(-3);
                }else{
                    intInput.push_back(-4);
                }
                left = right + 1;
                right = left;
            }
        }
        intInput.push_back(toInt(input.substr(left, right-left)));
        createPolish(intInput, 0, s, output);
        for(int i=0; i<diffRePolish.size(); i++){
            ans.push_back(calRePolish(diffRePolish[i]));
        }
        return ans;
    }
};