int main();
void ListItem();

void CreateAccount(){
    cout << "\n===============================================\n" << endl;
    cout << "                 CREATE ACCOUNT                 \n" << endl;
    cout << "===============================================\n\n" << endl;

    // Assign id to user

    user[last_id][0] = to_string(last_id);


    cout << "Please Enter First Name: ";
    cin.ignore();
    getline(cin, user[last_id][1]);

    cout << "Please Enter Last Name: ";
    getline(cin, user[last_id][2]);

    cout << "Please Enter Password: ";
    getline(cin, user[last_id][3]);

    cout << "Please Enter Department: ";
    getline(cin, user[last_id][4]);

    cout << "Please Enter Email Address: ";
    getline(cin, user[last_id][5]);

    cout << "Please Enter Phone Number: ";
    cout << "+251-";
    getline(cin, user[last_id][6]);

    current_id = last_id;

    last_id+=1;

    system("cls");


    main();
}

void SelectAccount(){
    int id;
    string password;
    enter_id:
    cout << "\n===============================================\n" << endl;
    cout << "                  LOG IN                     \n" << endl;
    cout << "===============================================\n\n" << endl;
    cout <<"Please Enter account id: ";
    cin >> id;

    //check if id exists
    if(user[id][0]==""){
        system("CLS");
        cout << "\t\t **Please Enter a valid id** \n";
        goto enter_id;
    }

    cout <<"Welcome "<<user[id][1]<<"\n";
    cout <<"Please Enter the password: ";
    cin >> password;

    if(password!= user[id][3]){
        system("CLS");
        cout << "\t\t\t **Incorrect Password** \n";
        goto enter_id;
    }
    else{
        current_id = id;
        system("cls");
        main();
    }
}
void FindLostItem() {

    cout << "\n";
    cout << "===============================================\n";
    cout << "             FIND LOST ITEM                   \n";
    cout << "===============================================\n\n";

    int choice;

    cout << "Choose search method: \n";
    cout << "1. Search by Item ID\n";
    cout << "2. Search by Item Name\n";
    cout << "3. Exit to Main Menu\n";
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int id;
            cout << "Enter ID of the item: ";
            cin >> id;
            system("CLS");

            if (id < 0 || id >= last_item_id || item[id][0] == "") {
                cout << "\nInvalid ID - please enter a valid ID." << endl;
            } else {
                cout << "\n";
                cout << "\n===============================================" << endl;
                cout << "               Found Item Details             " << endl;
                cout << "===============================================" << endl;
                cout << "\nName: " << item[id][1] << endl;
                cout << "Description: " << item[id][2] << endl;
                cout << "Place found: " << item[id][3] << endl;
                cout << "Date found: " << item[id][4] << endl;
                cout << "Email: " << item[id][5] << endl;
                cout << "Phone Number: " << item[id][6] << endl;
            }
            break;
        }
        case 2: {
            string name;
            cout << "Enter name of the item: ";
            cin.ignore();
            getline(cin, name);
            system("CLS");

            bool found = false;
            for (int i = 0; i < last_item_id; i++) {
                if (item[i][1] == name) {
                    cout << "\n";
                    cout << "\n===============================================" << endl;
                    cout << "               Found Item Details             " << endl;
                    cout << "===============================================" << endl;
                    cout << "\nName: " << item[i][1] << endl;
                    cout << "Description: " << item[i][2] << endl;
                    cout << "Place found: " << item[i][3] << endl;
                    cout << "Date found: " << item[i][4] << endl;
                    cout << "Email: " << item[i][5] << endl;
                    cout << "Phone Number: " << item[i][6] << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "\nItem not found with the name \"" << name << "\"." << endl;
            }
            break;
        }
        case 3:
            cout << "Returning to Main Menu..." << endl;
            main();
            break;
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
            FindLostItem();
            break;
    }

    int next_choice;
    cout << "\n\n0. Return to Main Menu" << endl;
    cout << "1. Search again" << endl;
    cout << "2. Exit Program" << endl;
    cout << "Choice: ";
    cin >> next_choice;
    system("CLS");

    switch (next_choice) {
        case 0:
            main();
            break;
        case 1:
            FindLostItem();
            break;
        case 2:
            cout << "Exiting program..." << endl;
            exit(0);
            break;
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
            FindLostItem();
            break;
    }
}


