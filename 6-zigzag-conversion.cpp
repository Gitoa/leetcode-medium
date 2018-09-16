struct node{
	char val;
	int x, y;
};
bool comp(node a, node b){
	if(a.y<b.y){
		return true;
	}else{
		
}
class Solution {
public:
    string convert(string s, int numRows) {
        vector<node>v;
        int tmpX=0, tmpY=0;
        for(int i=0; i<s.length(); i++){
        	node tmp = new node;
        	tmp.val = s[i];
        	tmp.x = tmpX;
        	tmp.y = tmpY;
        	if(tmpX%(numRows-1)==0){
        		tmpY++;
        	}else{
        		tmpX++;
        		tmpY=numRows - (tmpX%(numRows-1));
        	}
        }
        
    }
};
