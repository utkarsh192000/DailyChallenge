#include<bits/stdc++.h>
using namespace std;


int binaryTodecimal(string s){
    int ans=0;
    // initially our answer is 0 
    // we are going to take only those values whose bit value is 1 
    int weight=1;
    // since base of binary number is 2 and it increase with power of 2 as we go to MSB 
    // initially 2^0=1

    int i=s.length()-1;
    // we will start the traversing from backward i.e LSB 
    while(i>=0){
        if(s[i]=='1'){
            ans+=weight;
            // whenevr we find 1 , we add its weight 
        }
        weight=weight<<1;
        // in every loop increase the weight value by power of 2 ; 1,2,4,8,16...
        // here we have used left shift by 1 ; which is equivalent to multiplication of number by 2^1
        // weight=weight*2;
        
        i--;
        // decrement the i 

    }
    return ans;
    // finally return the ans 

}


int main(){

    string s;
    cin>>s;
    // input a string 

    int ans=binaryTodecimal(s);
    // store whatever the function returns 
    cout<<ans;
    // print it 


    return 0;
}