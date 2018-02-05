#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define over LONG_LONG_MAX
ll inf = 1LL << 60;
ll mod = 1000000007;
double pi = acos(-1.0);


using namespace std;
int n, k, d;
ll dp[110][2];

ll solve(int sum, int up){
  ll ans = 0;
  if(sum>n) return 0;
  if(sum == n) return 1;
  if(dp[sum][up == k]) return dp[sum][up == k];
  for(int i=1 ; i<=up ; i++){
    dp[sum][up == k] += solve(sum+i, up);
    dp[sum][up == k] %= mod;
  }
  return dp[sum][up == k];
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k >> d;
  cout << (solve(0,k) - solve(0,d-1) + 2*mod)%mod;
  return 0;
}
