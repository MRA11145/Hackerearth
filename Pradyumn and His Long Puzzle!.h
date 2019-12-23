//https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/pradyumn-and-his-long-puzzle/description/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// #define ll double
#define pb push_back
#define mk make_pair
#define PR pair<ll,ll>
#define pr pair<int,pair<int,int>>
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
	int n,m;
	cin >> n >> m;
	char arr[n][m];
	int dis[n][m];
	bool isvisited[n][m];
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		for(int j=0;j<m;j++)
		{
			arr[i][j]=s[j];
			dis[i][j]=inf;
			isvisited[i][j]=false;
		}
	}
	 int r[]={0,0,1,-1};
    int c[]={1,-1,0,0};

	priority_queue<pr,vector<pr>,greater<pr>>p;
	int x,y;
	cin >> x >> y;
	x--;
	y--;
	dis[x][y]=0;
	int x2,y2;
	cin >> x2 >> y2;
	x2--;
	y2--;
	p.push({0,{x,y}});
	while(p.size())
	{
		pr temp=p.top();
		p.pop();
		int u=temp.S.F;
		int v=temp.S.S;
		if(isvisited[u][v])
			continue;
		isvisited[u][v]=true;
		for(int i=0;i<4;i++)
		{
			if(u+r[i] >=0 && u+r[i]<n && v+c[i] >=0 && v+c[i]<m)
			{
				if(dis[u+r[i]][v+c[i]] > dis[u][v]+abs(arr[u][v]-arr[u+r[i]][v+c[i]]))
				{
					dis[u+r[i]][v+c[i]]=abs(arr[u][v]-arr[u+r[i]][v+c[i]])+dis[u][v];
				    // cout <<dis[u+r[i]][v+c[i]]<<endl;
					p.push({dis[u+r[i]][v+c[i]],{u+r[i],v+c[i]}});
				}


				
			}
			

		}

	}
	if(dis[x2][y2]==inf)
		cout << "Impossible";
	else
		cout <<dis[x2][y2];





}
