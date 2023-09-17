#include<iostream>
using namespace std;
int min_to_1(int n){
	//base case
	if(n==1){
		return 0;
	}
	//recursive case
	int opt1,opt2,opt3;
	opt1=opt2=opt3=INT_MAX;
	opt3=min_to_1(n-1);
	if(n%3==0){
		opt1=min_to_1(n/3);
	}
	if(n%2==0){
		opt2=min_to_1(n/2);
	}
	return min(opt1,min(opt2,opt3))+1;
}


int topdown_min_to_1(int n,int *dp){
	//base case
	if(n==1){
		return dp[n]=0;
	}
	//calculate karne se phele check
	if(dp[n]!=-1){
		return dp[n];
	}
	//recursive case
	int opt1,opt2,opt3;
	opt1=opt2=opt3=INT_MAX;
	opt3=topdown_min_to_1(n-1,dp);
	if(n%3==0){
		opt1=topdown_min_to_1(n/3,dp);
	}
	if(n%2==0){
		opt2=topdown_min_to_1(n/2,dp);
	}
	//return larne se phele store
	return dp[n]=min(opt1,min(opt2,opt3))+1;
}

int bottom_up(int n){
	int *dp=new int[n+1];
	dp[1]=0;
	int op1,op2,op3;
	for(int i=0;i<=n;i++){
		op1=op2=op3=INT_MAX;
		op1=dp[i-1];
		if(n%2==0){
			op2=dp[i/2];
		}
		if(n%3==0){
			op3=dp[i/3];
		}
		dp[i]=min(op1,min(op2,op3))+1;
	}
	for(int i=1;i<=n;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	return dp[n];
} 


int main(){
	int n;
	cin>>n;
	cout<<min_to_1(n)<<endl;
	int*dp=new int[n+1];
	for (int i=0;i<=n;i++)
	{
		dp[i]=-1;
	}
	cout<<topdown_min_to_1(n,dp)<<endl;
	cout<<bottom_up(n)<<endl;
	return 0;
}