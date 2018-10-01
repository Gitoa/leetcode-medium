class Solution {
public:
    struct node{
        int x, y;
        node(int x, int y):x(x), y(y){}
    };
    vector<int> circle(vector<vector<int>> &matrix, node a, node b, node c, node d){
        vector<int> ans;
        int x=a.x, y=a.y;
        while(x<=b.x){
            ans.push_back(matrix[y][x]);
            x++;
        }
        x=b.x;
        y=b.y+1;
        while(y<=c.y){
            ans.push_back(matrix[y][x]);
            y++;
        }
        x=c.x-1;
        y=c.y;
        while(x>=d.x&&y>b.y){
            ans.push_back(matrix[y][x]);
            x--;
        }
        x=d.x;
        y=d.y-1;
        while(y>a.y&&x<c.x){
            ans.push_back(matrix[y][x]);
            y--;
        }
        return ans;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size();
        if(m==0){
            return ans;
        }
        int n=matrix[0].size();
        if(n==0){
            return ans;
        }
        node a(0, 0);
        node b(n-1, 0);
        node c(n-1, m-1);
        node d(0, m-1);
        while(a.x<=b.x&&a.y<=d.y){
            vector<int> tmp = circle(matrix, a, b, c, d);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
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
