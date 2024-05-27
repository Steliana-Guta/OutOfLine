// Example C++ Arrays of students
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class Student
{
	char name[10];    // details of student
	char studID[8];
public:
	Student(const char* n, const char* ID); // constructor
	char* getName();  // returns name
	char* getID();     // returns ID
};
class StudentList
{
	Student* group[10]; // space for 10 students
public:

	StudentList();            // populate list - better from file
	Student* findStudent(const char* studID); // search given ID. returns null if not found

};
int main()
{
	const char* target1 = "0101111";
	const char* target2 = "0321103";
	StudentList s;
	Student* result = NULL;
	cout << s.findStudent(target1)->getName() << "\n" << endl;
	s.findStudent(target2);
	system("PAUSE");
	return 0;
}
Student::Student(const char* n, const char* ID) // constructor
{
	strcpy_s(name, n);
	strcpy_s(studID, ID);
}
char* Student::getName()   // returns name
{
	return name;
}
char* Student::getID()     // returns ID
{
	return studID;
}
StudentList::StudentList()            // populate list - better from file
{
	const char* names[] = { "Mary", "Jill", "Bill", "Mohammed", "Tom","Mike", "Vijay", "Shona", "Maria", "Tony" };
	const char* sids[] = { "0101111", "0101112", "0101145", "0221341", "0213213","9987654", "9899872", "0023451", "0200022", "9900123" };
	for (int i = 0; i < 10; i++)
	{
		group[i] = new Student(names[i], sids[i]);
	}
}
Student* StudentList::findStudent(const char* studID)
{
	Student* theStudent = NULL;  // for the student found
	int id = 0;   // index for search

	while (id <= 9 && theStudent == NULL)   // until whole array  or student found.
	{
		if (strcmp(studID, group[id]->getID()) == 0)  // check studID against array
		{
			theStudent = group[id];
		}
		id++;
	}
	if (theStudent == NULL)
	{
		cout << "NULL\n" << endl;
	}
	else return theStudent;  // either student found or null
}

