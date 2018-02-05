#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define over LONG_LONG_MAX
ll inf = 1LL << 60;
ll mod = 1000000007;
double pi = acos(-1.0);

using namespace std;

ll w[100010];
vector<ll> a;
ll dp[100010][2];
int n;

ll solve(int pos, int last){
  if(pos == a.size()) return 0;
  if(dp[pos][last == a[pos]-1] != -1) return dp[pos][last == a[pos]-1];
  if(last == a[pos]-1) return dp[pos][last == a[pos]-1] = solve(pos+1, last);
  else return dp[pos][last == a[pos]-1] = max(solve(pos+1, last), w[a[pos]] + solve(pos+1, a[pos]));
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  map<ll,ll> m;
  cin >> n;
  for(int i=0 ; i<n ; i++){
    int x;
    cin >> x;
    m[x]++;
  }
  a.clear();
  for(map<ll,ll> :: iterator it = m.begin() ; it != m.end() ; ++it){
    a.push_back(it->first);
    w[it->first] = (it->first) * (it->second);
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0,-1);
  return 0;
}
