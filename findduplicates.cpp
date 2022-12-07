// find duplicate in array
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[7]={6,3,1,5,4,3,2};
    int  ans = 0;
    for(int i = 0; i<7;i++){
        ans=ans^arr[i];
        cout<<"The 1st "<<"ans is "<<ans<<" i is :- "<<i<<" & Xor Is "<<ans<<endl;
    }
    cout<<endl;
    for(int i=0;i<7;i++){
        ans=ans^i;
        cout<<"The 2nd "<<"ans is "<<ans<<" i is :- "<<i<<" & Xor Is "<<ans<<endl;
    }
    cout<<"Final Answer is"<<endl;
    // returning ans
    cout<<ans;

}