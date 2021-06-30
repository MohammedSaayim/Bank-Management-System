#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <bits/stdc++.h>
#include<string>
#include <cstdlib>
#include <regex>
using namespace std;

//generating checksum for credit card number generator

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
    //if the sum is divisible by 10 checksum=0 
    //otherwise checksum=10-remainder to make the sum divisible by 10
    if(mod==0){
        checksum_int=0;
    }
    else{
        checksum_int=10-mod;
    }
    temp3='0'+checksum_int; //convert checksum from int to char
    return(temp3);
}
//end of function to generate checksum for cc num gen



//start of function to generate output for cc num
string cc_num_gen(){
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

    return(cc_num_str);
}
//end of cc num generator fn

// Function to validate the CVV
// (Card Verification Value) number
bool isValidCVVNumber(string str)
{
 
    // Regex to check valid CVV
    // (Card Verification Value) number
    const regex pattern("^[0-9]{3,4}$");
 
    // If the CVV (Card Verification Value)
    //  number is empty return false
    if (str.empty())
    {
        return false;
    }
 
    // Return true if the CVV
    // (Card Verification Value) number
    // matched the ReGex
    if (regex_match(str, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}

class credit
{
	public:
		string card_no;
		void type();
		bool isValid();
};

void credit:: type()
{
		if((card_no.length()==15) && (card_no[0]=='3') &&  (card_no[1]=='4'||'7'))
	{
		cout<<"You are trying to validate American Express Card."<<"\n";
	}
	else if((card_no.length()==16)&& (card_no[0]=='5')&&(card_no[1]=='1'||'2'||'3'||'4'||'5'))
	{
		cout<<"You are trying to validate Master Card"<<"\n";
	}
	else if((card_no[0]=='4')&&(card_no.length()==13||16))
	{
		cout<<"You are trying to evaluate Visa Cards"<<"\n";
	}

	else 
	{
		cout<<"Card Type Unknown!"<<endl;
	}
}


bool credit::isValid()
{
	 int len = card_no.length();
        int TotalSum = 0;
        int SumOdd=0,SumEven=0;
          
        //double the even placed digits from the end and adding all.If it results in two digit number ,add the digits
        for (int i = len - 2; i >= 0; i = i - 2) {
            int twice = (((card_no[i])-48)* 2);   //converting string array to integer array
            if (twice > 9) {
                twice = (twice / 10) + (twice % 10);
            }
            SumEven = SumEven+twice;
        }
        
      
        //adding all the odd digits number from the end
        for (int i = len - 1; i >= 0; i = i - 2) {
            SumOdd = SumOdd+(((card_no[i])-48));
        }
      
        TotalSum= SumEven +SumOdd;
        
       //checking if total sum of odd and even placed digits is a multiple of 10.
       //if yes,the number is valid.
        if(TotalSum%10==0)
        {
        	cout<<"Entered Card Number "<<card_no <<" is valid"<<endl;
            return true;
		}
		else{
			cout<<"Entered Card Number "<<card_no <<" is invalid"<<endl;
            return false;
		}
        
}

//cvv generator
int cvv_gen(){
    int cvv=rand()%999+147;
    return cvv;
}
//cvv generator end

int main()
 {
    srand(time(0));
    string str,cc_num;
 	credit ob1;
 	int i=0,ans,ans2,cvv;
	cout<<"*****CREDIT CARD GENERATOR & VALIDATOR*******"<<endl<<endl<<endl;
	cout<<"*********LUHN'S ALGORITHM*********"<<endl<<endl;
do{
    cout<<"Choose an option \n";
    cout<<" 1: Generate a Credit Card \n 2: Validate a Credit Card Number \n"<<endl;
    cout<<"(press any key to exit)\n"<<endl;
    cin>>ans;
    switch(ans){
        case 1: cc_num=cc_num_gen();
                cout<<"\n************************************************************\n";
                cout<<"Credit Card Number is: "<<cc_num<<endl;
                cout<<"************************************************************\n";
                cvv=cvv_gen();
                cout<<"\n************************************************************\n";
                cout<<"CVV is: "<<cvv<<endl;
                cout<<"\n************************************************************\n";
                break;
        case 2: 
                cout<<"Enter the credit card number you want to check: \n";
                cin>>ob1.card_no;
                cout<<"\n"<<"Your entered number is :"<<ob1.card_no<<"\n";
                ob1.type();
                cout<<"\n************************************************************\n";
                ob1.isValid();
                cout<<"************************************************************\n";
                cout<<"\n Enter CVV Number \n"<<endl;
                cin>>str;
                if(isValidCVVNumber(str)==1){
                    cout<<"\n************************************************************\n";
                    cout<<"The CVV number is valid \n"<<endl;
                    cout<<"************************************************************\n";
                }
                else{
                    cout<<"\n************************************************************\n";
                    cout<<"The CVV Number is Invalid \n"<<endl;
                    cout<<"\n************************************************************\n";
                }
                break;

        
        default:i++;
    }
}while(i==0);

    return 0;


}