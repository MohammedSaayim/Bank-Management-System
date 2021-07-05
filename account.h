#include<iostream>
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

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
bool isValidCVVNumber(string);
bool isValid();
char checksum_gen(string);
string cc_num_gen();
int cvv_gen();
void print_cc_num(string, int);

class account
{
	int acno;
	string name;
	int deposit;
	char type;
	string acc_cc_num; 
	int cc_cvv;
public:
	void create_account();
	void show_account() const;
	/*const after the function is used to tell the compiler that
	 this function won't attempt to change the object it is called on*/
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	string retname() const;
    void setname(string acc_name);
	int retacno() const;
    void setacno(int acc_no);

	int retdeposit() const;
    void setdeposit(int dep);

	char rettype() const;
	void settype(char cc_type);
	string retCCNum() const;
	void setCCNum(string cc_number);
	int retcvv() const;
	void setcvv(int cvv_num);
};

