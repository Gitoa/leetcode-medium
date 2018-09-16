class Solution {
public:
   	struct node{
		char val;
		int x, y;
	};
	static bool comp(node a, node b){
		if(a.y<b.y){
			return true;
		}else if(a.y == b.y){
			if(a.x < b.x){
				return true;
			}else{
				return false;
			}
		}
		return false;
	}
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        vector<node>v;
        string str;
        int tmpX=0, tmpY=0;
        for(int i=0; i<s.length(); i++){
        	node tmp;
        	tmp.val = s[i];
        	tmp.x = tmpX;
        	tmp.y = tmpY;
        	v.push_back(tmp);
        	if(tmpX%(numRows-1)==0){
        		tmpY++;
        		if(tmpY==numRows){
        			tmpY = numRows - 2;
        			tmpX++;
        		}
        	}else{
        		tmpX++;
        		tmpY--;
        	}
        }
        sort(v.begin(), v.end(), comp);
        for(vector<node>::iterator iter=v.begin(); iter!=v.end(); iter++){
        	str.push_back(iter->val);
        }
        return str;
    }
};
