#include <iostream>

using namespace std;

string user[100000][7]={{}};
string item[100000][6]={{}};
int current_id,last_id = 0;
int current_item_id,last_item_id = 0;
#include "function.h"

//                    0      1            2           3              4            5            6
// For user[x][7] = "id","First Name","Last Name","Password","Department","Email Address","Phone Number"

// x is used to go through each user
// y is used to access information about each user
// The value of user[0][0] = "0"
//              user[1][0] = "2" meaning id == each row
//last_id is used to create an account
//current_id is used to point at the row of the selected user

//                    0     1        2             3             4                    5
// For item[x][6] = "id","Name","Description","Location","Date/Time of loss","Contact Information"
// current_item_id is used to access the item
// last_item_id is used to log lost item
int main()
{
    char choice;
    if(user[0][0] ==""){
            main_menu:
            cout << "\t\t\t\t\t\t LOST AND FOUND TRACKER \n\n\n" << endl;
            cout << "1. Create Account \n" << endl;
            cout << "2. Select Account \n" <<endl;
            cout << "3. Exit \n" << endl;

            cin >> choice;
            switch(choice){
                case '1':
                    system("CLS");
                    CreateAccount();
                    break;

                case '2':
                    if(user[0][1]==""){
                            system("CLS");
                            cout << "There are no Accounts \n\n\n";
                            main();
                    }
                    else{
                            system("CLS");
                            SelectAccount();
                    }
                    break;

                case '3':
                    system("CLS");
                    return 0;
                    break;
                default:
                    system("CLS");
                    cout << "\t\t***Please Enter a valid choice***\n\n\n" << endl;
                    main();
                    }
            }
    else{
        cout << "\t\t\t\t\t\t LOST AND FOUND TRACKER \n\n\n" << endl;
        cout << "\t\t Id: " << user[current_id][0] << endl;
        cout << "\t\t Name: " << user[current_id][1]<<" "<<user[current_id][2]<<"\n\n\n" << endl;
        cout << "1. Find Lost Item \n" << endl;
        cout << "2. Register Found Items \n" << endl;
        cout << "3. Search items \n" << endl;
        cout << "4. Edit user contact information \n" << endl;
        cout << "5. Return to Main Menu \n" << endl;

        cin >> choice;
        switch(choice){
            case '1':
                system("cls");
                FindLostItem();
                break;
            case '2':
                system("cls");
                RegisterFoundItem();
                break;
            case '3':
                system("cls");
                SearchItem();
                break;
            case '4':
                system("cls");
                EditUser();
                break;
            case '5':
                system("cls");
                goto main_menu;
                break;
            default:
                system("cls");
                cout <<"**Please Enter a valid choice**";
                main();
                break;
        }
    }
    return 0;
}
