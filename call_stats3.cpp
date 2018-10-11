/*
Author: Isabel Tait
Date: 09-25-2018
Class: COP3014
Assignment: Assignment 5
Professor: Dr. Lofton Bullard

Description: Program calculates the net cost, the tax, and the total cost of a call. Input is phone number,
number of relay stations, and the length in minutes of a call. Program is divided in to three functions: Input, Output, and Process.
Program gets input from a data file and outputs a every field of the call record to the file.

*/

#include<iostream>
#include<string>
#include<fstream>//this library is for i/o stream 
using namespace std;

class call_record
{
public:
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};



void Input(ifstream &, call_record &);
void Output(const call_record &, ofstream &);
void Process(call_record &);

void Input(ifstream & in, call_record & customer_record)
{
	in >> customer_record.cell_number;
	in >> customer_record.relays;
	in >> customer_record.call_length;
}



void Output(const call_record & customer_record, ofstream & out)
{
	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);

	out << customer_record.cell_number << "        ";
	out << customer_record.relays << "             ";
	out << customer_record.call_length << "        ";
	out << customer_record.net_cost << "           ";
	out << customer_record.tax_rate << "%         ";
	out << customer_record.call_tax << "           ";
	out << customer_record.total_cost << "         " << endl;
}

void Process(call_record & customer_record)
{
	if (0 <= customer_record.relays && customer_record.relays <= 5)
	{
		customer_record.tax_rate = 1;
		//cout << "Your tax rate is " << customer_record.tax_rate << "%" << endl;
	}
	if (6 <= customer_record.relays && customer_record.relays <= 11)
	{
		customer_record.tax_rate = 3;
		//cout << "Your tax rate is " << customer_record.tax_rate << "%" << endl;
	}
	if (12 <= customer_record.relays && customer_record.relays <= 20)
	{
		customer_record.tax_rate = 5;
		//cout << "Your tax rate is " << customer_record.tax_rate << "%" << endl;
	}
	if (21 <= customer_record.relays && customer_record.relays <= 50)
	{
		customer_record.tax_rate = 8;
		//cout << "Your tax rate is " << customer_record.tax_rate << "%" << endl;
	}
	if (customer_record.relays > 50)
	{
		customer_record.tax_rate = 12;
		//cout << "Your tax rate is " << customer_record.tax_rate << "%" << endl;
	}



	customer_record.net_cost = customer_record.relays / 50.0*0.40*customer_record.call_length;
	//cout << "Your net cost is " << customer_record.net_cost << "." << endl;

	customer_record.call_tax = customer_record.net_cost*customer_record.tax_rate / 100;
	//cout << "Your call tax is " << customer_record.call_tax << "." << endl;

	/*cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);*/

	customer_record.total_cost = customer_record.net_cost + customer_record.call_tax;
	//cout << "Your total cost is " << customer_record.total_cost << "." << endl;

}


int main()
{
	call_record customer_record;
	ofstream out;

	ifstream in; //declares input file stream
	in.open("call_data.txt");

	out.open("weekly_call_info.txt");


	if (in.fail())
	{
		cout << "Input file did not open correctly." << endl;
	}

	else
	{
		while (!in.eof())
		{
			Input(in, customer_record);
			Process(customer_record);
			Output(customer_record, out);
		}
	}

	out.close();
	in.close();


	return 0;
}
