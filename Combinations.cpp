/*
    author    : MishkatIT
    created   : Thursday 2023-10-26-18.42.26
*/
#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';
using namespace std;
using ll        = long long;
using ld        = long double;
const ll mod    = 1000003;
const ll N      = 1e6 + 10;
const ll inf    = 1e9;
const ll linf   = 1e18;

vector<ll> fact(N);

void precal()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
    }

}

ll binPow(ll base, ll pow)
{
    ll result = 1;
    while(pow) {
        if(pow & 1) {
            result = (result % mod * base % mod) % mod;
        }
        base = (base % mod * base % mod) % mod;
        pow >>= 1;
    }
    return result;
}


ll nCr(ll n, ll r)
{
    if(n < r) {
        return 0;
    }
    ll x = fact[n];
    ll y = (fact[r] % mod * fact[n - r] % mod) % mod;
    return (x % mod * binPow(y, mod - 2) % mod) % mod;
}

int main()
{
    fio;
    precal();
    int t;
    cin >> t;
    int cs = 0;
    while(t--) {
        ll n, r;
        cin >> n >> r;
        cout << "Case " << ++cs << ": " << nCr(n, r) << '\n';
    }
    return 0;
}

