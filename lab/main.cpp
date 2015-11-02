#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <queue>
#include <list>
#include <iterator>
#include <time.h>
#include <ctime>
#include <map>

using namespace std;
const int eps = 1e-6;
const int pi = 3.1415926535897932384626433832795;
const int inf = 1e9;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(),a.end()
int n,m;
vector<vector<int>> g;
vector<bool> u;
void dfs(int v){
    vector<int>q;
    q.pb(v);
    while (!q.empty()){
        int c = q.back();
        u[c]=1;
        q.pop_back();
        for (int i=0;i<g[c].size();i++){
            if (!u[g[c][i]]){
                u[g[c][i]]=1;
                q.push_back(g[c][i]);
            }
        }
        printf("%d ",c);
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d",&n,&m);
    g.resize(n+1);
    u.resize(n+1,0);
    for (int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].pb(y);
    }
    for (int i=1;i<=n;i++){
       if (!u[i]) dfs(i);
    }
    return 0;
}