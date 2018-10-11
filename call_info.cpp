/*
Author: Isabel Tait
Date: 09-06-2018
Class: COP3014
Assignment: Assignment 1
Professor: Dr. Lofton Bullard

Description: Program calculates the net cost, the tax, and the total cost of a call. Input is phone number,
number of relay stations, and the length in minutes of a call. Program is divided in to three functions: Input, Output, and Process.

*/

#include<iostream>
#include<string>
using namespace std;



void Input(string & cell_number, int & relays, int & call_length); 
void Output(const string cell_number, const int relays, const int call_length, const double & net_cost, const double & call_tax, const double & total_cost_of_call); 
void Process(const int relays, const int call_length, double & net_cost, double & call_tax, double & total_cost_of_call, int & tax_rate);

void Input(string & cell_number, int & relays, int & call_length)
{
	cout << "Enter your Cell Phone Number: "; 
	cin >> cell_number; 
	cout << "Enter the number of relay stations: "; 
	cin >> relays; 
	cout << "Enter the length of the call in minutes: "; 
	cin >> call_length;
}



void Output(const string cell_number, const int relays, const int call_length, const double & net_cost, const double & call_tax, const double & total_cost_of_call)
{
	cout << "-----------------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Cell Phone" << "                    " << cell_number << endl;
	cout << "Number of Relay Stations" << "      " << relays << endl;
	cout << "Minutes Used" << "                  " << call_length << endl;
	cout << "Net Cost" << "                    " << net_cost << endl;
	cout << "Call Tax" << "                    " << call_tax << endl;
	cout << "Total Cost of Call" << "          " << total_cost_of_call << endl;

}

void Process(const int relays, const int call_length, double & net_cost, double & call_tax, double & total_cost_of_call, int & tax_rate)
{
	if (0 <= relays && relays <= 5)
	{
		tax_rate = 1;
		cout << "Your tax rate is " << tax_rate << "%" << endl;
	}
	if (6 <= relays && relays <= 11)
	{
		tax_rate = 3;
		cout << "Your tax rate is " << tax_rate << "%" << endl;
	}
	if (12 <= relays && relays <= 20)
	{
		tax_rate = 5;
		cout << "Your tax rate is " << tax_rate << "%" << endl;
	}
	if (21 <= relays && relays <= 50)
	{
		tax_rate = 8;
		cout << "Your tax rate is " << tax_rate << "%" << endl;
	}
	if (relays > 50)
	{
		tax_rate = 12;
		cout << "Your tax rate is " << tax_rate << "%" << endl;
	}

	/*cout << "We will now calculate the net cost of the call." << endl;
	cout << "Please type in the length in minutes of your call" << endl;
	cin >> call_length;
	cout << "The length in minutes of your call is " << call_length << endl;*/

	net_cost = relays / 50.0*0.40*call_length;
	cout << "Your net cost is " << net_cost << "." << endl;

	call_tax = net_cost*tax_rate / 100;
	cout << "Your call tax is " << call_tax << "." << endl;

	/*cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);*/

	total_cost_of_call = net_cost + call_tax;
	cout << "Your total cost is " << total_cost_of_call << "." << endl;

}


int main()
{

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
    string cell_number;
	int relays; 
	int  call_length; 
	double net_cost; 
	double call_tax; 
	double total_cost_of_call; 
	int tax_rate;
	string response = "y";

	cout << "Welcome to the Call Cost Calculator." << endl;
	
	while (response == "Y" || response == "y")
	{
		Input(cell_number, relays, call_length);
		Process(relays, call_length, net_cost, call_tax, total_cost_of_call, tax_rate);
		Output(cell_number, relays, call_length, net_cost, call_tax, total_cost_of_call);

		cout << "Would you like to make another calculation? Press Y for yes and N for no." << endl;
		cin >> response;
	}

	cout << "Goodbye." << endl;


	return 0;
}

