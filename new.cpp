#include <iostream>
#include <string>
using namespace std;
// Structure to represent a patient
struct Patient {
    int id;
    string first_name;
    string last_name;
    int age;
    string condition;
    Patient* next;
};
Patient *head = NULL;
int checkForId(int id);
//Function to create new patient
Patient * createPatient (){
	Patient *patient = new Patient;
	cout<<"\n Enter ID : ";
	cin>>patient->id;
	patient->id=checkForId(patient->id);
	cout<<"\n Enter First Name : ";
	cin>>patient->first_name;
	cout<<"\n Enter Last Name : ";
	cin>>patient->last_name;
	cout<<"\n Enter Age : ";
	cin>>patient->age;
	cout<<"\n Enter Condition : ";
	cin>>patient->condition;
	cout<<endl;
	patient->next = NULL;
	return patient;
}

int checkForId(int id){
	if (head == NULL) {
        return id;
    }
    Patient* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
        	cout<<" Enter another ID ID = "<<id<<" is taken \n";
			cin>>id;
			checkForId(id);
        }
        temp = temp->next;
    }
    return id;
}

// Function to add a node at the beginning of the list
void addPatientAtBeginning(){
	Patient* newPatient = createPatient();
	if(head == NULL)
		head = newPatient;
	else{
    newPatient->next = head;
    head = newPatient;}
}
// Function to add a node at the end of the list
void addPatientAtEnd(){
	Patient* newPatient = createPatient();
	if(head == NULL)
		head = newPatient;
	else if(head->next == NULL)
		head->next = newPatient;
	else{
		Patient *temp = head;
		while(temp->next != head)
		temp = temp->next;
		temp->next = newPatient;
	}
}
// Function to add a node after a specific node
void addPatientAfter(){
	if(head == NULL)
		cout<<"\n List is empty.\n";
	else{
		int targetID;
    	cout << "\n Enter the target ID of the patient : ";
    	cin >> targetID;
		Patient *temp = head;
		bool found = false;
		while(temp!= NULL){
			if(temp->id == targetID){
				Patient *temp1 = temp->next;
				Patient	*newPatient = createPatient();
				temp->next = newPatient;
				newPatient->next = temp1;
				found = true;
				break;
			}
		temp = temp->next;
		}
		if (found)
        	cout << "\n Successfully added the patient after patient ID = "<<targetID<<".\n";
    	else
        	cout << "\n Patient with the specified ID not found.\n";
	}
}
// Function to add a node before a specific node
void addPatientBefore() {
    if (head == NULL) {
        cout << "\n List is empty.\n";
        return;
    }
    int targetID;
    	cout << "\n Enter the target ID of the patient : ";
    	cin >> targetID;
    if (head->id == targetID) {
        addPatientAtBeginning();
        return;
    }
    Patient *temp = head;
    bool found = false;
    while (temp->next != NULL) {
        if (temp->next->id == targetID) {
            Patient *newPatient = createPatient();
            newPatient->next = temp->next;
            temp->next = newPatient;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (found)
        cout << "\n Successfully added the patient before the specified node.\n";
    else
        cout << "\n Patient with the specified ID not found.\n";
}
// Function to update specific node information
void updatePatient() {
    if (head == NULL) {
        cout << "\n List is empty.\n";
        return;
    }
    int id;
    cout << "\n Enter ID of the patient to update: ";
    cin >> id;

    Patient *temp = head;
    bool found = false;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "\n Enter new information for the patient:\n";
            cout << "Enter First Name: ";
            cin >> temp->first_name;
            cout << "Enter Last Name: ";
            cin >> temp->last_name;
            cout << "Enter Age: ";
            cin >> temp->age;
            cout << "Enter Condition: ";
            cin >> temp->condition;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found)
        cout << "\n Patient information updated successfully.\n";
    else
        cout << "\n Patient with the specified ID not found.\n";
}
// Function to delete the first node from the list
void deleteFirstPatient(){
	if (head == NULL) {
        cout << "\n List is empty.\n";
        return;
    }
    Patient *temp = head;
    head = head->next;
    delete temp;
    cout << "\n First patient deleted successfully.\n";
}
// Function to delete the last node from the list
void deleteLastPatient(){
	if (head == NULL) {
        cout << "\n List is empty.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "\n Last patient deleted successfully.\n";
        return;
    }
    Patient *temp = head;
    Patient *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
    cout << "\n Last patient deleted successfully.\n";
}
// Function to delete any node by searching
void deletePatient(){
	   if (head == NULL) {
        cout << "\n List is empty.\n";
        return;
    }
    int targetID;
    cout << "\n Enter the ID of the patient to delete: ";
    cin >> targetID;
    Patient *temp = head;
    Patient *prev = NULL;
    bool found = false;
    while (temp != NULL) {
        if (temp->id == targetID) {
            found = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (found) {
        if (prev == NULL) {
            // Deleting the first node
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "\n Patient with ID " << targetID << " deleted successfully.\n";
    } else {
        cout << "\n Patient with ID " << targetID << " not found.\n";
    }
}
//************Displaying Function**************//
void displayList(){
	 Patient *temp = head;
	if (temp == NULL){
        cout << "\n List is empty. No patients to display.\n" << endl;
        return;
    }
    cout << "\n Patient List:" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << ", First Name: " << temp->first_name <<",  Last Name: " << temp->last_name << ", Age: " << temp->age << ", Condition: " << temp->condition << endl;
        temp = temp->next;
    }
    cout << "---------------------------------------------------------------------------------------" << endl;
}
// Function to swap the data of two patient
void swapPatients(Patient* a, Patient* b) {
    int tempId = a->id;
    string tempFirstName = a->first_name;
    string tempLastName = a->last_name;
    int tempAge = a->age;
    string tempCondition = a->condition;

    a->id = b->id;
    a->first_name = b->first_name;
    a->last_name = b->last_name;
    a->age = b->age;
    a->condition = b->condition;

    b->id = tempId;
    b->first_name = tempFirstName;
    b->last_name = tempLastName;
    b->age = tempAge;
    b->condition = tempCondition;
}
// Function to sort the patient list by ID in ascending order
void sortById() {
    if (head == NULL || head->next == NULL) {
        // No need to sort if the list is empty or has only one node
        return;
    }

    bool swapped;
    Patient* current;
    Patient* last = NULL;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->id > current->next->id) {
                swapPatients(current, current->next);
                swapped = true;
            }
            current = current->next;
        }

        last = current;
    } while (swapped);

    cout << "\n Patient list sorted by ID in ascending order.\n";
}
// Function to sort the patient list by first name in ascending order
void sortByFirstName() {
    if (head == NULL || head->next == NULL) {
        // No need to sort if the list is empty or has only one node
        return;
    }

    bool swapped;
    Patient* current;
    Patient* last = NULL;

    do {
        swapped = false;
        current = head;
        while (current->next != last) {
            if (current->first_name > current->next->first_name) {
                swapPatients(current, current->next);
                swapped = true;
            }
            current = current->next;
        }

        last = current;
    } while (swapped);

    cout << "\nPatient list sorted by first name in ascending order.\n";
}
// Function to sort the patient list by last name in ascending order
void sortByLastName() {
    if (head == NULL || head->next == NULL) {
        // No need to sort if the list is empty or has only one node
        return;
    }

    bool swapped;
    Patient* current;
    Patient* last = NULL;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->last_name > current->next->last_name) {
                swapPatients(current, current->next);
                swapped = true;
            }
            current = current->next;
        }

        last = current;
    } while (swapped);

    cout << "\nPatient list sorted by last name in ascending order.\n";
}
// Function to search for a patient by ID
void searchById() {
    if (head == nullptr) {
        cout << "List is empty. No patients to search." << endl;
        return;
    }
    int targetId;
    cout << "Enter the ID of the patient you want to search for: ";
    cin >> targetId;
    
    Patient* temp = head;
    bool found = false;
    
    while (temp != nullptr) {
        if (temp->id == targetId) {
            cout << "Patient found!" << endl;
            cout << "ID: " << temp->id << ", First Name: " << temp->first_name << ", Last Name: " << temp->last_name << ", Age: " << temp->age << ", Condition: " << temp->condition << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    
    if (!found) {
        cout << "Patient with ID " << targetId << " not found in the list." << endl;
    }
}
// Function to search for list items by first name
void searchByFirstName() {
    if (head == NULL) {
        cout << "\nList is empty. No patients to search.\n";
        return;
    }

    string targetFirstName;
    cout << "\nEnter the first name to search for: ";
    cin >> targetFirstName;

    Patient* temp = head;
    bool found = false,flag = true;

    while (temp != NULL) {
        if (temp->first_name == targetFirstName) {
        	if(flag)
            cout << "\nPatient found:\n";
            cout << "ID: " << temp->id << ", First Name: " << temp->first_name << ", Last Name: " << temp->last_name << ", Age: " << temp->age << ", Condition: " << temp->condition << endl;
            found = true;
            flag = false;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "\nNo patients found with the specified first name.\n";
    }
}
// Function to search for list items by last name
void searchByLastName() {
    if (head == NULL) {
        cout << "\nList is empty. No patients to search.\n";
        return;
    }

    string targetLastName;
    cout << "\nEnter the last name to search for: ";
    cin >> targetLastName;

    Patient* temp = head;
    bool found = false,flag = true;

    while (temp != NULL) {
        if (temp->last_name == targetLastName) {
        	if(flag)
            cout << "\nPatient found:\n";
            cout << "ID: " << temp->id << ", First Name: " << temp->first_name << ", Last Name: " << temp->last_name << ", Age: " << temp->age << ", Condition: " << temp->condition << endl;
            found = true;
            flag = false;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "\nNo patients found with the specified last name.\n";
    }
}
int main(){
	int repeat = 0, choice= 0,choice1;
	while(repeat==0){
		cout<<"============================";
		cout << "\nPatient Management System" << endl;
		cout<<"===========================\n";
        cout << "1. Add a node at the beginning" << endl;
        cout << "2. Add a node at the end" << endl;
        cout << "3. Add a node after a specific Patient" << endl;
        cout << "4. Add a node before a specific Patient" << endl;
        cout << "5. Update node information" << endl;
        cout << "6. Delete the first Patient" << endl;
        cout << "7. Delete the last Patient" << endl;
        cout << "8. Delete specific Patient" << endl;
        cout << "9. Sort Patient list"<<endl;
        cout << "10. Search for  Patient"<<endl;
        cout << "11. Display all Patient" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        	case 1: 
				addPatientAtBeginning();
				break;
			case 2: 
				addPatientAtBeginning();
				break;
			case 3:
				addPatientAfter();
				break;
			case 4:
				addPatientBefore();
				break;
			case 5:
				updatePatient();
				break;
			case 6:
				deleteFirstPatient();
				break;
			case 7:
				deleteLastPatient();
				break;
			case 8:
				deletePatient();
				break;
			case 9:
				cout << "1. Sort by ID" << endl;
  				cout << "2. Sort by First Name" << endl;
 				cout << "3. Sort by Last Name" << endl;
  			  	cout << "Enter your choice: ";
  				cin >> choice1;
  				 switch (choice1) {
        			case 1: 
						sortById();
						break;
					case 2:
						sortByFirstName();
						break;
					case 3:
						sortByLastName();
						break;
					default:
						cout<<"Invalid choice";
						}
    			break;
    		case 10:
				cout << "1. Search by ID" << endl;
  				cout << "2. Search by First Name" << endl;
 				cout << "3. Search by Last Name" << endl;
  			  	cout << "Enter your choice: ";
  				cin >> choice1;
  				 switch (choice1) {
        			case 1: 
						searchById();
						break;
					case 2:
						searchByFirstName();
						break;
					case 3:
						searchByLastName();
						break;
					default:
						cout<<"Invalid choice";
						}
    			break;
			case 11:
				displayList();
				break;
			case 0:
				repeat=1;
				break;
		}
	}
}



