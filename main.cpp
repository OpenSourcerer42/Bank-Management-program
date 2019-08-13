#include <iostream>
#include <fstream>
#include <sstream>
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

void Add() {
	cout << "Add function";
}

void Delete() {
	cout << "Delete function";
}

void Edit() {
	cout << "Edit function";
}


void View(vector<string> lines) {

	//Converts the Vector to a string array
    string records[lines.size()];
    std::copy(lines.begin(), lines.end(), records);

	//initializes an array of the class Records to store each record
	Records bankRecords[lines.size() - 1];
	string sTmp, tmp;
	int count = 0;

	// this loop will split each record in the array into name, address, balance and ID, and then store it in the bankRecords array
	for (int i = 0; i < (sizeof(records)/sizeof(*records)); i++) {
		sTmp = records[i];
		stringstream ss(sTmp);
		vector<string> result;

		while(getline(ss, tmp, ',')) {
			result.push_back(tmp);
		}

		string arrTmp[result.size()];
		std::copy(result.begin(), result.end(), arrTmp);
		//if statement to skip the title of the csv file as that is not needed
		if (i >= 1) {
			bankRecords[count].Name = arrTmp[0];
			bankRecords[count].Address = arrTmp[1];
			bankRecords[count].Balance = stod(arrTmp[2]);
			bankRecords[count].ID =	stoi(arrTmp[3]);
			if (count == 3) {
				break;
			}
			count++;
		} 

	}
	//outputs each record that was in the csv file from the class array and its members 
	cout << "-----------------------------------------------" << "\n";
	cout << "||----------------- Records -----------------||" << "\n";
	cout << "-----------------------------------------------" << "\n\n";
	cout << "Name | " << "Address | " << "Balance | " << "ID" << "\n";
	cout << "-----------------------------------------------" << "\n\n";
	for (int j = 0; j < 3; j++) {
		cout << bankRecords[j].Name << " | ";
		cout << bankRecords[j].Address << " | ";
		cout << bankRecords[j].Balance << " | ";
		cout << bankRecords[j].ID << "\n";
		cout << "-----------------------------------------------" << "\n";
		cout << "\n\n";
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
	case 4:
		Add();
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
	cout << "4. Add a record." << "\n\n";
	cin >> operation;
	cout << "\n\n";

	if (operation > 4) {
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
