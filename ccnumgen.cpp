#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <bits/stdc++.h>
#include<string>
#include <cstdlib>
using namespace std;

char luhn(string cc_num_str_temp){
    
    char temp, temp2, temp3;
    int num2=0, sum=0, mod=0, checksum_int=0;

    for(int i=15;i>=0;i--)
    {

        temp=cc_num_str_temp[i];
        num2=((int)temp)-((int)'0');
        if(i%2==0)
                {
                    num2*=2;
                    if(num2>9){
                        num2-=9;
                    }
                    temp2='0'+num2;
                    cc_num_str_temp[i]=temp2;
                }
                sum+=num2;
        
    }
   // sum+=10;//for cc_num_str[0 and 1] which are not included in above
    mod=sum%10;
    if(mod==0){
        checksum_int=0;
    }
    else{
        checksum_int=10-mod;
    }
    temp3='0'+checksum_int;
    return(temp3);
}

int main(){
    srand(time(0));
    char checksum;
    long long int iin=0,threeToFifteen=0, cc_num=0;
    string cc_num_str, cc_num_str_temp;
    iin=5500000000000000;//15 zeroes
    threeToFifteen= rand()%999999999999+143791678912; //12 nine's and 12 random digits
    
    threeToFifteen*=10;

    cc_num=threeToFifteen+iin;
    cc_num_str_temp=to_string(cc_num);
    cc_num_str=to_string(cc_num);

    checksum=luhn(cc_num_str_temp);
    cc_num_str[15]=checksum;

    cout<<cc_num_str<<endl;
    return 0;
}
