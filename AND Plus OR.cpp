/* APPROACH -: BRUTE FORCE, SINCE THE CONSTRAINTS ARE SMALL ENOUGH */
// CODE-:
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i) 
#define REP(i,k,n) for (int i = k; i < n; ++i) 
#define REPR(i,k,n) for (int i = k; i >= n; --i) 
#define input(i,n,arr,p) for(int i=0;i<n;i++){ int p;cin>>p;arr[i] = p;}
typedef long long ll;
void solve();

int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);cout.tie(NULL);
  ll T;
cin>>T;
 while(T--)
solve();
return 0;
}

void solve()
{
	ll x;
	cin>>x;
	bool flag = true;
	for(ll i=0;i<=x/2;i++)
	{
	    ll p = x-i;
	    if((p|i)+(p&i)==x)
	    {
	        std::cout <<p<<" "<<i<< std::endl;
	        flag = false;
	        break;
	    }
	    if(flag)
	    std::cout << -1 << std::endl;
	}
  }
