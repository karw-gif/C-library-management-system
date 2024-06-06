#include <iostream>
#include <string>
#include <vector>

using namespace std;

//creating a class called Manuals to store Manualss 
class Manuals {
private:
    string workTitle;
    string numbers;
    string writers;
    bool borrowed;
	
public:
    Manuals(string n, string t, string a) : workTitle(n), numbers(t), writers(a),borrowed(false){}
    
    // printing the workTitle ,numbers and writers of the Manuals 
    void input() {
        cout << "Enter the workTitle, numbers and writers: " << endl;
        cin >> workTitle >> numbers >> writers;
    }

    void display() const {
    
        cout << workTitle << " " << numbers << " " << writers << endl;
    }
    string gettitles() const { return workTitle; }
    string getnumbers() const { return numbers; }
    string getwriters() const { return writers; }
   
    bool getborrowed() const { return borrowed; }
    void setborrowed(bool status) { borrowed = status; }
};

//creating a class called Person to store Person details 
class Person {
private:
    string workTitle;
    string firstname;
    string secondname;

public:
    Person(string n, string t, string a) : workTitle(n), firstname(t), secondname(a) {} //store the values in a constructor

//printing the workTitle ,firstname and secondname of a Person 
    void input() {
        cout << "Input the workTitle, firstname and secondname: " << endl;
        cin >> workTitle >> firstname >> secondname;
    }

    void display() const {
        cout << workTitle << " " << firstname << " " << secondname << endl;
    }

	string gettitles() const {return workTitle;}
	string getadmno() const {return firstname;}
	string getsecondname() const {return secondname;}
};

//creating a class called librarian to store Library details 
class Librarian {
private:
    vector<Manuals> Manualss;
    vector<Person> People;
    vector<Manuals> borrowedManualss; // vector for borrowed Manualss
    vector<Manuals> returnedManualss; // vector for returned Manualss

public:

//displays all the Manualss available 
    void showManualss() const { 
        for (size_t i = 0; i < Manualss.size(); ++i) {
            Manualss[i].display();
        }
    }


//adds a new Person 
    void addPerson(const Person& Person) { 
        People.push_back(Person);
    }
 //adds a new Manuals 
    void addManuals(const Manuals& Manuals) { 
        Manualss.push_back(Manuals);
    }

//displays all the People 
    void showPeople() const { 
        for (size_t i = 0; i < People.size(); ++i) {
        	
            People[i].display();
        }
    }
    
    //searches for a Manuals that has been input
    void searchManuals(const string& searchTerm) const {
        bool found = false;
        for (size_t i = 0; i < Manualss.size(); ++i) {
            if (Manualss[i].gettitles() == searchTerm || Manualss[i].getnumbers() == searchTerm || Manualss[i].getwriters() == searchTerm) {
                Manualss[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No Manuals found with the search term: " << searchTerm << endl;
        }
    }
    //searches for Person 
    void searchPerson(const string& searchTerm) const {
        bool found = false;
        for (size_t i = 0; i < Manualss.size(); ++i) {
            if (People[i].gettitles() == searchTerm || People[i].getadmno() == searchTerm || People[i].getsecondname() == searchTerm) {
                People[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No Person found with the search term: " << searchTerm << endl;
        }
    }
    //borrows a Manuals if it exists 
    void borrowManuals(const string& searchTerm) {
        for (size_t i = 0; i < Manualss.size(); ++i) {
            if ((Manualss[i].gettitles() == searchTerm || Manualss[i].getnumbers() == searchTerm || Manualss[i].getwriters() == searchTerm) && !Manualss[i].getborrowed()) {
                Manualss[i].setborrowed(true);
                cout << "Manuals borrowed successfully." << endl;
                return;
            }
        }
        cout << "Manuals not available for borrowing." << endl;
    }

//returns Manuals that was borrowed 
    void returnManuals(const string& searchTerm) {
        for (size_t i = 0; i < Manualss.size(); ++i) {
            if ((Manualss[i].gettitles() == searchTerm || Manualss[i].getnumbers() == searchTerm || Manualss[i].getwriters() == searchTerm) && Manualss[i].getborrowed()) {
                Manualss[i].setborrowed(false);
                cout << "Manuals returned successfully." << endl;
                return;
            }
        }
        cout << "Manuals not found or already returned." << endl;
    }
 
};
	


int main(){
    string workTitle, numbers, writers,searchTerm;
    int choice;
    Librarian library;

    while (true) {
         cout << "Enter the choice you want"<<endl;
         cout<<"7: Add a Manuals"<<endl;
		 cout<<"2: Show all Manualss"<<endl;
		 cout<<"5: Add a Person"<<endl;
		 cout<<"8: Show People"<<endl;
         cout<<"6: Search Manuals by workTitle, numbers or writers"<<endl;
		 cout<<"3: Search person by workTitle, firstname or lib no"<<endl;
		 cout<<"1: Borrow a Manuals"<<endl;
		 cout<<"4: Return a Manuals"<<endl;
		 cout<<"0: exit"<<endl;
         cin >> choice;

        switch(choice){
        case 7:{
            cout << "Enter the workTitle, numbers and writers: " << endl;
            cin >> workTitle >> numbers >> writers;
            Manuals newManuals(workTitle, numbers, writers);
            library.addManuals(newManuals);
            break;
            }
        case 2:{
            library.showManualss();
            break;
            }
        case 5:{
            cout << "Enter the workTitle, numbers and writers: " << endl;
            cin >> workTitle >> numbers >> writers;
            Person addPerson(workTitle, numbers, writers);
            library.addPerson(addPerson);
            break;
            }
		case 8:{
            library.showPeople();
            break;
            }
        case 6:{
            cout << "Enter the workTitle, numbers or writers to search: ";
            cin >> searchTerm;
            library.searchManuals(searchTerm); 
            break;
            }
        case 3:{
            cout << "Enter the workTitle, firstname or secondname to search: ";
            cin >> searchTerm;
            library.searchPerson(searchTerm);   
            break; 
            }
	    case 1:{
            cout << "Enter the workTitle, numbers or writers of the Manuals to borrow: ";
            cin >> searchTerm;
            library.borrowManuals(searchTerm);
            break;
            }
        case 4:{
            cout << "Enter the workTitle, numbers or writers of the Manuals to return: ";
            cin >> searchTerm;
            library.returnManuals(searchTerm); 
            break;	
            }		
		case 0:{
            break;
            }
		default:{
		  cout << "choose corectly" << endl;
        }
    }
    }

    return 0;
};