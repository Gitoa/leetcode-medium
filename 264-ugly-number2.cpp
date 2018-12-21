class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyArr{1};
        int th2 = 0, th3 = 0, th5 = 0;
        while(--n){
            uglyArr.push_back(min(uglyArr[th2]*2, min(uglyArr[th3]*3, uglyArr[th5]*5)));
            while(uglyArr[th2]*2<=uglyArr.back()) th2++;
            while(uglyArr[th3]*3<=uglyArr.back()) th3++;
            while(uglyArr[th5]*5<=uglyArr.back()) th5++;
        }
        return uglyArr.back();
    }
};