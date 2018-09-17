class Solution {
public:
    struct node{
	    int x, y;
    };
    static bool cmp(node a, node b){
       return a.y>b.y;
    }
    int maxArea(vector<int>& height) {//优化了下，排序后按高度进行操作，若位置在记录数组内，不需要计算也不需要加入数组，这样可以减少部分比较，还可以进一步优化，设置两个记录数组，用于左侧和右侧的比较 
        vector<node>v;
        vector<node>tmp;	
        for(int i=0; i<height.size(); i++){
            node tmp;
            tmp.x = i;
            tmp.y = height[i];
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), cmp);
        tmp.push_back(v[0]);
        tmp.push_back(v[1]);
        int maxX=max(v[0].x, v[1].x);
        int minX=min(v[0].x, v[1].x);
        int maxV=(maxX - minX) * min(v[0].y, v[1].y);
        for(int i=2; i<v.size(); i++){
            int pos = v[i].x;
            int h = v[i].y;
            if(pos<minX){
                minX=pos;
                for(int j=0; j<tmp.size(); j++){
                    maxV = max(maxV, min(h, tmp[j].y)*(tmp[j].x-minX));
                }
                tmp.push_back(v[i]);
            }
            else if(pos>maxX){
                maxX=pos;
                for(int j=0; j<tmp.size(); j++){
                    maxV = max(maxV, min(h, tmp[j].y)*(maxX-tmp[j].x));
                }
                tmp.push_back(v[i]);
            }
        }
        return maxV;
    }
};
