#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
// ----- CURRENCY CONVERTER ----->
/*
 Author: Ankit
 Date: 9-8-2025
 Project: Currency Converter
 Description: It is a console based currency converter tool. 
*/
// ---> UI
void menu()
{
	cout << " <--------------- CURRENCY CONVERTER --------------->\n\t\t ••••••••••••••••••••\n"
		 << endl;
	cout << "\t   💸WELCOME TO CURRENCY CONVERTER💸\n\t   🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺\n"
		 << endl;
	cout << "   1. Convert \t\t\t 2. Currency info\n   3. Edit exchange rate \t 4. Exit\n"
		 << endl;
	cout << " ____________________________________________________\n"
		 << endl;
}
// ---> navigation button
void back_button()
{
	char yes;
	do
	{
		cout << "   Type (y) to back: ";
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
		{
			break;
		}
	} while (yes != 'y' && yes != 'Y');
}
// ---> data structure
// map to store currency code and their exchange rate
map<string, double> rate = {
	{"USD", 1.0},
	{"EUR", 0.8587},
	{"GBP", 0.7445},
	{"JPY", 171.7},
	{"AUD", 1.5334},
	{"CAD", 1.3741},
	{"CHF", 0.9255},
	{"CNY", 7.1838},
	{"INR", 83.9},
	{"ZAR", 19.14},
	{"AED", 3.67250},
	{"SAR", 3.75000},
	{"KRW", 1326},
	{"BRL", 5.48},
	{"MXN", 19.14},
	{"RVB", 0.0128},
	{"THB", 33.30},
	{"PHP", 56.8576},
	{"IDR", 16263.8},
	{"VND", 26222.7},
	{"TRY", 0.025},
	{"MYR", 0.2352},
	{"BND", 1.28496},
	{"NZD", 0.6009},
	{"HKD", 7.79},
	{"SGD", 1.0695},
	{"PKR", 283.549},
	{"PLN", 0.2766},
	{"NOK", 0.0992},
	{"SEK", 0.1053},
	{"DKK", 0.1573}};

// map to store countries name and their currency name
map<string, string> name = {
	{"United States", " Dollar"},
	{"Europe", "Euro"},
	{"British", "Pound"},
	{"Japan", "Yen"},
	{"Australia", "Dollar"},
	{"Canada", "dollar"},
	{"Swiss", "Franc"},
	{"China", "Yuan"},
	{"India", "Rupee"},
	{"South Africa", "Rand"},
	{"VAE", "Dirham"},
	{"Saudi", "Riyal"},
	{"South Korea", "Won"},
	{"Brazil", "Real"},
	{"Mexico", "Peso"},
	{"Russia", "Ruble"},
	{"Thai", "Baht"},
	{"Philippine", "Peso"},
	{"Indonesia ", "Rupiah"},
	{"Vietnam ", "Dong"},
	{"Turkish", "Lira"},
	{"Malaysia", "Ringgit"},
	{"Brunei", "Dollar"},
	{"New Zealand", "Dollar"},
	{"Hong Kong", "Dollar"},
	{"Singapore", "Dollar"},
	{"Pakistan", "Rupee"},
	{"Polish", "Zloty"},
	{"Norwegian", "Krone"},
	{"Swedish", "Krona"},
	{"Danish", "Krone"}

};

// ---> 1. currency convertion
void convert()
{
	// welcome message
	cout << "\t   💸WELCOME TO CURRENCY CONVERTER💸\n\t   🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺\n"
		 << endl;
	// available currency
	cout << "\t  🤑Available countries currency are:-\n\t  -----------------------------------\n"
		 << endl;
	cout << "    ";
	for (auto i : rate)
	{
		cout << i.first << ", ";
	}
	cout << "\n"
		 << endl;
	// variables to store user input
	string currency1, currency2;
	double amount;
	char user;
	do
	{ // loop for continues convertion
		cout << "  Enter Source Currency Code: ";
		cin >> currency1;
		cout << "  Enter Target Currency Code: ";
		cin >> currency2;
		cout << "  Enter Amount: ";
		cin >> amount;
		// processing message
		cout << "\n  Converting💸... \n  Converting💸... \n  Converting💸... \n"
			 << endl;
		// converting user input into upper case
		transform(currency1.begin(), currency1.end(), currency1.begin(), ::toupper);
		transform(currency2.begin(), currency2.end(), currency2.begin(), ::toupper);
		// converting currency
		if (rate.find(currency1) != rate.end() && rate.find(currency2) != rate.end())
		{
			double inusd = amount / rate[currency1];
			double targetcurr = inusd * rate[currency2];
			cout << "  After converting:\n   " << amount << " " << currency1 << " = " << targetcurr << " " << currency2 << "\n"
				 << endl;
		}
		else
		{ // if currency code not found
			cout << " Currency Code Not Fount❗\n"
				 << endl;
		}
		do
		{ // this loop handle wrong input
			cout << "  Do you want to convert again (y/n): ";
			cin >> user;
			cout << endl;
			if (user == 'n' || user == 'N' || user == 'y' || user == 'Y')
			{
				break;
			}
		} while (user != 'n' || user != 'N' || user != 'y' || user != 'Y');
		if (user == 'n' || user == 'N')
		{
			break; // input mached, exit
		}
	} while (user != 'n' && user != 'N');
	back_button(); // back button
}

