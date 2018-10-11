/*
Author: Isabel Tait
Date: 10-9-2018
Class: COP3014
Assignment: Assignment 6
Professor: Dr. Lofton Bullard

Description: Program calculates the net cost, the tax, and the total cost of a call. Input comes from call record. Program is divided in 
to three functions: Input, Output, and Process.
Program gets input from a data file and reads it into an array of call records. The data from the array then gets printed into a datafile.

*/

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

const int SIZE = 200;

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



void Input(call_record call_DB[], int & count);
void Output(const call_record call_DB[], const int & count);
void Process(call_record call_DB[], const int & count);

void Input(call_record call_DB[], int & count)
{
	ifstream in;
	count = 0;

	in.open("call_data.txt");

	if (in.fail())
	{
		cout << "Input file did not open correctly." << endl;
		exit(1);
	}

	while (!in.eof())
	{
		in >> call_DB[count].cell_number;
		in >> call_DB[count].relays;
		in >> call_DB[count].call_length;

		count++;
	}


	in.close();
	/*in >> customer_record.cell_number;
	in >> customer_record.relays;
	in >> customer_record.call_length;*/
}



void Output(const call_record call_DB[], const int & count)
{
	ofstream out;
	int i;

	out.open("weekly4_call_info.txt");

	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);

	if (out.fail())
	{
		cout << "Output file did not open correctly." << endl;
		exit(1);
	}

	for (i=0; i<count; i++)
	{
		out << call_DB[i].cell_number << "        ";
		out << call_DB[i].relays << "             ";
		out << call_DB[i].call_length << "        ";
		out << call_DB[i].net_cost << "           ";
		out << call_DB[i].tax_rate << "%         ";
		out << call_DB[i].call_tax << "           ";
		out << call_DB[i].total_cost << "         " << endl;

		
	}

	

	out.close();
}

void Process(call_record call_DB[], const int & count)
{
	int i;

	


	for (i = 0; i < count; i++)
	{
		/*call_DB[i].net_cost = call_DB[i].relays / 50.0 * 0.40 * call_DB[i].call_length;
		call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate / 100;
		call_DB[i].total_cost = call_DB[i].net_cost + call_DB[i].call_tax;*/

		if (0 <= call_DB[i].relays && call_DB[i].relays <= 5)
		{
			call_DB[i].tax_rate = 1;
			
		}
		if (6 <= call_DB[i].relays && call_DB[i].relays <= 11)
		{
			call_DB[i].tax_rate = 3;
			//cout << "Your tax rate is " << customer_record.tax_rate << "%" << endl;
		}
		if (12 <= call_DB[i].relays && call_DB[i].relays <= 20)
		{
			call_DB[i].tax_rate = 5;
			//cout << "Your tax rate is " << customer_record.tax_rate << "%" << endl;
		}
		if (21 <= call_DB[i].relays && call_DB[i].relays <= 50)
		{
			call_DB[i].tax_rate = 8;
			//cout << "Your tax rate is " << customer_record.tax_rate << "%" << endl;
		}
		if (call_DB[i].relays > 50)
		{
			call_DB[i].tax_rate = 12;
			//cout << "Your tax rate is " << customer_record.tax_rate << "%" << endl;
		}


		call_DB[i].net_cost = call_DB[i].relays / 50.0 * 0.40 * call_DB[i].call_length;
		call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate / 100;
		call_DB[i].total_cost = call_DB[i].net_cost + call_DB[i].call_tax;
		
	}
}


int main()
{
	call_record call_DB[SIZE];
	int count = 0;

	Input(call_DB, count);
	Process(call_DB, count);
	Output(call_DB, count);


	return 0;
}