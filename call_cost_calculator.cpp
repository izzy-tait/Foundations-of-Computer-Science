/*
Author: Isabel Tait 
Date: 08-29-2018
Class: COP3014
Assignment: Assignment 1
Professor: Dr. Lofton Bullard 

Description: Program calculates the net cost, the tax, and the total cost of a call. Input is phone number,
number of relay stations, and the length in minutes of a call.

*/

#include <iostream>
#include<string>
using namespace std; 


int main()
{
	int relays, call_length, tax_rate; //inputs //tax_rate//cell_num
	double net_cost, call_tax, total_cost;
	long long cell_num;
	string response="y";

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	while (response == "Y" || response == "y")
	{
		cout << "Welcome to the Call Cost Calculator." << endl;

		cout << "Please type in your cell phone number." << endl;
		cin >> cell_num;
		cout << "The number you typed in is " << cell_num << endl;

		cout << "We will start off by calculating the tax rate. Please put in the number of relay stations used to make the call." << endl;
		cin >> relays;
		cout << "The number of relay stations is" << " " << relays << endl;

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

		cout << "We will now calculate the net cost of the call." << endl;
		cout << "Please type in the length in minutes of your call" << endl;
		cin >> call_length;
		cout << "The length in minutes of your call is " << call_length << endl;

		net_cost = relays / 50.0*0.40*call_length;
		cout << "Your net cost is " << net_cost << "." << endl;

		call_tax = net_cost*tax_rate / 100;
		cout << "Your call tax is " << call_tax << "." << endl;

		/*cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);*/

		total_cost = net_cost+call_tax;
		cout << "Your total cost is " << total_cost << "." << endl;

		cout << "-----------------------------------------------------------" << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "Cell Phone" << "                    " << cell_num << endl;
		cout << "Number of Relay Stations" << "      " << relays << endl;
		cout << "Minutes Used" << "                  " << call_length << endl;
		cout << "Net Cost" << "                    " << net_cost << endl;
		cout << "Call Tax" << "                    " << call_tax << endl;
		cout << "Total Cost of Call" << "          " << total_cost << endl;


		cout << "Would you like to calculate another call? Press Y for yes and N for no." << endl;
		cin >> response; 

	}
	cout << "Goodbye." << endl;
	


	
	return 0; 
}