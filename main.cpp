#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Records {
	public:
		string Name;
		string Address;
		double Balance;
		int ID;
};

void Edit() {
	cout << "Edit function";
}

void Delete() {
	cout << "Delete function";
}

void View(vector<string> lines) {

	//Converts the Vector to a string array
    string records[lines.size()];
    std::copy(lines.begin(), lines.end(), records);

	//prints out each line of the CSV ... 
	//TO-DO: split each element of the array into seperate variables storing name, address, balance and ID to store in the class
	for (int i = 0; i < (sizeof(records)/sizeof(*records)); i++) {
		cout << "\n" << records[i] << "\n";
	}
}

void Open(int op) {
	vector<string> lines;
    
    string line;

    fstream file;
	//opens the file, loops through each line and stores the data in a string vector
    file.open("test.csv", ios::in);
    while(!file.eof()) {
        getline(file, line);
        lines.push_back(line);
        if (file.eof()) {
             file.close();
             break;
        }
    }
	//checks which operation was chosen then calls that specific function
	switch(op) {
	case 1:
		View(lines);
		break;
	case 2:
		Edit();
		break;
	case 3:
		Delete();
		break;
	}
}

int main() {
	int operation;

	cout << "\n\n\t\t" << "------------------------------" << "\n";
	cout << "\t\t" << "||  BANK MANAGEMENT SYSTEM  ||" << "\n";
	cout << "\t\t" << "------------------------------" << "\n";
	cout << "\t\t" << " ----------Welcome-----------" << "\n\n\n";
	cout << "Please select which operation you would like to perform: " << "\n\n";
	cout << "1. View all records." << "\n";
	cout << "2. Edit a specific record." << "\n";
	cout << "3. Delete a specific record." << "\n\n";
	cin >> operation;
	cout << "\n\n";

	if (operation > 3) {
		int ans;
		cout << "Error: Please select an available option, would you like to try again? yes(1) or no (2)";
		cin >> ans;
		if (ans == 1) {
			main();
		} else {
			cout << "\n\n\n" << "Exiting .....";
		}
	}

	Open(operation);
	

}
