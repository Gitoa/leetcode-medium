class Solution {
public:
    struct node{
        int x, y;
        node(int x, int y):x(x), y(y){}
    };
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for(int i=0; i<n ;i++){
            vector<int> tmp(n);
            ans.push_back(tmp);
        }
        node a(0, 0);
        node b(n-1, 0);
        node c(n-1, n-1);
        node d(0, n-1);
        int start=1;
        while(a.x<=b.x){
            int x, y;
            y=a.y;
            for(x=a.x; x<=b.x; x++){
                ans[y][x]=start++;
            }
            y=b.y+1;
            x=b.x;
            for(;y<=c.y; y++){
                ans[y][x]=start++;
            }
            y=c.y;
            x=c.x-1;
            for(; x>=d.x; x--){
                ans[y][x]=start++;
            }
            y=d.y-1;
            x=d.x;
            for(; y>a.y; y--){
                ans[y][x]=start++;
            }
            a.x++;
            a.y++;
            b.x--;
            b.y++;
            c.x--;
            c.y--;
            d.x++;
            d.y--;
        }
        return ans;
    }
};