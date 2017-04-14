#include<string>
#include<iostream>
#include<fstream>
using namespace std;

//write studentType class
class studentType{
public:
    string fname;
    string lname;
    int ID;
    string city;
};
//write NodeType struct
struct nodeType{
    studentType student;
    nodeType* next;
};
//write specification for UnsortedType
class UnsortedListType{
public:
    void insertMid(int);
    UnsortedListType();
    void insertEnd(studentType);
    void insertFront(studentType);
    void printList();
    ~UnsortedListType();
private:
    nodeType* first;
};
UnsortedListType::UnsortedListType() //constructor
{
    first = NULL; //initialize first node in list
}
//write implementation
void UnsortedListType::insertMid(int count) //add node to middle of list
{
    nodeType* temp;
    temp = new nodeType; //create new node
    temp->student.lname = "Keeling"; //set values for student
    temp->student.fname = "Harry";
    temp->student.ID = 20;
    temp->student.city = "Dallas";
    nodeType* current = first; //set current to start of list
    for (int i = 1; i<(count / 2); i++) //find middle of list
    {
        current = current->next; //go from one node to the next
    }
    temp->next = current->next; //have the new node point to the next node in the list
    current->next = temp; //have the node before the next node point to the node you just created
    
}

void UnsortedListType::insertEnd(studentType newstudent)
{
    
    nodeType* current = first; //set current to the start of the list
    if (first != NULL)
    {
        while (current->next != NULL) //find end of list
        {
            current = current->next; //go from one node to the next
        }
        current->next = new nodeType; //create new node
        current = current->next; //set current to the node you jut created
        current->student.fname = newstudent.fname; //set values for student
        current->student.lname = newstudent.lname;
        current->student.ID = newstudent.ID;
        current->student.city = newstudent.city;
        current->next = NULL; //set next pointer to NULL
    }
    else //set the node as the beginnging of the list
    {
        current = new nodeType; //create new node
        current->student.fname = newstudent.fname; //set values for student
        current->student.lname = newstudent.lname;
        current->student.ID = newstudent.ID;
        current->student.city = newstudent.city;
        current->next = NULL; //set next to NULL
        first = current; //make it first node in list
    }
}

void UnsortedListType::insertFront(studentType newstudent)
{
    if (first != NULL)
    {
        nodeType* current = new nodeType; //create new node
        current->student.fname = newstudent.fname; //set values for student
        current->student.lname = newstudent.lname;
        current->student.ID = newstudent.ID;
        current->student.city = newstudent.city;
        current->next = first; //have the node you just created connect to the current start of the list
        first = current; //set the node you just created as the new front of the list
    }
    else //set the node as the beginnging of the list
    {
        nodeType* current = new nodeType; //create new node
        current->student.fname = newstudent.fname; //set values for student
        current->student.lname = newstudent.lname;
        current->student.ID = newstudent.ID;
        current->student.city = newstudent.city;
        current->next = NULL; //set next pointer to NULL
        first = current;  //make it first node in list
    }
    
}

void UnsortedListType::printList()
{
    nodeType* current = first; //set current to front of list
    while (current->next != NULL) //keep going until end of list
    {
        cout << current->student.fname << " "; //print values for current student
        cout << current->student.lname << " ";
        cout << current->student.ID << " ";
        cout << current->student.city << endl;
        current = current->next; //move to next node
    }
}
UnsortedListType::~UnsortedListType()
{
    //create a pointer and set it to the second node in the list
    //keep going until you get to the end of the list
    //go from one node to the next
    for (nodeType* hold_next = first->next; hold_next->next != NULL; hold_next = hold_next->next)
    {
        delete first; //delete first element
        first = hold_next; // make next element first in the list
    }
}
int main()
{
    UnsortedListType studentlist; //create Unsorted list object
    studentType a_student; //create student object
    ifstream reader; //create variable to read file
    int count = 0; //create variable to keep track of nodes in list
    reader.open("infile.txt"); //open file
    reader >> a_student.lname >> a_student.fname >> a_student.ID >> a_student.city; //priming read
    while (reader) //read until file is finished
    {
        if (a_student.ID % 2 == 0) //if ID is even
            studentlist.insertFront(a_student); //add to front
        else //if ID is odd
            studentlist.insertEnd(a_student); //add to end
        count++; //keep track of number of nodes in list
        reader >> a_student.lname >> a_student.fname >> a_student.ID >> a_student.city; //read data for next student
    }
    studentlist.insertMid(count); //add middle studen to list
    studentlist.printList(); //print student list
    return 0;
}

/*Sol Remeaux, 10 Annapolis
 Mary Robinson, 8 Vienna
 Claude Claire, 6 Diego
 Wilson Joan, 4 Frederick
 Stan Jackson, 2 Baltimore
 Harry Keeling 20 Dallas
 Jill Herold, 1 Washington
 Francis Jerry, 3 Woodbridge
 Stanley Smith, 5 Angeles
 Santino Rodriguez, 7 Fresno
 Amelia Elliot, 9 Carrolton
 Press any key to continue . . .
	*/
