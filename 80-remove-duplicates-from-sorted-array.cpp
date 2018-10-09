class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=0;
        vector<int>::iterator fir, sec;
        fir = nums.begin();
        if(fir == nums.end()){
            return len;
        }
        sec = nums.begin()+1;
        len = 1;
        while(sec != nums.end()){
            cout<<*fir<<" "<<*sec<<endl;
            if(*sec == *fir){
                len++;
                while(sec+1 != nums.end()){
                    if(*(sec+1) == *fir){
                        *nums.erase(sec+1);
                    }else{
                        break;
                    }
                }
                if(sec+1 == nums.end()){
                    break;
                }else{
                    len++;
                    fir = sec+1;
                    sec = fir+1;
                }
            }else{
                len++;
                fir = sec;
                sec = sec + 1;
            }
        }
        return len;
    }
};