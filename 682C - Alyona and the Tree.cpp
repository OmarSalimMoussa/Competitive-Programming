#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define over LONG_LONG_MAX
ll inf = 1LL << 60;
ll mod = 1000000007;
double pi = acos(-1.0);

using namespace std;

vector<pair<int,ll> > g[100010];
ll a[100010];
bool seen[100010];
int in = 0;

void dfs(int cur, ll sum){
  if(seen[cur]) return;
  seen[cur] = true;
  if(sum<=0) sum = 0;
  if(sum > a[cur]) return;
  in++;
  for(int i=0 ; i<g[cur].size() ; i++){
    dfs(g[cur][i].first, sum+g[cur][i].second);
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  for(int i=1 ; i<=n ; i++){
    cin >> a[i];
  }
  for(int i=1 ; i<=n-1 ; i++){
    int p;
    ll c;
    cin >> p >> c;
    g[i+1].push_back({p,c});
    g[p].push_back({i+1,c});
  }
  dfs(1, 0);
  cout << n - in;
  return 0;
}
