#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[1000001];
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=1000000;i++){
        a[i]=(a[i-1]+a[i-2]) % 1000;
    }
    while(n--){
        int b;
        cin>>b;
        cout<<a[b]<<endl;
    }
    return 0;
}