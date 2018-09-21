class Solution {
public:
	
    int divide(int dividend, int divisor) {
        if(dividend==-pow(2,31) && divisor==-1){
			return pow(2,31)-1;
		}
		if(dividend==0){
			return 0;
		}
		bool flag=(dividend>0&&divisor>0)||(dividend<0&&divisor<0);
		long long div1=abs((long long)dividend);
		long long div2=abs((long long)divisor);
		int i=0;
		int ans=0;
		while(div1>=div2<<1){
			div2<<=1;
			i++;
		}
		while(i>=0){
            cout<<div2<<endl;
			if(div1>=div2){
				ans+=(1<<i);
				div1-=div2;
			}
			i--;
			div2>>=1;
		}
		return flag?ans:-ans;
    }
};