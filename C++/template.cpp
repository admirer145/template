#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
using namespace chrono;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define inf 1000000000000000018
#define MOD 1000000007
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define hrc high_resolution_clock
#define fr(i, s, n) for(int i=(s); i<=(n); i++)
#define rfr(j, n, s) for(int j=(n); j>=(s); j--)
#define lsb(x) ((x)&(-x))

pii dir4[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
pii dir8[8] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

hrc::time_point timeS;

void sTime(){
    timeS = hrc::now();
}

void eTime(){
    hrc::time_point timeE = hrc::now();
    auto t = duration_cast<milliseconds>(timeE-timeS).count();
    cout<<"Time taken : "<<t<<"ms"<<endl;
}

bool isSet(ll n, int i){
    return n&(1<<i);
}

template<typename T, typename S> void mask(T &n, S i){
    n+=(1<<i);
}

template<typename T, typename S> void unMask(T &n, S i){
    n-=(1<<i);
}

void print(){
    cout<<endl;
}

template<typename T, typename... Args>
void print(T var, Args... arg){
    std::cout<<var<<" ";
    print(arg...);
}

void file(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}

template<typename T, typename S> string base(T n, S b){
    string res="";
    while(n){
        T md = n%b;
        if(md>=10){
            md+=55;
        }else{
            md+=48;
        }
        res+=char(md);
        n/=b;
    }
    reverse(all(res));
    return res;
}

template<class T = ll>
class BIT{
    public:
    
    vector<T> bit;
    int size;
    
    BIT(int len){
        size = len+1; 
        bit = vector<T>(size);
    }
    
    void insert(int indx, T val){
        while(indx<size){
            bit[indx]+=val;
            indx+=lsb(indx);
        }
    }
    T query(int indx){
        T res=0;
        while(indx>0){
            res+=bit[indx];
            indx-=lsb(indx);
        }
        return res;
    }
};

class unionFind{
    public:

    vi arr;
    vi size;
    
    unionFind(int n){
        arr = vi(n+1);
        size = vi(n+1);
        fr(i, 0, n){
            arr[i] = i;
            size[i] = 1;
        }
    }

    int Find(int a){
        while(a!=arr[a]){
            a=arr[arr[a]];
        }
        return a;
    }
    void Union(int a, int b){
		if(size[a]>size[b]){
			swap(a,b);
		}
        size[b] += size[a];
        arr[a] = arr[b];
    }
};

template<typename T> vector<T> factorArray(T n){
    vector<T> Factor;
    for(T i=1;i*i<=n;i++){
        if(n%i==0){
            if(n/i!=i){
                Factor.pb(n/i);
            }
            Factor.pb(i);
        }
    }
    sort(all(Factor));
    return Factor;
}

template<typename T> vector<vector<T>> primeFactorArray(T n){
    vector<vector<T>> ans;
    for(T i=2;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            ans.pb({i, cnt});
        }
    }
    if(n>1){
        ans.pb({n,1});
    }
    return ans;
}

vi totientArray(int n)
{
    vi res(n+1);
    
    fr(i, 0, n){
        res[i]=i;
    }
    
    fr(i, 2, n){
        if(res[i]==i){
            res[i]=i-1;
            for(int j=2*i;j<=n;j+=i)
            {
                res[j]=(res[j]/i)*(i-1);
            }
        }
    }
    return res;
}


vi sieveArray(int size){
    vi prm(size+1);
    fr(i, 2, size){
        prm[i]=1;
    }
    prm[0]=prm[1]=0;
    
    for(int i=2; i*i<=size; i++){
        if(prm[i]){
            for(int j=i*i; j<=size; j+=i){
                prm[j]=0;
            }
        }
    }
    return prm;
}

bool isVowel(char s){
    string vowC = "AEIOU", vowS = "aeiou";
    fr(i, 0, 4){
        if(vowC[i]==s || vowS[i]==s){
            return true;
        }
    }
    return false;
}


bool isPalindrome(string str){
    int s=0, e=str.length()-1;
    while(s<e){
        if(str[s]!=str[e])
            return false;
        s++;
        e--;
    }
    return true;
}

bool isPrime(ll num){
    if(num<2){
        return false;
    }
    for(ll i=2; i*i<=num; i++){
        if(num%i==0)
            return false;
    }
    return true;
}

ll lowerPower(ll n, ll k=2){
    if(k<=1 || n<=0){
        return 0;
    }
    ll ans=1;
    while(n>=ans){
        ans*=k;
    }
    return ans/k;
}

ll upperPower(ll n, ll k=2){
    if(k<=1 || n<=0){
        return 0;
    }
    ll ans=1;
    while(n>=ans){
        ans*=k;
    }
    return ans;
} 

ll power(ll base, ll exp, ll mod=MOD){
    ll ans=1;
    while(exp>0){
        if(exp&1)
            ans = (ans*base)%mod;
        base = (base*base)%mod;
        exp/=2;
    }
    return ans;
}

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}

void solve(){
    
}

int main(){
    
    fast;
    int t=1;
    cin>>t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
