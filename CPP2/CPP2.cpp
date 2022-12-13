// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include "CPP2.h"
#include <cstring>
#include <sstream> // this will allow you to use stringstream in your program

//A comment made by jason
//A commnet made again by Jason
using namespace std;
void Search();
void AddAccount();
void Intro();
void SearchStruct();

struct account
{
	string name;
	int ic;
	string place;
	
};


int main() {

	char ch;
	int num;
	Intro();
	do
	{
		system("cls");
		cout << "\n\n\t\tMAIN MENU";
		cout << "\n\t\t01. NEW ACCOUNT";
		cout << "\n\t\t02. SEARCH ACCOUNT";
		cout << "\n\t\t03. SEARCH ACCOUNT BY STRUCT";

		/*
		cout << "\n\t\t03. WITHWithdraw AMOUNT";
		cout << "\n\t\t04. BALANCE ENQUIRY";
		cout << "\n\t\t05. ALL ACCOUNT HOLDER LIST";
		cout << "\n\t\t06. CLOSE AN ACCOUNT";
		cout << "\n\t\t07. Update AN ACCOUNT";
		*/
		cout << "\n\t\t08. EXIT";
		cout << "\n\t\tSelect Your Option (1-8) ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			AddAccount();
			break;
		case '2':
			Search();
			break;
		case '3':
			SearchStruct();
			break;
		case '8':
			cout << "\n\t\tThanks for using bank managemnt system";
			break;
		default:cout << "\a";
		}
		cin.ignore();
		cin.get();
	} while (ch != '8');
	return 0;
}

void Intro()
{
	cout << "\n\t\tMalaysian Account";
	cout << "\n\t\tMANAGEMENT";
	cout << "\n\t\tSYSTEM";
	cout << "\n\nMADE BY : Lu Jason";
	cin.get();
}

//Search without using structure
void Search()
{
	string data[50];
	string line;
	bool isFound = false;

	//Read the txt file first
	ifstream myfile("example.txt");
	if (myfile.is_open())
	{
		int count = 0;
		while (getline(myfile, line))
		{
			//Store the data into data array
			data[count] = line;
			count++;
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}

	//Get the name input for search
	cout << "Please enter the name to search:" << endl;
	string search;
	//clear buffer before taking new
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, search);

	//Loop through the data to find the user's data
	for (int i = 0; i < size(data); i++)
	{
		/*
		std::size_t found = data[i].find(search);
		found = data[i].find(search);
		if (found != std::string::npos)
		{
			isFound = true;
			std::cout << data[i] << found << '\n';
		}

		*/

		//Since we already know the user has 3 info (name,ic,place), therefore we set the length of info become 3
		string info[3];
		int count = 0;
		string s = "";
		//Converting the data into string array
		for (auto x : data[i])
		{
			if (x == ',')
			{
				info[count] = s;
				s = "";
				count++;
			}
			else {
				s = s + x;
				info[count] = s;
			}
		}

		//After converted the data into string array, loop through the string array to find the name is match or not
		//If it is match, then display the relevant data.
		for (int i = 0; i < size(info); i++)
		{
			if (info[0] == search)
			{
				cout << info[i] << endl;
				isFound = true;
			}
		}
	}

	//By using bool to detect if the account is found, if not found then display the account is not found message.
	if (!isFound)
	{
		cout << "No account found" << endl;
	}

}

//Search with struct
void SearchStruct()
{
	string data[50];
	string line;
	bool isFound = false;
	account ac[size(data)];

	//Read the txt file first
	ifstream myfile("example.txt");
	if (myfile.is_open())
	{
		int count = 0;
		while (getline(myfile, line))
		{
			//Store the data into data array
			data[count] = line;

			count++;
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}

	//Get the name input for search
	cout << "Please enter the name to search:" << endl;
	string search;
	//clear buffer before taking new
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, search);

	//Loop through the data to find the user's data
	for (int i = 0; i < size(data); i++)
	{
		string info[3];
		int count = 0;
		string s = "";
		//Converting the data into string array
		for (auto x : data[i])
		{
			if (x == ',')
			{
				info[count] = s;
				s = "";
				count++;
			}
			else {
				s = s + x;
				info[count] = s;
			}
		}

		//Convert string to int
		stringstream ss;
		int num;
		ss << info[1];
		ss >> num;
		ac[i] = { info[0],num,info[2] };
	}

	//Search user 
	for (int i = 0; i < size(ac); i++)
	{
		if (ac[i].name == search)
		{
			cout << "Name:" << ac[i].name << endl;
			cout << "Place:" << ac[i].place << endl;
			cout << "IC:" << ac[i].ic << endl;

		}
	}
}

void AddAccount()
{
	string name;
	string place;
	int ic;
	account ac;

	//Get the name input
	cout << "Please enter name:" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new
	getline(cin, ac.name);

	//Get the place input
	cout << "Please enter place:" << endl;
	getline(cin, ac.place);

	//Get the IC input
	cout << "Please enter IC:" << endl;
	cin >> ac.ic;

	//Combine the data into 1 string variable
	string data = ac.name + "," + std::to_string(ac.ic) + "," + ac.place;

	//Using fstream to write the data into text file
	fstream f;
	ofstream fout;
	ifstream fin;
	fin.open("example.txt");
	fout.open("example.txt", ios::app);
	if (fin.is_open())
		fout << data;
	cout << " Account has been added to file" << endl;
	fin.close();
	fout.close();
}

