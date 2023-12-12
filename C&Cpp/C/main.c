#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define int long
#define long long long
#define keqing main
#define endl '\n'
const int mod = 1000000007;
const int limit = 10000;

keqing(){
    int n;scanf("%lld",&n);
    int a[n];
    for(int &x:a)scanf("%lld",&x);
    set<int> st;
    int check[limit]={};
    st.insert(a[0]);
    for(int &x:a){
        auto it = st.lower_bound(x);
        if(*it==x)continue;
        if(it==st.end()){
            check[x]=check[*(--it)];
        }else if(it==st.begin()){
            check[x]=check[*it];
        }else{
            check[x]=check[*(it)];
            check[x]=max(check[x],check[*(--it)]);
        }
        check[x]++;
        st.insert(x);
    }
    for(auto x:st){
        printf("%lld %lld\n",x,check[x]);
    }
}