void RegisterFoundItem(){
    cout << "\n===============================================\n" << endl;
    cout << "              REGISTER FOUND ITEM              \n" << endl;
    cout << "===============================================\n\n" << endl;

    item[last_item_id][0] = last_item_id;

    cout << "Enter Name of the item: ";
    cin.ignore();
    getline(cin,item[last_item_id][1]);

    cout << "Enter Description of the item: ";
    getline(cin,item[last_item_id][2]);

    cout << "Enter Place you found the item: ";
    getline(cin,item[last_item_id][3]);

    cout << "Enter the Day you found the item: ";
    getline(cin,item[last_item_id][4]);

    item[last_item_id][5] = user[current_id][5];
    item[last_item_id][6] = "+251-" + user[current_id][6];
    current_item_id = last_item_id;

    last_item_id++;

    system("CLS");

    main();
}

void ListItem(){
    if (last_item_id == 0) {
        cout << "No items have been registered yet.\n\n";
    } else {
        cout << "\n\t\t\tList of Lost Items\n";
        cout << "--------------------------------------------------------------------\n";
        cout << "ID\tName\t\tDescription\t\tLocation\t\tDate/Time\t\tContact Info\n";
        cout << "--------------------------------------------------------------------\n";

        for (int i = 0; i < last_item_id; ++i) {
            cout << item[i][0] << "\t"          // ID
                 << item[i][1] << "\t\t"       // Name
                 << item[i][2] << "\t\t"       // Description
                 << item[i][3] << "\t\t"       // Location
                 << item[i][4] << "\t\t"       // Date/Time
                 << item[i][5] << endl;        // Contact Info
        }
        cout << "--------------------------------------------------------------------\n";
    }

    cout << "\nPress Enter to return to the main menu...";
    cin.ignore();
    cin.get();
    system("CLS");


}

void EditUser() {
    cout << "\n===============================================\n" << endl;
    cout << "                  EDIT USER                     \n" << endl;
    cout << "===============================================\n\n" << endl;
    string input;

    // Track if any update was made

    bool isUpdated = false;
    //clears leftovers from the above files
     cin.ignore();

    //updates the user's information or keep the current as the user's choice

    cout << "Current First Name: " << user[current_id][1] << "\nEnter new First Name (leave blank to keep current): ";
    getline(cin, input);
    if (!input.empty()) {
        user[current_id][1] = input;
        isUpdated = true;
    }

    cout << "Current Last Name: " << user[current_id][2] << "\nEnter new Last Name (leave blank to keep current): ";
    getline(cin, input);
    if (!input.empty()) {
        user[current_id][2] = input;
        isUpdated = true;
    }

    cout << "Current Password: " << user[current_id][3] << "\nEnter new Password (leave blank to keep current): ";
    getline(cin, input);
    if (!input.empty()) {
        user[current_id][3] = input;
        isUpdated = true;
    }

    cout << "Current Department: " << user[current_id][4] << "\nEnter new Department (leave blank to keep current): ";
    getline(cin, input);
    if (!input.empty()) {
        user[current_id][4] = input;
        isUpdated = true;
    }

    cout << "Current Email Address: " << user[current_id][5] << "\nEnter new Email Address (leave blank to keep current): ";
    getline(cin, input);
    if (!input.empty()) {
        user[current_id][5] = input;
        isUpdated = true;
    }

    cout << "Current Phone Number: +251 " << user[current_id][6]
         << "\nEnter new Phone Number (leave blank to keep current, format: 9XXXXXXXX): +251 ";
    getline(cin, input);
    if (!input.empty()) {
        user[current_id][6] = input;
        isUpdated = true;
    }
    //checks if there is anything updated
    if (isUpdated) {
        cout << "\nUser information updated successfully!\n";
    } else {
        cout << "\nNo changes were made.\n";
    }
    cout << "\nPress Enter to return to the main menu...";
    system("CLS");
    main();
}
