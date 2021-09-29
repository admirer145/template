#include<bits/stdc++.h>
using namespace std;

// Number of factors of each i till n
// Time Complexity: O(nlogn)
vector<int> number_of_factors(int n){
    vector<int> factors(n+1, 0);
    for(int i=1; i<=n; i++){
        for(int j=1; i*j<=n; j++){
            factors[i*j]++;
        }
    }
    return factors;
}

// Number of coprimes of each i till n
// Time Complexity: O(nlogn)
vector<int> number_of_coprimes(int n){
    vector<int> phi(n+1);
    iota(phi.begin(), phi.end(), -1);
    phi[0] = 0; phi[1] = 1;
    for(int i=2; i<=n; i++){
        for(int j=2*i; j<=n; j+=i){
            phi[j] -= phi[i];
        }
    }
    return phi;
}

// all prime factors of n and their count
// Time Complexity: O(sqrt(n))
vector<pair<int, int>> prime_factors_of_n(int n){
    vector<pair<int, int>> prime_factors;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            int cnt = 0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            prime_factors.push_back({i, cnt});
        }
    }
    if(n > 1){
        prime_factors.push_back({n, 1});
    }
    return prime_factors;
}

// all prime numbers till n
// Time Complexity: O(n)
vector<int> primes_till_n(int n){
    vector<int> pr, lp(n+1, 0);
    for (int i=2; i<=n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=n; ++j)
            lp[i * pr[j]] = pr[j];
    }
    return pr;
}


void test(){
    vector<int> factors = number_of_factors(20);
    vector<int> coprimes = number_of_coprimes(20);
    vector<pair<int, int>> prime_factor = prime_factors_of_n(20);
    vector<int> primes = primes_till_n(20);
    for(int i=0; i<factors.size(); i++){
        cout<<factors[i]<<" \n"[i==(int)factors.size()-1];
    }
    for(int i=0; i<coprimes.size(); i++){
        cout<<coprimes[i]<<" \n"[i==(int)coprimes.size()-1];
    }
    for(int i=0; i<prime_factor.size(); i++){
        cout<<prime_factor[i].first<<" \n"[i==(int)prime_factor.size()-1];
    }
    for(int i=0; i<primes.size(); i++){
        cout<<primes[i]<<" \n"[i==(int)primes.size()-1];
    }
}

int main(){
    test();
    return 0;
}
