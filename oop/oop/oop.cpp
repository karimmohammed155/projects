#include <iostream>
#include <string>
using namespace std;
class person
{
protected:   //access modifier for inheritance
	int id;
	string name;
	int age;
	friend void set_get(person &s, int i, string n, int a); // friend function
public:
	person() // default constructor
	{
		id = 0;
		name = "  ";
		age = 0;
	}
	person(int i, string n,int a) // parametarized constructor
	{
		id = i;
		name = n;
		age = a;
	}
	void set(int i, string n, int a) // set function
	{
		id = i;
		name = n;
		age = a;
	}
	void set(string n, int a, int i) // set function (overloading function)
	{
		id = i;
		name = n;
		age = a;
	}
	bool search(int i) // search function
	{
		if (id == i)
			return true;
		else
			return false;
	}
	void get() // get function
	{
		cout << "name : " << name << "\n" << "id : " << id << "\n" << "age : " << age << "\n";
	}
	int operator ++(int) // +1 operator for id 
	{
		return id++;
	}
	int operator --(int) // -1 operator for id
	{
		return id--;
	}
	bool operator >(person& s) // bigger than operator for age
	{
		if (age > s.age)
			return true;
		else
			return false;
	}
	int operator +(person& s) // sum operator for age
	{
		return age += s.age;
	}
};
void set_get(person &s, int i, string n, int a)  // friend function
{
	s.id = i;
	s.name = n;
	s.age = a;
	cout << s.id << "\t" << s.name << "\t" << s.age << endl;
}
class student:public person // child class (inheritance)
{
	float gpa;
public:
	student() // default constructor
	{
		id = 0;
		name = "  ";
		age = 0;
		gpa = 0.0;
	}
	student(int i, string n, int a, float g)  // parametarized constructor
	{
		id = i;
		name = n;
		age = a;
		gpa = g;
	}
	void set(int i, string n, int a, float g) // set function (overriding function)
	{
		id = i;
		name = n;
		age = a;
		gpa = g;
	}
	void get() // get function (overriding function) 
	{
		cout << "name : " << name << "\n" << "id : " << id << endl;
		cout << "age : " << age << "\n" << "gpa : " << gpa << endl;
	}
};
int main()
{
	student e,e1;
	e1.set(7, "karim", 20, 3.5);
	e1++; // +1 operator for id
	e1.get();
	cout << "                                     " << endl;
	e.set(8, "omar", 30, 3.2);
	e--; // -1  operator for id
	e.get();
	cout << "                                     " << endl;
	cout << e.operator>(e1) << endl; // bigger than operator for age
	cout << e.operator+(e1) << endl; // sum operator for age
	set_get(e1, 5, "abdo", 70);     // friend function
	cout << "                                     " << endl;
	/////////////////////////////////////////////////////////////////////////////////
	person e2[2];								             //
	e2[0].set("ali", 60, 42);					             //
	e2[1].set(43, "ahmed", 50);	// overloading	             //     Array of object
	e2[0].get();								             //
	cout << "                                     " << endl; //
	e2[1].get();											 //
	cout << "                                     " << endl; //
	/////////////////////////////////////////////////////////////////////////////////
	int ids;									  //
	string names;								  //
	int agee;									  //
	float gpaa;									  //
	int size;									  //
	cout << "enter size :" << endl;				  //
	cin >> size;								  //
	student* e3 = new student[size];			  //
	for (int i = 0; i < size; i++)				  //
	{											  //
		cout << "enter id :" << endl;			  //	 Dynamic array of object
		cin >> ids;								  //
		cout << "enter name :" << endl;			  //
		cin >> names;							  //
		cout << "enter age :" << endl;			  //
		cin >> agee;							  //
		cout << "enter gpa :" << endl;			  //
		cin >> gpaa;							  //
		e3[i].set(ids, names,agee , gpaa);		  //      
	}											  //
	cout << "                           " << endl;//	
	for (int i = 0; i < size; i++)				  //
	{											  //
		e3[i].get();							  //
	}											  //
	/// ///////////////////////////////////////////////////////////////////////
}
