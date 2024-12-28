int main();

void CreateAccount(){
    cout << "\t\t\t\t\t\t CREATE ACCOUNT \n\n\n";

    // Assign id to user

    user[last_id][0] = last_id;


    cout << "Please Enter First Name \n";
    cin.ignore();
    getline(cin, user[last_id][1]);

    cout << "Please Enter Last Name \n";
    getline(cin, user[last_id][2]);

    cout << "Please Enter Password \n";
    getline(cin, user[last_id][3]);

    cout << "Please Enter Department \n";
    getline(cin, user[last_id][4]);

    cout << "Please Enter Email Address \n";
    getline(cin, user[last_id][5]);

    cout << "Please Enter Phone Number \n";
    cout << "+251 ";
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
    cout << "\t\t\t\t\t\t REGISTER FOUND ITEM \n\n\n";

    cout << "Enter name of the item: ";
    cin.ignore();
    getline(cin,item[last_item_id][0]);

    cout << "Enter place you found the item: ";
    getline(cin,item[last_item_id][1]);

    cout << "Enter the day you found the item: ";
    getline(cin,item[last_item_id][2]);

    item[last_item_id][3] = user[current_id][5];
    item[last_item_id][4] = "+251 " + user[current_id][6];
    current_item_id = last_item_id;
    last_item_id++;
    system("CLS");
}

void ListItem(){

}

void EditUser(){

}

