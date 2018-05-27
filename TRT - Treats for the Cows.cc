#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
ll inf = 1LL << 62;
ll mod = 1000000007;

using namespace std;

pair<ll,int> dp[2020][2020];
int pre[2020];
int v[2020];
pair<ll,int> init;

pair<ll,int> solve(int i, int j, int a){
  if(i == j) return {a*v[i], a};
  if(dp[i][j] != init) return {dp[i][j].first + (a - dp[i][j].second)*(pre[j] - (i == 0? 0: pre[i-1])), a};
  ll L = a * v[i] + solve(i+1, j, a+1).first;
  ll R = a * v[j] + solve(i, j-1, a+1).first;
  return dp[i][j] = {max(L, R), a};
}

int main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("in.in","r",stdin);
  init = {inf, 0};
  for(int i=0 ; i<=2000 ; i++)
    for(int j=0 ; j<= 2000 ; j++)
      dp[i][j] = init;
  int n;
  cin >> n;
  for(int i=0 ; i<n ; i++){
    cin >> v[i];
    if(i == 0) pre[i] = v[i];
    if(i) pre[i] = v[i] + pre[i-1];
  }
  cout << solve(0, n-1, 1).first;
  return 0;
}
