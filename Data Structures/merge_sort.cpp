/*
author : lifecodemohit
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void merge(ll r[],ll c[],ll l,ll mid,ll ri)
{
	ll i,j,k,temp1[ri-l+1],temp2[ri-l+1];
	for(i=l,j=mid+1,k=0;i<=mid&&j<=ri;k++)
	{
		if(r[i]<=r[j])
		{
			temp1[k]=r[i];
			temp2[k]=c[i];
			i++;
		}
		else
		{
			temp1[k]=r[j];
			temp2[k]=c[j];
			j++;
		}
	}
	if(i<=mid)
	{
		while(i<=mid)
		{
			temp1[k]=r[i];
			temp2[k]=c[i];
			i++;
			k++;
		}
	}
	if(j<=ri)
	{
		while(j<=ri)
		{
			temp1[k]=r[j];
			temp2[k]=c[j];
			j++;
			k++;
		}
	}
	for(i=l,j=0;i<=ri;i++,j++)
	{
		r[i]=temp1[j];
		c[i]=temp2[j];
	}
}
void msort(ll r[],ll c[],ll l,ll ri)
{
	ll mid;
	if(l<ri)
	{
		mid=(l+ri)/2;
		msort(r,c,l,mid);
		msort(r,c,mid+1,ri);
		merge(r,c,l,mid,ri);
	}
}
int main()
{
	ll n,i;
	scanf("%lld",&n);
	ll a[n],b[n];
	for(i=0;i<=n-1;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
	}
	msort(a,b,0,n-1);
	for(i=0;i<=n-1;i++)
	{
		printf("%lld   %lld\n",a[i],b[i]);  // Sort array a and rearrange b w.r.t a
	}
	return 0;
}