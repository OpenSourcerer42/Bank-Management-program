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
	string newRecord[4];
	//input the data into a string array
	cout << "To add a record you must enter the Name, Address, Balance and ID of the account:" << "\n\n";
	cout << "Please enter the Name of the account" << "\n";
	cin.ignore(); // this makes sure that the cin function will include spaces when putting data into the array
	getline(cin, newRecord[0]);
	cout << "Please enter the Address of the account: " << "\n";
	getline(cin, newRecord[1]);
	cout << "Please enter the balance of the account: " << "\n";
	cin >> newRecord[2];
	cout << "Please enter the 4 digit ID of the account: " << "\n";
	cin >> newRecord[3];

	cout << "||  Name,  Address,  Balance,  ID  ||" << "\n";
	cout << "-------------------------------------" << "\n";
	for (int i = 0; i < (sizeof(newRecord)/sizeof(*newRecord)); i++) {
		cout << newRecord[i] << ", ";
	}
	cout << "\n" << "-------------------------------------" << "\n\n";
	int ans;
	cout << "Here are the details to add to the record, are these correct or would you like to input them again? Input again(1) or continue(2):" << "\n\n";
	cin >> ans;
	if(ans == 1) {
		Add();
	} else if (ans == 2) {
		// opens the file in apped mode, adds all elements of the array into a string then adds the string onto the end of the file.
		string input;
		input =  newRecord[0] + "," + newRecord[1] + "," + newRecord[2] + "," + newRecord[3];
		fstream file;
		file.open("test.csv", ios::app);
		file << input << endl;

		cout << "You have successfully added the account to the file." << "\n";
	}
}

void Delete(vector<string> lines) {

	string deleteID;
	cout << "Please enter the ID of the account you would like to delete: " << "\n\n";
	cin >> deleteID;
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
	for (int i = 0; i < (sizeof(bankRecords)/sizeof(*bankRecords)); i++) {
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
			if (count == (sizeof(bankRecords)/sizeof(*bankRecords) - 1)) {
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
	for (int j = 0; j < (sizeof(bankRecords)/sizeof(*bankRecords) - 1); j++) {
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
		Delete(lines);
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
	cout << "3. Delete a specific record." << "\n";
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
