#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=n; i>=2; i--){
        bool flag = true;
        for(int j=2; j < n; j++){
            if(i % j == 0)
                flag = false;
        }
        if(flag){
            cout<<n;
            return 0;
        }     
    }
    return 0;
}