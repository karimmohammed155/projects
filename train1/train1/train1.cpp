#include<iostream>
#include<fstream>
using namespace std;
class Traveller
{
protected:
	int id;
	string name;
	int size;
	Traveller* t;
public:
	Traveller()
	{

	}
	Traveller(int Size)
	{
		size = Size;
		t = new Traveller[size];
	}
	void Add_to_file(int ID, string Name)
	{
		ofstream write;
		write.open("Travellers.txt", ios::app);
		write << ID << "\t" << Name << endl;
		write.close();
	}
	void Print()
	{
		ifstream read;
		read.open("Travellers.txt");
		int i = -1;
		while (!read.eof())
		{
			++i;
			read >> t[i].id >> t[i].name;
			if (read.eof())
				break;
			cout << t[i].id << "\t" << t[i].name << endl;
		}
		read.close();
	}
	void Search_about_traveller(int ID)
	{
		ifstream read;
		read.open("Travellers.txt");
		int i = -1;
		bool check = false;
		while (!read.eof())
		{
			++i;
			read >> t[i].id >> t[i].name;
			if (t[i].id == ID)
			{
				cout << t[i].id << "\t" << t[i].name << endl;
				check = true;
				break;
			}
			if (read.eof())
				break;
		}
		read.close();
		if (check == false)
		{
			cout << "This Traveller doesn't exist!" << endl;
		}
	}
	void Search_about_traveller(string name) // overloading function
	{
		ifstream read;
		read.open("Travellers.txt");
		int i = -1;
		bool check = false;
		while (!read.eof())
		{
			++i;
			read >> t[i].id >> t[i].name;
			if (t[i].name == name)
			{
				cout << t[i].id << "\t" << t[i].name << endl;
				check = true;
				break;
			}
			if (read.eof())
				break;
		}
		read.close();
		if (check == false)
		{
			cout << "This Traveller doesn't exist!" << endl;
		}
	}
};
class Train :public Traveller // inheritance
{
	string direction_from;
	string direction_to;
	Train* t;
public:
	Train()
	{

	}
	Train(int Size)
	{
		size = Size;
		t = new Train[size];
	}
	void Add_to_file(int ID, string from, string to)
	{
		ofstream write;
		write.open("Train.txt", ios::app);
		write << ID << "\t" << from << "\t" << to << endl;
		write.close();
	}
	void Print()
	{
		ifstream read;
		read.open("Train.txt");
		int i = -1;
		while (!read.eof())
		{
			++i;
			read >> t[i].id >> t[i].direction_from >> t[i].direction_to;

			if (read.eof())
				break;
			cout << t[i].id << "\t" << t[i].direction_from << "\t" << t[i].direction_to << endl;
		}
		read.close();
	}
	void Search_about_train(int ID)
	{
		ifstream read;
		read.open("Train.txt");
		int i = -1;
		bool check = false;
		while (!read.eof())
		{
			++i;
			read >> t[i].id >> t[i].direction_from >> t[i].direction_to;
			if (t[i].id == ID)
			{
				cout << t[i].id << "\t" << t[i].direction_from << "\t" << t[i].direction_to << endl;
				check = true;
				break;
			}
			if (read.eof())
				break;
		}
		read.close();
		if (check == false)
		{
			cout << "This Train doesn't exist!" << endl;
		}
	}
	void Search_about_train(string Direction_from, string Direction_to) // overloading function
	{
		ifstream read;
		read.open("Train.txt");
		int i = -1;
		bool check = false;
		while (!read.eof())
		{
			++i;
			read >> t[i].id >> t[i].direction_from >> t[i].direction_to;
			if (t[i].direction_from == Direction_from && t[i].direction_to == Direction_to)
			{
				cout << t[i].id << "\t" << t[i].direction_from << "\t" << t[i].direction_to << endl;
				check = true;
			}
			if (read.eof())
				break;
		}
		read.close();
		if (check == false)
		{
			cout << "This Train doesn't exist!" << endl;
		}
	}
};
class Tickets :public Traveller
{
private:
	string datetime;
	int train_id;
	int traveller_id;
	float price;
	Tickets* t;
public:
	Tickets()
	{

	}
	Tickets(int Size)
	{
		size = Size;
		t = new Tickets[size];
	}
	void Save_to_file(int Traveller_ID, int Train_ID, string DateTime, float Price)
	{
		ofstream write;
		write.open("Tickets.txt", ios::app);
		write << Traveller_ID << "\t" << Train_ID << "\t" << DateTime << "\t" << Price << endl;
		write.close();
	}
	void Print()
	{
		ifstream read;
		read.open("Tickets.txt");
		int i = -1;
		while (!read.eof())
		{
			++i;
			read >> t[i].traveller_id >> t[i].train_id >> t[i].datetime >> t[i].price;

			if (read.eof())
				break;
			cout << t[i].traveller_id << "\t" << t[i].train_id << "\t" << t[i].datetime << "\t" << t[i].price << endl;
		}
		read.close();
	}
};
int main()
{
	Tickets ticket(20);
	Traveller travel(20);
	Train train(20);
	int Traveller_id;
	int train_id;
	string from, to;
	string datetime;
	string name;
	float price;
	int c;
	do
	{
		cout << "1. Travellers" << endl;
		cout << "2. Trains" << endl;
		cout << "3. Tickets" << endl;
		cout << "Choose one : ";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "1. Add Traveller" << endl;
			cout << "2. Search about Traveller by ID " << endl;
			cout << "3. Search about Traveller by Name " << endl;
			cout << "4. Display Travellers" << endl;
			cout << "Choose one : ";
			cin >> c;
			switch (c)
			{
			case 1:
				cout << "Enter Id : ";
				cin >> Traveller_id;
				cout << "Enter Name : ";
				cin >> name;
				travel.Add_to_file(Traveller_id, name);
				break;
			case 2:
				cout << "Enter Id : ";
				cin >> Traveller_id;
				travel.Search_about_traveller(Traveller_id);
				break;
			case 3:
				cout << "Enter Name : ";
				cin >> name;
				travel.Search_about_traveller(name);
				break;
			case 4:
				travel.Print();
				break;
			}
			break;
		case 2:
			cout << "1. Add Train" << endl;
			cout << "2. Search about Train by ID " << endl;
			cout << "3. Search about Trains by Directions " << endl;
			cout << "4. Display Trains" << endl;
			cout << "Choose one : ";
			cin >> c;
			switch (c)
			{
			case 1:
				cout << "Enter ID : ";
				cin >> train_id;
				cout << "Ener Direction from : ";
				cin >> from;
				cout << "Enter Direction to : ";
				cin >> to;
				train.Add_to_file(train_id, from, to);
				break;
			case 2:
				cout << "Enter ID : ";
				cin >> train_id;
				train.Search_about_train(train_id);
				break;
			case 3:
				cout << "Enter Direction From : ";
				cin >> from;
				cout << "Enter Direction to : ";
				cin >> to;
				train.Search_about_train(from, to);
				break;
			case 4:
				train.Print();
				break;
			}
			break;
		case 3:
			cout << "1. Add Ticket" << endl;
			cout << "2. Display Tickets" << endl;
			cout << "Choose one : ";
			cin >> c;
			switch (c)
			{
			case 1:
				cout << "Enter Traveller ID : ";
				cin >> Traveller_id;
				cout << "Enter Train ID : ";
				cin >> train_id;
				cout << "Enter DateTime : ";
				cin >> datetime;
				cout << "Enter Price : ";
				cin >> price;
				ticket.Save_to_file(Traveller_id, train_id, datetime, price);
				break;
			case 2:
				ticket.Print();
				break;
			}
			break;
		}
		cout << "press any key if you want to continue or press 0 to exit : ";
		cin >> c;
	} while (c != 0);
}