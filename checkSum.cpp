/*
author :  EnPee;
Date : 01 10 2019  17:09:12;
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define st_clk double st=clock();
#define end_clk double en=clock();
#define show_time cout<<"\tTIME="<<(en-st)/CLOCKS_PER_SEC<<endl;
#define sc(n) scanf("%d",&n)
#define scst(n) scanf("%s",n)
#define Size(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define ms(A) memset(A, 0, sizeof(A))
#define msv(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define found(A, x) (A.find(x) != A.end())
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define PRINTN(n) printf("%d\n",(n))
#define PRINTS(s) printf("%s\n",s)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REVFOR(i, a, n) for(int i = a; i > n; i--)
#define forall(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define DEB(n) cout<<"(<<< DEBUG "<<n<<" >>>)"<<endl;
#define length(x) ( sizeof(x) / sizeof(x[0]) )
int n=8;
string sum(string s1,string s2){
string sum="";
	string extra="";
	
	char carry='0';
	sum+=(s1[n-1]==s2[n-1])?'0':'1';
	carry=(s1[n-1]=='1'&&s2[n-1]=='1')?'1':'0';
	for(int i=n-2;i>=0;i--){
		if(carry=='1')
		sum+=(((s1[i]==s2[i])?'0':'1')==carry)?'0':'1';
		else
		sum+=(s1[i]==s2[i])?'0':'1';
		
		if(carry!='1')carry=(s1[i]=='1'&&s2[i]=='1')?'1':'0';
		else{
			if(s1[i]=='1')
		 carry = (s1[i]=='1'&&carry=='1')?'1':'0';
		else
		carry = (s2[i]=='1'&&carry=='1')?'1':'0';
		}
		
		
	}
	if(carry=='1'){
		int r=0;
		while(sum[r]!='0'){
		sum[r]='0';
		r++;
	}sum[r]='1';
	
		}
		extra = sum;
	return extra;	
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cout<<"enter the data set to send:"<<endl;
    string s;
    getline(cin,s);
    cout<<"enter the fram size:"<<endl;
    int o;
    cin>>o;
    n=o; 
	string check=s.substr(0,n);
    for(int i=n;i<s.size();i+=n){
    check = sum(check,s.substr(i,n));
	reverse(check.begin(),check.end());	
	}
	for(int q=0;q<n;q++){
		check[q]=(check[q]=='1')?'0':'1';
	}
	cout<<"check sum is:"<<endl;
	cout<<check<<endl;
	s=s+check;
	cout<<"Enter the recieved data set:"<<endl;
	string rec;
	getline(cin,rec);
	getline(cin,rec);
	if(rec==s)cout<<"dataset accepted";
	else cout<<"dataset does not match rejected"<<endl;
	
	return 0;
}