class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        for(vector<int>::iterator iter=nums.begin(); iter!=nums.end(); iter++){
            v.push_back(*iter);
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
			int j=i+1, k=v.size()-1;
			while(j<k){
				if(v[i]+v[j]+v[k]==0){
					vector<int> tmp;
					tmp.push_back(v[i]);
					tmp.push_back(v[j]);
					tmp.push_back(v[k]);
					ans.push_back(tmp);
					j++;
					k--;	
                    while(j<v.size()&&v[j]==v[j-1]){
					    j++;
				    }
				    while(k>i&&v[k]==v[k+1]){
				    	k--;
				    }	
				}else if(v[i]+v[j]+v[k]>0){
					k--;	
                    while(k>i&&v[k]==v[k+1]){
					    k--;
			    	}	
				}else{
					j++;
                    while(j<v.size()&&v[j]==v[j-1]){
					    j++;
				    }
				}				
			}
            while(i+1<v.size()&&v[i]==v[i+1]){
                i++;
            }
        }
        return ans;
    }
};
