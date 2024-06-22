#include<iostream>
using namespace std;
class Ticket
{
public:
	int id;
	string time;
	string Class;
	string direction_from;
	string direction_to;
	float price;
	Ticket* next;
	Ticket* prev;
	Ticket(int ID, string Time, string C, string from, string to, float Price)
	{
		id = ID;
		time = Time;
		Class=C;
		direction_from = from;
		direction_to = to;
		price = Price;
	}
};
class Reservation
{
	Ticket* head;
	Ticket* tail;
public:
	Reservation() 
	{
		head = NULL;
		tail = NULL;
	}
	void insert_first(int ID, string Time, string C, string from, string to, float Price)
	{
		Ticket* t = new Ticket(ID, Time, C, from, to, Price);
		t->next = head;
		t->prev = NULL;
		if (head == NULL)
		{
			head = t;
			tail = t;
		}
		else
		{
			head->prev = t;
			head = t;
		}
	}
	void insert_last(int ID, string Time, string C, string from, string to, float Price)
	{
		if (head == NULL)
		{
			insert_first(ID, Time, C, from, to, Price);
		}
		else
		{
			Ticket* t = new Ticket(ID, Time, C, from, to, Price);
			t->next = NULL;
			t->prev = tail;
			tail->next = t;
			tail = t;
		}
	}
	void insert_middle(int item_id,int ID, string Time, string C, string from, string to, float Price)
	{
		if (head == NULL)
		{
			insert_first(ID, Time, C, from, to, Price);
		}
		else
		{
			Ticket* temp = head;
			bool flag = false;
			while (temp != NULL)
			{
				if (temp->id == item_id)
				{
					flag = true;
					Ticket* t = new Ticket(ID, Time, C, from, to, Price);
					t->next = temp->next;
					t->prev = temp;
					temp->next->prev = t;
					temp->next = t;
					break;
				}
				temp = temp->next;
			}
			if (flag == false)
			{
				cout << "This id not found ! " << endl;
			}
		}
	}
	void Traversal()
	{
		Ticket* t = head;
		while (t != NULL)
		{
			cout << t->id << "\t" << t->Class << "\t" << t->direction_from << "\t" << t->direction_to << "\t" << t->time << "\t" << t->price<<" LE" << endl;
			t = t->next;
		}
	}
	void delete_first()
	{
		if (head == NULL)
		{
			cout << "There is no Tickets !" << endl;
		}
		else
		{
			Ticket* temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;
		}
	}
	void delete_last()
	{
		if (head == NULL)
		{
			cout << "There is no Tickets !" << endl;
		}
		else
		{
			Ticket* temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete temp;
		}
	}
	void delete_middle(int item_id)
	{
		if (head == NULL)
		{
			cout << "There is no Tickets !" << endl;
		}
		else
		{
			bool flag = false;
			Ticket* temp = head;
			while (temp != NULL)
			{
				if (temp->id == item_id)
				{
					flag = true;
					temp->next->prev = temp->prev;
					temp->prev->next = temp->next;
					delete temp;
					break;
				}
				temp = temp->next;
			}
			if (flag == false)
			{
				cout << "This id not found !" << endl;
			}
		}
	}
	void search(int id)
	{
		bool flag = false;
		Ticket* t = head;
		while (t != NULL)
		{
			if (t->id == id)
			{
				flag = true;
				cout << t->id << "\t" << t->Class << "\t" << t->direction_from << "\t" << t->direction_to << "\t" << t->time << "\t" << t->price << " LE" << endl;
				break;
			}
			t = t->next;
		}
		if (flag == false)
		{
			cout << "This id not found !" << endl;
		}
	}
	void update(int id, string new_time)
	{
		bool flag = false;
		Ticket* t = head;
		while (t != NULL)
		{
			if (t->id == id)
			{
				flag = true;
				t->time = new_time;
				break;
			}
			t = t->next;
		}
		if (flag == false)
		{
			cout << "This id not found !" << endl;
		}
	}
	void sort()
	{
		Ticket* temp1 = head;
		Ticket* temp2 = head;
		Ticket* temp3 = head->next;

		while (temp1 != NULL)
		{
			while (temp3 != NULL)
			{
				if (temp2->id > temp3->id)
				{
					string Class = temp2->Class;
					string direction_from = temp2->direction_from;
					string direction_to = temp2->direction_to;
					int id = temp2->id;
					float price = temp2->price;
					string  time = temp2->time;

					temp2->Class = temp3->Class;
					temp2->direction_from = temp3->direction_from;
					temp2->direction_to = temp3->direction_to;
					temp2->id = temp3->id;
					temp2->price = temp3->price;
					temp2->time = temp3->time;

					temp3->Class = Class;
					temp3->direction_from = direction_from;
					temp3->direction_to = direction_to;
					temp3->id =id;
					temp3->price = price;
					temp3->time = time;
				}
				temp2 = temp3;
				temp3 = temp3->next;
				
			}

			temp1 = temp1->next;
			temp2 = head;
			temp3 = head->next;
		}
	}
};
int main()
{
	int id,exist_id;
	string time;  
	string Class;
	string direction_from;
	string direction_to;
	float price;
	Reservation res;
	Reservation st;
	char c = 'y';
	int i;
	do
	{
		cout << "\t\t\t\t===========================Main Menu====================" << endl;
		cout << "\t\t\t\t--------------------------------------------------------" << endl;
		cout << "1. Insert First" << endl;
		cout << "2. Insert Last" << endl;
		cout << "3. Insert Middle" << endl;
		cout << "4. Delete First" << endl;
		cout << "5. Delete Last" << endl;
		cout << "6. Delete Middle" << endl;
		cout << "7. Search About an item using ID" << endl;
		cout << "8. Update an ticket using ID " << endl;
		cout << "9. Sort the Ticket By ID" << endl;
		cout << "10. Create Stack by LinkedList" << endl;
		cout << "11. Traversal" << endl;
		cout << "12. Exit" << endl;
		cout << "Enter Your Option : ";
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "Enter ID : ";
			cin >> id;
			cout << "Enter Time : ";
			cin >> time;
			cout << "Enter Direction from : ";
			cin >> direction_from;
			cout << "Enter Direction to :";
			cin >> direction_to;
			cout << "Enter Class : ";
			cin >> Class;
			cout << "Enter Price : ";
			cin >> price;
			res.insert_first(id, time, Class, direction_from, direction_to, price);
			cout << "\t\tDone" << endl;
			break;
		case 2:
			cout << "Enter ID : ";
			cin >> id;
			cout << "Enter Time : ";
			cin >> time;
			cout << "Enter Direction from : ";
			cin >> direction_from;
			cout << "Enter Direction to :";
			cin >> direction_to;
			cout << "Enter Class : ";
			cin >> Class;
			cout << "Enter Price : ";
			cin >> price;
			res.insert_last(id, time, Class, direction_from, direction_to, price);
			cout << "\t\tDone" << endl;
			break;
		case 3:
			cout << "Enter Exist Id : ";
			cin >> exist_id;
			cout << "Enter ID : ";
			cin >> id;
			cout << "Enter Time : ";
			cin >> time;
			cout << "Enter Direction from : ";
			cin >> direction_from;
			cout << "Enter Direction to :";
			cin >> direction_to;
			cout << "Enter Class : ";
			cin >> Class;
			cout << "Enter Price : ";
			cin >> price;
			res.insert_middle(exist_id,id, time, Class, direction_from, direction_to, price);
			cout << "\t\tDone" << endl;
			break;
		case 4:
			res.delete_first();
			break;
		case 5:
			res.delete_last();
			break;
		case 6:
			cout << "Enter Exist Id : ";
			cin >> exist_id;
			res.delete_middle(exist_id);
			break;
		case 7:
			cout << "Enter Exist Id : ";
			cin >> exist_id;
			res.search(exist_id);
			break;
		case 8:
			cout << "Enter Exist Id : ";
			cin >> exist_id;
			cout << "Enter New Time : ";
			cin >> time;
			res.update(exist_id, time);
			break;
		case 9:
			res.sort();
			break;
		case 10:
			
			cout << "1. Push" << endl;
			cout << "2. Pop" << endl;
			cout << "3. Display" << endl;
			cout << "Enter your Choice : ";
			cin >> i;
			switch (i)
			{
			case 1:
				cout << "Enter ID : ";
				cin >> id;
				cout << "Enter Time : ";
				cin >> time;
				cout << "Enter Direction from : ";
				cin >> direction_from;
				cout << "Enter Direction to :";
				cin >> direction_to;
				cout << "Enter Class : ";
				cin >> Class;
				cout << "Enter Price : ";
				cin >> price;
				st.insert_first(id, time, Class, direction_from, direction_to, price);
				cout << "\t\tDone" << endl;
				break;
			case 2:
				st.delete_first();
				break;
			case 3:
				st.Traversal();
				break;
			}
			break;
		case 11:
			res.Traversal();
			break;
		case 12:
			cout << "Thanks For your Time " << endl;
			break;
		default:
			cout << "Thanks For your Time " << endl;
			break;
		}
		cout << "Press y or Y to Continue or any key to Exit : ";
		cin >> c;
	} while (c=='y' || c=='Y');
	cout << "Thanks For your Time " << endl;

}	