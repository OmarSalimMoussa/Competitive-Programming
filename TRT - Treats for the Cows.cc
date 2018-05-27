#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
ll inf = 1LL << 62;
ll mod = 1000000007;

using namespace std;

ll dp[2020][2020];
int v[2020];

int main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  for(int i=0 ; i<n ; i++){
    cin >> v[i];
  }
  for(int i=n-1 ; i>=0 ; i--){
    for(int j=i ; j<n ; j++){
      if(i == j) dp[i][j] = n*v[i];
      else{
        ll a = n-(j-i);
        if(i == n-1) dp[i][j] = a*v[j] + dp[i][j-1];
        else if(j == 0) dp[i][j] = a*v[i] + dp[i+1][j];
        else dp[i][j] = max(a*v[i] + dp[i+1][j], a*v[j] + dp[i][j-1]);
      }
    }
  }
  cout << dp[0][n-1];
  return 0;
}

