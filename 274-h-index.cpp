class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0){
            return 0;
        }
        int h=0;
        sort(citations.begin(), citations.end());   
        for(int i=citations.size()-1; i>=0; i--){
            if(citations.size() - i > citations[i]){
                h = citations.size() - i;
                break;
            }
            if(i == 0){
                h = citations.size() + 1;
            }
        }
        return h-1;
    }
};