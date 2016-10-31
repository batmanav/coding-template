
/*
Author : lifecodemohit
Problem : http://www.spoj.com/problems/DQUERY/
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll 					long long int
#define MOD 				1000000007
#define sn(n) 				scanf("%lld",&n)
#define pn(n) 				printf("%lld\n",n)
#define ss(str) 			scanf("%s",str)
#define ps(str) 			printf("%s\n",str)
#define rep(i,s,e) 			for(i=s;i<=e;i++)
#define reprev(i,s,e) 		for(i=s;i>=e;i--)
#define reps(b,e,g,str) 	for(b=str,e=&str[g-1];b<=e;b++) 
#define mem(arr,val) 		memset(arr,val,sizeof(arr))
#define dis(arr,s,e) 		for(i=s;i<=e;i++) printf("%lld ",arr[i]); printf("\n"); 

ll cnt[1000010],ans=0,res[200010],a[30010];

struct sort_struct
{
	ll x;ll y;ll z;ll b_no;
};

struct by_bno
{
	bool operator()(const sort_struct &a, const sort_struct &b)
	{
		if(a.b_no==b.b_no)
			return a.z<b.z;
		return a.b_no<b.b_no;
	}
};

void rem(ll pos)
{
	if(cnt[a[pos]]==1)
		ans--;
	cnt[a[pos]]--;
}

void add(ll pos)
{
	if(cnt[a[pos]]==0)
		ans++;
	cnt[a[pos]]++;
}

int main()
{
	mem(cnt,0);
	ll n,i,j,q;
	sn(n);
	rep(i,0,n-1)
		sn(a[i]);
	vector<sort_struct> v1;
	sn(q);
	rep(j,0,q-1)
	{
		sort_struct s;
		sn(s.y);
		sn(s.z);
		s.x=j;
		s.b_no=(s.y/sqrt(n));
		v1.push_back(s);
	}
	sort(v1.begin(),v1.end(),by_bno());
	size_t k;
	ll curL=0,curR=0,L,R;
	add(0);
	rep(k,0,v1.size()-1)
	{
		L=v1[k].y-1;
		R=v1[k].z-1;
		//printf("%lld %lld\n",L,R);
		while(curL<L)
		{
			rem(curL);
			curL++;
		}
		while((curL-1)>=L)
		{
			curL--;
			add(curL);
		}
		while((curR+1)<=R)
		{
			curR++;
			add(curR);
		}
		while(curR>R)
		{
			rem(curR);
			curR--;
		}
		res[v1[k].x]=ans;
		/*rep(i,1,3)
			printf("%lld,",cnt[i]);
		printf("\n");
		printf("%lld\n",ans);*/
	}
	rep(j,0,q-1)
		pn(res[j]);
	return 0;
}