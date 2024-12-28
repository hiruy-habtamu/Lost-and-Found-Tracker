int main();

void CreateAccount(){
    cout << "\t\t\t\t\t\t CREATE ACCOUNT \n\n\n";

    // Assign id to user

    user[last_id][0] = to_string(last_id);


    cout << "Please Enter First Name \n";
    cin >> user[last_id][1];

    cout << "Please Enter Last Name \n";
    cin >> user[last_id][2];

    cout << "Please Enter Password \n";
    cin >> user[last_id][3];

    cout << "Please Enter Department \n";
    cin >> user[last_id][4];

    cout << "Please Enter  Email Address \n";
    cin >> user[last_id][5];

    cout << "Please Enter Phone Number \n";
    cout << "+251 ";
    cin >> user[last_id][6];

    current_id = last_id;

    last_id+=1;

    system("cls");


    main();
}

void SelectAccount(){
    int id;
    string password;
    enter_id:
    cout <<"\t\t\t\t\t\t SELECT ACCOUNT \n\n\n";
    cout <<"Please Enter account id \n";
    cin >> id;

    //check if id exists
    if(user[id][0]==""){
        system("CLS");
        cout << "\t\t **Please Enter a valid id** \n";
        goto enter_id;
    }

    cout <<"Welcome "<<user[id][1]<<"\n";
    cout <<"Please Enter the password\n";
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
void FindLostItem(){

}

void RegisterFoundItem(){

}

void ListItem(){

}

void EditUser() {
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
