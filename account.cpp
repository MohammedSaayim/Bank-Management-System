#include<iostream>
#include"account.h"
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

//start of bank management system


//generating checksum for credit card number generator
char checksum_gen(string cc_num_str_temp){
    
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


//cvv generator
int cvv_gen(){
    int cvv=rand()%999+100;
    return cvv;
}
//cvv generator end

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

    checksum=checksum_gen(cc_num_str_temp);
    cc_num_str[15]=checksum;

    return(cc_num_str);
}
//end of cc num generator fn


int getIntFromString(string str)
{
    stringstream strStream(str);
    int x = 0;
    strStream >> x;

    return x;
}

// Start of Function to validate CVV
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
// End of Function to validate CVV

void account::create_account()
{
	cout<<"\n\t\t\tEnter the Account No. : ";
	cin>>acno;
	cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore(); /*cin.ignore() is to clear the unwanted buffer, 
					so when next input is taken, 
					it stores into the desired container, 
					but not in the buffer of previous variable*/

	cin>>name;
	cout<<"\n\t\t\tEnter Type of the Account Current or Savings(Type C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>deposit;
	cout<<"\n\t\t\tCreating credit card\n\n";
	acc_cc_num = cc_num_gen();
	cc_cvv = cvv_gen();

	print_cc_num(acc_cc_num, cc_cvv);

	cout<<"\n\n\t\t\tAccount Created..\n";
}

void print_cc_num(string cc_num, int cvv)
{
    cout<<"*****CREDIT CARD GENERATOR*******"<<endl<<endl<<endl;
    cout<<"*********LUHN'S ALGORITHM*********"<<endl<<endl;
    cout<<"\n|***********************************************************|\n";
    cout<<"|                                                           |\n";                                                         
    cout<<"|Credit Card Number: "<<cc_num<<"                       |"<<endl;                          
    cout<<"|                                                           |\n|";    
    cout<<"CVV: "<<cvv<<"                                                   |"<<endl;
    cout<<"|                                                 MASTERCARD|   \n*************************************************************\n";

}

void account::show_account() const
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
	cout<<"\n\t\t\tCredit Card : " << acc_cc_num;
	cout<<"\n\t\t\tCVV Number : "<< cc_cvv;
	//print_cc_num(acc_cc_num, cc_cvv);
}


void account::modify()
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
    cin>>name;
	cout<<"\n\t\t\tModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tModify Balance amount : ";
	cin>>deposit;
}


void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<" "<<acc_cc_num<<setw(16)
	<<" "<<cc_cvv<<setw(3)<<endl;
	//setw sets the width for output operation
}

void account::setname(string acc_name) {
	name=acc_name;
}

string account::retname() const{
	return name;
}

void account::setacno(int acc_no) 
{
	 acno=acc_no;
}

int account::retacno() const
{
	return acno;
}

void account::setCCNum(string cc_number) 
{
 acc_cc_num=cc_number;
}

string account::retCCNum() const
{
	return acc_cc_num;
}

void account::setcvv(int cvv_num){
    cc_cvv=cvv_num;
}
int account::retcvv() const
{
	return cc_cvv;
}

void account::setdeposit(int dep){
    deposit=dep;
}
int account::retdeposit() const
{
	return deposit;
}

void account::settype(char cc_type){
    type=cc_type;
}
char account::rettype() const
{
	return type;
}


//end of bank management system above main fn



//start of bank mgmt. sys. below main fn
void write_account()
{
	account ac;
	ofstream outFile; //ofstream is a stream class to write data to files

	//open file in binary mode to add data (ios::app means append)  
	outFile.open("account.csv",ios::app); 
	ac.create_account();

	/*reinterpret_cast converts one pointer of another pointer of any type,
	  used here to convert binary bits to char*/
	//outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile<<"\n"<<ac.retacno()<<","<<ac.retname()<<","<<ac.rettype()<<","<<ac.retdeposit()<<","<<ac.retCCNum()<<","<<ac.retcvv();
	outFile.close();
}

void display_sp(int n)
{
    vector<string> row;
	account ac;
	bool flag=false;
	ifstream inFile;//ifstream is a file class to read from files
	inFile.open("account.csv");
    string line, word, temp;
    
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tACCOUNT DETAILS\n";


    while(inFile>>temp){
        
        row.clear();
        //getline(inFile,line);
        stringstream s(temp);
        //cout<<line<<"line 2 strstream";
        while(getline(s,word, ',')){
            row.push_back(word);
        }
        
        ac.setacno(getIntFromString(row[0]));
        if(n == ac.retacno())
        {
            ac.setname(row[1]);
            ac.settype(row[2][0]);
            ac.setdeposit(getIntFromString(row[3]));
            ac.setCCNum(row[4]);
            ac.setcvv(getIntFromString(row[5]));
            
            ac.show_account();
            cout<<"\n\n";
            flag = true;

            break;
        }
        
        
    }
    inFile.close();
	if(flag==false)
		cout<<"\n\n\t\t\tAccount number does not exist";
}


void display_all()
{
    vector<string> row;
	account ac;
	bool flag=false;
	ifstream inFile;//ifstream is a file class to read from files
	inFile.open("account.csv");
    string line, word, temp;
    
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tBALANCE DETAILS\n";
    	/*while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}*/

    int count = 1;

		while(inFile>>temp){
            
            row.clear();
            //getline(inFile,line);
            stringstream s(temp);
            //cout<<line<<"line 2 strstream";
            while(getline(s,word, ',')){
                row.push_back(word);
            }
            ac.setacno(getIntFromString(row[0]));
            ac.setname(row[1]);
            ac.settype(row[2][0]);
            ac.setdeposit(getIntFromString(row[3]));
            ac.setCCNum(row[4]);
            ac.setcvv(getIntFromString(row[5]));
            cout<<count<<"\n";
            ac.show_account();
            count++;
            cout<<"\n\n";
            flag = true;
            
        }
    inFile.close();
	if(flag==false)
		cout<<"\n\n\t\t\tAccount number does not exist";
}



void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;//fstream is a file class to both read and write from/to files
    File.open("account.dat",ios::binary|ios::in|ios::out);//opens file in binary or input or output mode
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));//convert from binary to char and sizeof(account) means read whole file
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			/*pos=pos-sizeOf(Account) this is to set 'pos' from 
			cur pos to the beginning of the account to be modified*/

			File.seekp(pos,ios::cur); //fn call at 1353 
			/*seekp is to move the pointer from 
			cur position to the beginning of the record to be modified*/

		    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    cout<<"\n\n\t\t\tRecord Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}



void delete_account(int n)
{
	account ac;
	ifstream inFile;//ifstream: Stream class to read from files
	ofstream outFile;//ofstream: Stream class to write on files
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);//moves cursor to beginning of acc
	/* In (0,ios::beg), 0 is the value by which the pos 
	   of stream buffer will offset and ios::beg is the 
	   direction from which the offset will occur..beg=beginning*/  

	/*The below while loop loops through all the accounts*/
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{	
		/* if the for acc no doesn't match
			then rewrite the data of the acc 
			to temp file, so that when this account.dat 
			file gets deleted, we can restore the deleted 
			acc of unmatched acc no, so with this if 
			condition only the acc no matched will get del*/
		if(ac.retacno()!=n)//n is acc no
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");/*renaming temp.dat to account.dat to 
									   restore unmatched acc from if condition*/
	cout<<"\n\nRecord Deleted ..";
}



void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\t\t\tTO DEPOSITSS AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			/*sets the position of the cursor at the
			 beginning of the acccount*/
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}
//end of bank mgmt. sys. below main fn

