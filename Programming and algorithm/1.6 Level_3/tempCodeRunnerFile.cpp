#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<n;k++)
                if(a[i]+a[j] == a[k])
                    sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}