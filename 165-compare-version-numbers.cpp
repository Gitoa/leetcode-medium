class Solution {
public:
    int toNum(string s){
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }
    int compareVersion(string version1, string version2) {
        int left1 = 0, right1 = 0;
        int left2 = 0, right2 = 0;
        while(left1 < version1.size() && left2 < version2.size()){
            right1 = left1;
            for(; right1<version1.size(); right1++){
                if(version1[right1] == '.'){
                    break;
                }
            }
            string strNum1 = version1.substr(left1, right1-left1);
            int num1 = toNum(strNum1);
            right2 = left2;
            for(; right2<version2.size(); right2++){
                if(version2[right2] == '.'){
                    break;
                }
            }
            string strNum2 = version2.substr(left2, right2-left2);
            int num2 = toNum(strNum2);
            if(num1>num2){
                return 1;
            }else if(num1<num2){
                return -1;
            }
            left1 = right1 + 1;
            left2 = right2 + 1;
        }
        if(right1 == version1.size() && right2 == version2.size()){
            return 0;
        }
        if(right1 == version1.size()){
            while(left2 < version2.size()){
                right2 = left2;
                for(; right2<version2.size(); right2++){
                    if(version2[right2] == '.'){
                        break;
                    }
                }
                string strNum2 = version2.substr(left2, right2-left2);
                int num2 = toNum(strNum2);
                if(num2!=0){
                    return -1;
                }
                left2 = right2 + 1;
            }
            return 0;
        }
        if(right2 == version2.size()){
            while(left1 < version1.size()){
                right1 = left1;
                for(; right1<version1.size(); right1++){
                    if(version1[right1] == '.'){
                        break;
                    }
                }
                string strNum1 = version1.substr(left1, right1-left1);
                int num1 = toNum(strNum1);
                if(num1!=0){
                    return 1;
                }
                left1 = right1 + 1;
            }
            return 0;
        }
    }
};