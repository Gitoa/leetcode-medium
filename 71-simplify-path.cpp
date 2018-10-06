class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        while(path[1]=='/' && 1<path.size()){
            path.erase(1, 1);
        }
        int end=path.find("/", 1);
        int begin=0;
        while(end!=string::npos){
            string str=path.substr(begin+1, end-begin-1);
            if(str!="."){
                if(str==".."){
                    if(ans.size()!=0){
                        int pos=ans.rfind("/");
                        ans.erase(pos);
                    }
                }else{
                    ans += ("/"+str);
                }
            }
            begin=end;
            while((begin+1<path.size()) && (path[begin+1]=='/')){
                begin++;
            }
            if(begin+1==path.size()){
                break;
            }
            end=path.find("/", begin+1);
        }
        if(begin+1!=path.size()){
            string str=path.substr(begin+1);
            if(str!="."){
                if(str==".."){
                    if(ans.size()!=0){
                        int pos=ans.rfind("/");
                        ans.erase(pos);
                    }
                }else{
                    ans += ("/"+str);
                }
            }
        }
        if(ans.size()==0){
            ans = "/";
        }
        return ans;
    }
};