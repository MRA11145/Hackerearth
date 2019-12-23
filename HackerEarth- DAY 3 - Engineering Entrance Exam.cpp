#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// #define ll double
#define pb push_back
#define mk make_pair
#define pr pair<ll,ll>
#define S second
#define F first
#define in insert
const ll INF = INT64_MAX;
const int inf = INT_MAX;
const int SIZE = 1e6+1;
int prime[SIZE];
void seive()
{
	memset(prime,true,sizeof(prime));
	prime[1]=false;
	prime[2]=true;
	for(int p=2;p*p<SIZE;p++)
	{
		if(prime[p])
		{
			for(int i=p*p;i<SIZE;i+=p)
				prime[i]=false;
		}
	}
}
ll min(ll a, ll b)
{
	if( a < b)
		return a;
	return b;
}
ll max(ll a,ll b)
{
	if( a > b)
		return a;
	return b;
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	ll n,M,k,q;
	cin >> n >> M >> k >> q;
	vector<pair<int,int>>v[n+1];
	int x,y,w;
	for(int i=0;i<M;i++)
	{
		cin >> x >> y >> w;
		v[x].pb({y,w});
		v[y].pb({x,w});
	}
	vector<int>dis(n+1,inf);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>s;
	for(int i=0;i<k;i++)
	{
		cin >> x;
		s.push({0,x});
		dis[x]=0;
	}
// 	priority_queue<pair<int,int>>::iterator it;
vector<bool>isvisited(n+1,false);
	while(s.size())
	{
		pair<int,int>temp=s.top();
		s.pop();
		int cost=temp.F;
		y=temp.S;
		if(isvisited[y])
			continue;
			
		isvisited[y]=true;
		else
		{
			for(auto i:v[y])
			{
				if(dis[i.F] > dis[y]+cost)
				{
					dis[i.F]=dis[y]+cost;
					s.push({dis[i.F],i.F});

				}
			}
		}

	}
	for(int i=0;i<q;i++)
	{
		cin >> x;
		if(x==inf)
			cout << -1<<endl;
		else
			cout << dis[x]<<endl;
	}


}
