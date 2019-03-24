// spoj      
        #include <bits/stdc++.h>
             
        using namespace std;
         
        typedef long long ll; 
        const ll N = 1e4+5;
        const ll MOD = 1000000007;
        #define all(x) x.begin(),x.end()
        #define pii pair<ll,ll>
        #define pis pair<ll,string>
        #define F first
        #define S second
        #define LCM(a,b) ((a*b)/__gcd(a,b))
        #define inf 1e15
        #define test ll cse;scanf("%lld",&cse);for(ll _i=1;_i<=cse;_i++)
        #define PI 3.14159265
        typedef vector<vector<ll>> matrix;
        typedef vector<ll> vi;
 
 
vector<int> g[N];
bool used[N];
int timer, tin[N], fup[N];

int n,m;
unordered_set<int> Ap;
//set< pair<int,int> > Br;
void dfs(int v, int p = 0) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;

    for (int to: g[v]) {
        if (to == p)  continue;
        
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            // if(fup[to] > tin[v])
            //     Br.insert({ min(to,v), max(to,v)}); // bridge
            if (fup[to] >= tin[v] && p != 0)
                Ap.insert(v);             //v is articulation point
            ++children;
        }
        
    }
    if (p == 0 && children > 1)
        Ap.insert(v);                    //v is articulation point
}
void init(){
    memset(used , 0 , sizeof used);
    for(int i=0;i<N;i++) g[i].clear();
        
        Ap.clear();
        //Br.clear();
}
int main() {

    while(true){
        init();

        scanf("%d %d",&n,&m);

        if(n==0 && m==0)
            break;
        int x,y;
        for(int i=0;i<m;i++){
            scanf("%d %d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        timer = 1;
        dfs (1);
        printf("%d\n", (int)Ap.size());
    }
    return 0;
}