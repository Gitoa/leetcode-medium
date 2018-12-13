class Solution {
public:
    vector<bool> flag;
    vector<int> in;
    vector<vector<int>> G;
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        int courseNum=0;
        flag = vector<bool>(numCourses, false);
        in = vector<int>(numCourses, 0);
        G = vector<vector<int>> (numCourses, vector<int>(0));
        for(int i=0; i<prerequisites.size(); i++){
            int fir = prerequisites[i].first;
            int sec = prerequisites[i].second;
            G[sec].push_back(fir);
            in[fir] ++;
        }
        for(int i=0; i<numCourses; i++){
            if(!flag[i] && in[i]==0){
                queue<int> q;
                flag[i] = true;
                q.push(i);
                courseNum++;
                while(!q.empty()){
                    int currentCourse = q.front();
                    ans.push_back(currentCourse);
                    q.pop();
                    vector<int> nextCourses = G[currentCourse];
                    for(int j=0; j<nextCourses.size(); j++){
                        int nextCourse = nextCourses[j];
                        in[nextCourse]--;
                        if(in[nextCourse]==0){
                            q.push(nextCourse);
                            courseNum++;
                            flag[nextCourse] = true;
                        }
                    }
                }
            }
        }
        if(courseNum!=numCourses){
            return vector<int>(0);
        }
        return ans;
    }
};