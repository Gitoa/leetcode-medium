class Solution {
public:
    struct Node{
        string s;
        int val;//number of remain '('
        int remain;//number of '(' not in s
    };
    vector<string> generateParenthesis(int n) {
        vector<Node> node;
        vector<Node> ans;
        vector<string> strAns;
        Node fir;
        fir.s="(";
        fir.val=1;
        fir.remain=n-1;
        node.push_back(fir);
        int remain=n-1;
        ans=node;
        for(int i=1; i<n*2; i++){
            node = ans;
            ans.clear();
            int len = node.size();
            for(int j=0; j<len; j++){
                Node tmp1=node[j];
                if(tmp1.remain>0){
                    tmp1.s+="(";
                    tmp1.val++;
                    tmp1.remain--;
                    ans.push_back(tmp1);
                }
                Node tmp=node[j];
                if(tmp.val>0){
                    tmp.s+=")";
                    tmp.val--;
                    ans.push_back(tmp);
                }
            }
        }
        for(int i=0; i<ans.size(); i++){
            strAns.push_back(ans[i].s);
        }
        return strAns;
    }
};