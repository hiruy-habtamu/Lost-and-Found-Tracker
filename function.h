int main();

void CreateAccount(){
    cout << "\t\t\t\t\t\t CREATE ACCOUNT \n\n\n";

    // Assign id to user

    user[last_id][0] = last_id;


    cout << "Please Enter First Name \n";
    cin >> user[last_id][1];

    cout << "Please Enter Last Name \n";
    cin >> user[last_id][2];

    cout << "Please Enter Password \n";
    cin >> user[last_id][3];

    cout << "Please Enter Department \n";
    cin >> user[last_id][4];

    cout << "Please Enter Email Address \n";
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
    int choice;
    int fd[100000]={};
    bool found{false};
    cout << "\t\t\t\t\t\t FIND LOST ITEM \n\n\n";
    cout<<"Enter name of the item: ";
    cin.ignore();
    getline(cin,lost[last_lost_id][0]);
    cout<<"Enter place you lost the item: ";
    getline(cin,lost[last_lost_id][1]);
    cout<<"Enter the day you lost the item: ";
    getline(cin,lost[last_lost_id][2]);
    current_lost_id = last_lost_id;
    last_lost_id++;
    system("CLS");
    cout << "\t\t\t\t\t\t FIND LOST ITEM \n\n\n";
    for(int j=0;j<last_item_id;j++){
        if(lost[current_id][0]==item[j][0]||lost[current_id][1]==item[j][1]){
            fd[j]=j;
            found=true;
        }
    }
//    if(!found){
//    cout<<"SORRY-No item with this discribtion\n";
//
//    }
//    else{
//        cout<<"ID\t\tNAME\t\tPLACE\t\tDATE\t\tEMAIL\t\tPHONE-NUMBER"<<endl;
//        for(int k=0;k<)
//        cout<<j+1<<"\t\t"<<item[j][0]<<"\t\t"<<item[j][1]<<"\t\t"<<item[j][2]
//            <<"\t\t"<<item[j][3]<<"\t\t"<<item[j][4]<<endl;
//    }
    cout << "\n\n0. Return to Main Menu \n" << endl;
    cin>>choice;
    switch(choice){
    case '0':
        system("CLS");
        main();
        break;
    default:
        system("cls");
        main();

    }

}

void RegisterFoundItem(){
    cout << "\t\t\t\t\t\t REGISTER FOUND ITEM \n\n\n";

    cout<<"Enter name of the item: ";
    cin.ignore();
    getline(cin,item[last_item_id][0]);
    cout<<"Enter place you found the item: ";
    getline(cin,item[last_item_id][1]);
    cout<<"Enter the day you found the item: ";
    getline(cin,item[last_item_id][2]);
    item[last_item_id][3] = user[current_id][5];
    item[last_item_id][4] = "+251 " + user[current_id][6];
    current_item_id = last_item_id;
    last_item_id++;
    system("CLS");
    main();
}

void ListItem(){
    int choice;
    cout << "\t\t\t\t\t\t LIST ITEMS \n\n\n";
    if(last_item_id==0){
        cout<<"EMPTY-No list to display\n";
    }
    else{
    cout<<"ID\t\tNAME\t\tPLACE\t\tDATE"<<endl;
    for(int i=0;i<last_item_id;i++){
        cout<<i+1<<"\t\t"<<item[i][0]<<"\t\t"<<item[i][1]<<"\t\t"<<item[i][2]<<endl;
    }
    }
    cout << "\n\n0. Return to Main Menu \n" << endl;
    cin>>choice;
    switch(choice){
    case '0':
        system("CLS");
        main();
        break;
    default:
        system("cls");
        main();

    }
}

void EditUser(){

}

