#include<iostream>
#include<string>
#include<vector>
using namespace std;
string intToRoman(int num) {
    string str;
    vector<string>v;
    string tmp = "0IVXLCDM";   
    int M, D, C, L, X, V, I;
    M = num/1000;
    num%=1000;
    D = num/500;
    num%=500;
    C = num/100;
    num%=100;
    L = num/50;
    num%=50;
    X = num/10;
    num%=10;
    V = num/5;
    num%=5;
    I = num;
    if(I==4){
        if(V==0){
            str.insert(0, "IV");
        }else if(V==1){
            str.insert(0, "IX"); 
            V--;
        }
    }else{
        while(I--){
            str.insert(0,"I");
        }
    }
    while(V--){
        str.insert(0, "V");
    }
    if(X==4){
        if(L==0){
            str.insert(0, "XL");
        }else if(L==1){
            str.insert(0, "XC");
            L--;
        }
    }else{
        while(X--){
            str.insert(0, "X");
        }
    }
    while(L--){
        str.insert(0, "L");
    }
    if(C==4){
        if(D==0){
            str.insert(0, "CD");
        }else if(D==1){
            str.insert(0, "CM");
            D--;
        }
    }else{
        while(C--){
            str.insert(0, "C");
        }
    }
    while(D--){
        str.insert(0, "D");
    }
    while(M--){
        str.insert(0, "M");
    }
    return str;
}
int main(){
    int n;
    while(cin >> n){
    	string ans = intToRoman(n);
   	 	cout << ans;
   	 }
    return 0;
}

