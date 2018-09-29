class Solution {
private:
	vector<vector<int>> ret;
public:
	void permu(vector<int>next_permu, vector<int>res){
		if(res.size()==0){
			ret.push_back(next_permu);
		}else{
			for(int i=0; i<res.size(); i++){
				int tmp=res[i];
                next_permu.push_back(res[i]);
                res.erase(res.begin()+i);
                permu(next_permu, res);
                res.insert(res.begin()+i, tmp);
                next_permu.erase(next_permu.end()-1);
			}
		}
		
	}
	void perm(vector<int>&nums, int k, int m){
		if(k==m-1){
			ret.push_back(nums);
		}
		else{
			for(int i=k; i<m; i++){
				swap(nums[k], nums[i]);
				perm(nums, k+1, m);
				swap(nums[k], nums[i]);
			}
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return ans;
        /*�Լ����õݹ�ķ�ʽʵ��ȫ���У���һ��������ȫ����ǰ��������ɵ����飬�ڶ���������ʣ�µ�����ɵ�����
		�������Ǳ���ʣ�����飬��ʣ������Ϊ�㣬��Ϊһ���µ�ȫ���У�����������������鲢��ʣ��������ɾ���������жϡ� 
		vector<int> next_permu;
        permu(next_permu, nums);
        return ret;
        
        
        ���Ͽ���������һ��������ʽ�ĵݹ飬 ����dfsʵ�֣����� 
		*/
    }
};
