#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9 + 7)
#define mset(a, k) memset(a, k, sizeof(a))
#define fr(i, x, y) for (ll i = x; i < y; i++)
#define dr(i, x, y) for (ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define pqueue priority_queue<ll>
#define piqueue priority_queue<ll, vll, greater<ll>>
#define mapcl map<char, ll>
#define mapll map<ll, ll>
#define mapsl map<string, ll>
#define vi vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define psi pair<string, ll>
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define vii vector<pii>
#define vvi vector<vi>
#define vvii vector<vii>
using namespace std;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
//----------------------------------------FUNCTIONS-------------------------------------
ll gcd(ll x, ll y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll logx(ll base, ll num)
{
    int cnt = 0;
    while (num != 1)
    {
        num /= base;
        ++cnt;
    }
    return cnt;
}
vi vin(ll n)
{
    vi a(n);
    fr(i, 0, n) cin >> a[i];
    return a;
}
void out(vi a)
{
    for (int i = 0; i < (ll)a.S; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void in(ll *a, ll n)
{
    for (ll i = 0; i < n; i++)
        cin >> a[i];
}
void out(ll *a, ll n)
{
    fr(i, 0, n) { cout << a[i] << " "; }
    cout << '\n';
}
void out1(vi v)
{
    fr(i, 0, (ll)v.S) { cout << v[i] << " "; }
    cout << endl;
}
const ll MAXN = (ll)(1 * 1e6 + 5);
void solve()
{

    ll n;
    cin >> n;
    ll a[n];
    in(a, n);
    ll cnt = 0;
    ll maxi = -1;
    ll mini = 10;
    ll time[n][n];
    set<ll> s[5];
    fr(i, 0, n)
    {
        s[i].insert(i);
        fr(j, 0, n)
        {
            if (i == j)
            {
                time[i][j] = 0;
                continue;
            }
            ll x = j - i;
            x *= 60;
            ll y = a[i] - a[j];
            if (y == 0)
            {
                time[i][j] = -INT_MAX;
                continue;
            }
            ll z = (x / y);
            time[i][j] = z;
            if (z >= 0)
            {
                s[i].insert(j);
            }
        }
    }
    //maxi = max(maxi, cnt);
    //mini = min(mini, cnt);
    /*	fr(i, 0, n)
		{
			cout << i + 1 << "-> ";
			for (auto it : s[i])cout << it + 1 << " ";
			cout << '\n';
		}*/
    fr(i, 0, n)
    {
        //s[i].insert(i + 1);
        fr(j, 0, n)
        {
            if (time[i][j] >= 0)
            {
                //s[i].insert(j + 1);
                for (auto it : s[j])
                {
                    if (time[i][j] <= time[j][it])
                        s[i].insert(it);
                }
            }
        }
    }
    fr(i, 0, n)
    {
        //cout << i + 1 << "-> ";
        mini = min(mini, (ll)s[i].size());
        maxi = max(maxi, (ll)s[i].size());
    }
    //cout << '\n';
    cout << mini << " " << maxi << '\n';
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("inp4.txt", "r", stdin);
    freopen("out4.txt", "w", stdout);
#endif
    fast();
    ll t = 1;
    cin >> t;
    //sieve(1e7 + 5);
    fr(i, 0, t)
    {
        solve();
    }
}