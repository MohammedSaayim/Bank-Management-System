#include<iostream>
#include"account.h"
// #include"sort.h"
#include<fstream>
#include<cctype>//toUpper
#include<iomanip>//ios::
#include<stdlib.h>//rand()
#include<time.h>//srand()
#include <bits/stdc++.h>//includes every std lib
#include<string>
#include <cstdlib>//rand()
#include <regex>
using namespace std;

//start of class 'credit' which contains types of credit card and validator member fns
class credit
{
	public:
		string card_no;
		void type();
		bool isValid();
};
//end of class 'credit'

//start of validator fn
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
//end of validator fn


//start of credit card type fn
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
//end of type fn


int main()
{
    srand(time(0));//seeds or initializes random number generator
    string str,cc_num;
 	credit ob1;
	int num,i=0,ans,ans2,cvv;

    //start of bank management system inside main
	do
	{
	cout<<"\n\n\t\t\t\t===================================\n";
	cout<<"\t\t\t\tCREDIT CARD GENERATOR AND VALIDATOR";
	cout<<"\n\t\t\t\t===================================\n";

		cout<<"\t\t\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t\t\t1. NEW ACCOUNT";
		cout<<"\n\t\t\t\t2. VIEW SPECIFIC ACCOUNT DETAILS";
		cout<<"\n\t\t\t\t3. DISPLAY ALL ACCOUNTS";
        cout<<"\n\t\t\t\t4. Validate a Credit Card Number \n"<<endl;
        cout<<"\n\t\t\t\t   (press any key to exit)\n"<<endl;
		cout<<"\n\n\t\t\t\tSelect Your Option (1-4): ";
		cin>>ans;

		switch(ans)
		{
		case 1:
			write_account();
			break;/*
		case 2:
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case 3:
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;*/
		case 2:
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case 3:
			display_all();
			break;/*
		case 6:
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		case 7:
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
        case 8: 
			cc_num=cc_num_gen();
			cvv=cvv_gen();
            print_cc_num(cc_num, cvv);
            break;*/
        case 4: 
            system("CLS");
            cout<<"*****CREDIT CARD VALIDATOR*******"<<endl<<endl<<endl;
            cout<<"*********LUHN'S ALGORITHM*********"<<endl<<endl;
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
		 default:
			i++;
			break;
		}
		cin.ignore();
		cin.get();
    }while(i==0);
    //end of bank mgmt. sys. inside main 

	return 0;
}



