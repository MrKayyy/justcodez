#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back

void dfs(ll u,vector<ll> adj[],ll processed[],vector<ll> &top,ll &cycle)
{
    if(processed[u]==2)
    return;
    if(processed[u]==1)
    {
    cycle++;
    return;
    }
    processed[u]=1;
    for(auto e:adj[u])
    {
        dfs(e,adj,processed,top,cycle);
    }
    processed[u]=2;
    top.pb(u);
    
}

void topsort(vector<ll> adj[],ll n)
{
    ll i;
    ll processed[n+1];
    for(i=1;i<=n;i++)
    processed[i]=0;
    ll cycle=0;
    vector <ll> top;
    for(i=1;i<=n;i++)
    {
        if(processed[i]!=2)
        dfs(i,adj,processed,top,cycle);
    }
    if(cycle!=0)
    cout<<"Cycle found";
    else
    {
        for(i=top.size()-1;i>=0;i--)
        cout<<top[i]<<" ";
    }
    
}
int main()
{
	ll n;
	ll t;
	cin>>n>>t;
	vector <ll> adj[n+1];
    ll i;
    ll u,v;
    for(i=0;i<t;i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
    }
    
   topsort(adj,n);
    
    return 0;
}
