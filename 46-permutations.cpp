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
				
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return ans;
        /*自己采用递归的方式实现全排列，第一个参数是全排列前几个数组成的数组，第二个参数是剩下的数组成的数组
		方法就是遍历剩余数组，若剩余数组为零，则为一个新的全排列，否则将其加入排列数组并从剩余数组中删除，继续判断。 
		vector<int> next_permu;
        permu(next_permu, nums);
        return ret;
		
		还有使用交换方式实现的
		
		
		DFS方式的比较好理解，其实我的方式就是DFS，只是DFS用visited数组标记，我用res数组操作
		*/
    }
};
