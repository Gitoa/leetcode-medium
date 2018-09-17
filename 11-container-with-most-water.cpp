class Solution {
public:
    struct node{
	    int x, y;
    };
    static bool cmp(node a, node b){
       return a.y>b.y;
    }
    int maxArea(vector<int>& height) {//�Ż����£�����󰴸߶Ƚ��в�������λ���ڼ�¼�����ڣ�����Ҫ����Ҳ����Ҫ�������飬�������Լ��ٲ��ֱȽϣ������Խ�һ���Ż�������������¼���飬���������Ҳ�ıȽ� 
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
