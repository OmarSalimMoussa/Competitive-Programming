#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
ll inf = 1LL << 62;
ll mod = 1000000007;

using namespace std;
string abr;
vector<string> txt;
unordered_map<string, short> m;

int dp[150][150][150];

int solve(int cur, int ptr, int pos){
  if(cur == abr.length() && ptr == txt.size()) return 1;
  if(ptr == txt.size()) return 0;
  if(pos == txt[ptr].length()) return 0;


  if(dp[cur][ptr][pos] != -1) return dp[cur][ptr][pos];


  dp[cur][ptr][pos] = 0;
  if(abr[cur] == toupper(txt[ptr][pos])){
    dp[cur][ptr][pos] += solve(cur+1, ptr, pos+1) + solve(cur+1, ptr+1, 0) + solve(cur, ptr, pos+1);
  }
  else{
    dp[cur][ptr][pos] += solve(cur, ptr, pos+1);
  }


  return dp[cur][ptr][pos];
}

int main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  while(cin >> n){
    if(n == 0) return 0;
    bool ok = true;

    m.clear();
    string inv;

    while(n--) cin >> inv, m[inv] = 1;

    while(cin >> abr){
      txt.clear();
      for(int i=0 ; i<150 ; i++)
        for(int j=0 ; j<150 ; j++)
          for(int k=0 ; k<150 ; k++)
            dp[i][j][k] = -1;
      string line, var;
      getline(cin, line);
      istringstream iss(line.substr(1));
      while(iss >> var){
        if(var == "CASE" && abr == "LAST"){
          ok = false;
          break;
        }
        if(m[var] == 0) txt.push_back(var);
      }
      if(!ok){
        break;
      }
      int ans = solve(0,0,0);
      if(ans == 0) cout << abr << " is not a valid abbreviation\n";
      else cout << abr << " can be formed in " << ans << " ways\n";
    }
  }
  return 0;
}
