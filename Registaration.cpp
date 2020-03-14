#include "Registaration.h"
#include <iostream>
#include<string>
#include<iostream>
#include<string>
#include <fstream>
#include <list>



	list<user>lisusers;
	const string filname = "Uzers.txt";



	int init()
	{

		ifstream fin;
		fin.open(filname);

		bool isopen = fin.is_open();

		if (isopen == false) {
			cout << "Error" << endl;
		}
		else {
			user tempuser;
			int count = 0;
			string temp;
			while (!fin.eof()) {
				count++;
				fin >> temp;
				if (count == 1) {
					tempuser.name = temp;
					
				}
				else if (count == 2) {
					tempuser.gmail = temp;

				}
				else if (count == 3) {
					tempuser.pasword = temp;
					lisusers.push_back(tempuser);
					count = 0;
					
				}
			}
		}
		return 0;
	}

	int center()
	{
		init();
		int a;

		cout << "1.Registration" << endl;
		cout << "2.Login" << endl;
		cout << "3.Exit" << endl;
		cout << "Selekt funktion->";
		do {
			cin >> a;
			switch (a)
			{
			case 1:

				registration();
				Login();
				break;
			case 2:
				Login();
				break;
			case 3:
				cout << "Bye!" << endl;
				
				break;
			}
		} while (a != 3);
		
		return 0;
	}


	int registration()
	{

		user newuser;
		cout << "Enter user name->";
		cin >> newuser.name;
		cout << "Enter user email->";
		cin >> newuser.gmail;
		cout << "Enter password->";
		cin >> newuser.pasword;
		system("cls");
		lisusers.push_back(newuser);
		cout << "Registrstion was secssesful!" << endl;
		ofstream fout;
		fout.open(filname, fstream::app);
		bool isopen = fout.is_open();
		if (isopen == false) {
			cout << "Eror file cant open " << endl;
		}
		else {


			fout << newuser.name << endl;
			fout  << newuser.gmail << endl;
			fout  << newuser.pasword << endl;
			cout << endl;
		}

		return 0;
		
	}

	int Login()
	{
		    int a;
			
			string login;
			string pasword;
			
				cout << "Enter your login->";
				cin >> login;
				cout << "Enter your pasword->";
				cin >> pasword;
				system("cls");
			for(user item:lisusers){
					if (login == item.gmail && pasword == item.pasword) {

						cout << "Name->" << item.name << endl;
						break;
					}
					
					
		    }
			do {
				cout << "1.Try agin" << endl;
				cout << "2.Exit" << endl;
				cin >> a;
				system("cls");
				switch (a)
				{
				case 1:
					Login();
					break;
				case 2:
					center();
					break;
				}
			} while (a != 2);

				
			
			

		

		return 0;
	}

	

