class Solution {
private:
    static bool cmp(int a, int b){
        string firA = to_string(a) + to_string(b);
        string firB = to_string(b) + to_string(a);
        return firA > firB;
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans="";
        for(int i=0; i<nums.size(); i++){
            ans += to_string(nums[i]);
        }
        int pos=0;
        while(ans[pos]=='0'&&pos<ans.size()-1){
            pos++;
        }
        return ans.substr(pos, ans.size()-pos);
    }
};