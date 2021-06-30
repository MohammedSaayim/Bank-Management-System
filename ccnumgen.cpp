#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <bits/stdc++.h>
#include<string>
#include <cstdlib>
using namespace std;


int main(){
    srand(time(0));
    char temp;
    char temp2;
    int num2=0;
    int sum=0;
    int mod=0;
    int checksum=0;
    char temp3;
    int totalSum=0;
    long long int iin=5500000000000000;//15 zeroes
    long long int threeToFifteen= rand()%999999999999+143791678912; //12 nine's and 12 random digits
    threeToFifteen*=10;
    long long int cc_num=threeToFifteen+iin;
    string cc_num_str=to_string(cc_num);
    
    string cc_num_str_actual=to_string(cc_num);

    for(int i=15;i>=0;i--)
    {

        temp=cc_num_str[i];
        num2=((int)temp)-((int)'0');
        if(i%2==0)
                {
                    num2*=2;
                    if(num2>9){
                        num2-=9;
                    }
                    temp2='0'+num2;
                    cc_num_str[i]=temp2;
                }
                sum+=num2;
        
    }
   // sum+=10;//for cc_num_str[0 and 1] which are not included in above
    mod=sum%10;
    if(mod==0){
        checksum=0;
    }
    else{
        checksum=10-mod;
    }
    temp3='0'+checksum;
    cc_num_str_actual[15]=temp3;

    totalSum=sum+checksum;
    cout<<cc_num_str_actual<<endl;
    return 0;
}
