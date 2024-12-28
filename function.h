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
void FindLostItem() {
     cout << "\n";
    cout << "===============================================\n";
    cout << "             FIND LOST ITEM                   \n";
    cout << "===============================================\n\n";

    int id; // store the ID
    int choice;

    cout << "Enter ID of the item: ";
    cin >> id;

    if (id < 0 || id >= last_item_id || item[id][0] == "") {
        cout << "\nInvalid ID - please enter a valid ID." << endl;
//        system("CLS");
//        ListItem();
    }
    else{
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


    cout << "\n\n0. Return to Main Menu" << endl;
    cout << "1. Search again" << endl;
    cout << "2. Exit Program" << endl;
    cout << "choice: ";
    cin >> choice;
    system("CLS");
    switch(choice){
    case 0:
        main();
        break;
    case 1:
        FindLostItem();
        break;
    case 2:
        cout << "Exiting program..." << endl;
        exit(0);
    default:
        cout << "Invalid choice! Please enter a valid option." << endl;
        FindLostItem();
    }
    if (choice == 0) {
        main();
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

}

void EditUser(){

}

