class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> edge;
        vector<int> inDegree(n, 0);
        int res = n;
        vector<bool> rest(n, true);
        for(int i=0; i<n; i++){
            vector<int> tmp;
            edge.push_back(tmp);
        }
        for(int i=0; i<edges.size(); i++){
            int fir=edges[i].first, sec=edges[i].second;
            edge[fir].push_back(sec);
            edge[sec].push_back(fir);
            inDegree[fir]++;
            inDegree[sec]++;
        }
        while(res>2){
            vector<int> leaf;
            for(int i=0; i<n; i++){
                if(rest[i] && inDegree[i]==1){
                    leaf.push_back(i);
                }
            }
            for(int i=0; i<leaf.size(); i++){   
                for(int j=0; j<edge[leaf[i]].size(); j++){
                    int next = edge[leaf[i]][j];
                    if(rest[next] && inDegree[next]>1){
                        inDegree[next] --;
                    }
                }
                rest[leaf[i]]=false;
                res--;
            }
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(rest[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};