// ---> 2. Currency info
void currency_info()
{
	// welcome message
	cout << "\t   💸WELCOME TO CURRENCY CONVERTER💸\n\t   🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺\n"
		 << endl;
	// available currency
	cout << "    Here the list of countries currency and\n    their exchange rate:-\n  "
		 << endl;
	cout << "  S.NO.   COUNTRY NAME   CURRENCY NAME\n  -----   ------------   -------------" << endl;

	map<string, string>::iterator it2 = name.begin(); // rate iterator
	for (int i = 0; i < name.size(); i++)
	{ // printing values
		cout << "   " << i + 1 << "  —  " << it2->first << "    —    " << it2->second << endl;
		it2++;
	}
	// currency and rate
	cout << "\n\n   S.NO.   CURRENCY CODE    1USD=RATE\n   -----   -------------    ---------" << endl;
	map<string, double>::iterator it1 = rate.begin(); // name iterator

	for (int i = 0; i < rate.size(); i++)
	{ // printing value
		cout << "   " << i + 1 << "     —    " << it1->first << "       —    " << it1->second << endl;
		it1++;
	}
	// how to convert info
	cout << "\n\n     How to convert❗\n     〰️〰️〰️〰️〰️〰️〰️〰️\n   First, convert the source currency into\n   \"USD\" by using formula\n     USD = Amount/Rate\n   Second, convert the USD currency into\n   targt currency, by using formula\n    target currency=USD currency*target currency rate\n"
		 << endl;
	cout << "     💸THANKS FOR VISIT 💸\n"
		 << endl;
	back_button(); // back button
}

// ---> 3. Edit Exchange Rate
void edit_exchange_rate()
{
	// welcome message
	cout << "\t   💸WELCOME TO CURRENCY CONVERTER💸\n\t   🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺🔺\n"
		 << endl;
	// available currency
	cout << "    Available currency and their currency exchange\n    rate are:-\n  "
		 << endl;
	// print currency code and exchange rate
	cout << "     CURRENCY Code     EXCHANGE RATE(1USD=RATE) \n     -------------     ------------------------" << endl;
	for (auto i : rate)
	{
		cout << "       " << i.first << "\t    —\t \t" << i.second << endl;
	}
	cout << "\n    EDIT EXCHANGE RATE :-\n    --------------------\n"
		 << endl;
	// some variable to store user input
	string currency;
	double exrate;
	char user;
	do
	{ // for continues
		cout << "   Enter Currency code: ";
		cin >> currency;
		// change user input into upper case
		transform(currency.begin(), currency.end(), currency.begin(), ::toupper);
		// processing message
		cout << "\n   searching🔍...\n   searching🔍...\n   searching🔍...\n"
			 << endl;
		if (rate.find(currency) != rate.end())
		{
			cout << "   Currency code founded🤑\n"
				 << endl;
			cout << "    Enter new Exchange rate: ";
			cin >> exrate;
			rate[currency] = exrate; // change exchange rate
			// processing message
			cout << "\n   Updating... \n   Updating... \n   Updating... \n   Update successful 💸🤑\n"
				 << endl;
		}
		else // if currency code not found
		{
			cout << "   Currency code not found. try again later...\n"
				 << endl;
		}
		do
		{ // to handle wrong input
			cout << "   Do you want to Edit more(y/n) :";
			cin >> user;
			cout << endl;
			if (user == 'n' || user == 'N' || user == 'y' || user == 'Y')
			{
				break; // exit loop
			}
		} while (user != 'n' || user != 'N' || user != 'y' || user != 'Y');
		if (user == 'n' || user == 'N')
		{
			break; // exist loop
		}
	} while (user != 'n' && user != 'N');
	back_button(); // back button
}

int main()
{
	int input;
	do
	{
		menu();
		do
		{ // this loop for users wrong input
			cout << "   INPUT: ";
			cin >> input;
			cout << endl;
			if (input > 0 && input <= 4)
			{
				break;
			}
		} while (input <= 0 && input > 4);
		switch (input)
		{
		case 1:
			convert();
			break;
		case 2:
			currency_info();
			break;
		case 3:
			edit_exchange_rate();
			break;
		case 4:
			cout << "            💸THANKS FOR VISIT💸\n            ____________________\n"
				 << endl;
			cout << "   Exiting... \n   Exiting... \n   Exiting... \n"
				 << endl;
			break;
		default:
			cout << "   Enter available input" << endl;
		}

	} while (input != 4);
	return 0;
}