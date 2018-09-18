class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        for(vector<int>::iterator iter=nums.begin(); iter!=nums.end(); iter++){
            v.push_back(*iter);
        }
        sort(v.begin(), v.end());
        vector<int> apper;
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout << endl;
        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                int f = -v[i]-v[j];
                int k;
                for(k=v.size()-1; k>=0; k--){
                    if(v[k]==f||k<=j){
                        break;
                    }
                }
                cout<<i<<" " <<j<<" "<<k<<endl;
                if(k>j){
                    vector<int>tmp;
                    tmp.push_back(v[i]);
                    tmp.push_back(v[j]);
                    tmp.push_back(-v[i]-v[j]);
                    sort(tmp.begin(), tmp.end());
                    ans.push_back(tmp);
                }
                while(j+1<v.size()&&v[j]==v[j+1]){
                    j++;
                }
            }
            while(i+1<v.size()&&v[i]==v[i+1]){
                i++;
            }
        }
        return ans;
    }
};