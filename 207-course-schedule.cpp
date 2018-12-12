//很经典的拓扑排序问题
class Solution {
public:
    map<int, vector<int>> out;
    vector<int> color;
    bool flag=false;
    void dfs(int pos){
        if(!flag){
            color[pos] = 0; 
            vector<int> outNode = out[pos];
            for(int i=0; i<outNode.size(); i++){
                if(color[outNode[i]]==-1){
                    dfs(outNode[i]);
                }else if(color[outNode[i]]==0){
                    flag=true;
                    return;
                }
            }
            color[pos] = 1;
        }
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        for(int i=0; i<prerequisites.size(); i++){
            pair<int, int> tmpP = prerequisites[i];
            int fir = tmpP.first, sec = tmpP.second;
            if(out.count(fir)==1){
                out[fir].push_back(sec);
            }else{
                vector<int> tmpOut;
                tmpOut.push_back(sec);
                out[fir] = tmpOut;
            }
        }
        color = vector<int>(numCourses, -1);
        for(int i=0; i<numCourses; i++){
            if(color[i]==-1){
                dfs(i);
            }
        }
        return !flag;
    }
};