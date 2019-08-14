#include <iostream>
using namespace std;
struct user{
    string name;
    string sign_in_date = 0;
    int number_of_travels = 0;
    struct travel* user_travels = NULL;
    struct user* next_user = NULL;
}user;

struct travel{
    string origin;
    string destination;
    int money = 0;
    struct travel* next_travel = NULL;
}travel;

//function proto-types:
void add_user(struct user** main_head);
void add_travel();
void remove_user();
void show_prompt();
void print_a_user_info();
void print_a_travel_info();

//global variables:

int main() {
    struct user *head;

    int command;
    while(true){
        show_prompt();
        cin >> command;
        //defining a sentinel for our loop
        if (command == -1){
            cout << "end of the program";
            break;
        }
        switch (command){
            case 1:
                add_user();
                break;
            case 2:
                add_travel();
                break;
            case 3:
                remove_user();
                break;
            default:
                cout << "bad input!" << endl;
                break;
        }
    }
    return 0;
}
void show_prompt(){
    cout << "Enter a command:" << endl;
    cout << " 1) add a user\n"
            " 2) add a travel\n"
            " 3) remove a user\n"
            "-1) end of the program\n";
}
void add_user(struct user** head){
    cout << "adding a user..." << endl;

    struct user* new_user = (struct user*)malloc(sizeof(struct user));

    string temp_name;
    cout << "please enter the user's name:" << endl;
    cin >> temp_name;
    new_user -> name = temp_name;

    string temp_sign_in_date;
    cout << "please enter the user's sign-in date:" << endl;
    cin >> temp_sign_in_date;
    new_user -> sign_in_date = temp_sign_in_date;

}
void add_travel(){
    cout << "adding a travel..." << endl;
    string temp_origin;
    cout << "please enter the user's name:" << endl;
    cin >> temp_origin;
    //

    string temp_destination;
    cout << "please enter the user's sign-in date:" << endl;
    cin >> temp_destination;
    //
}
void remove_user(){
    cout << "removing a user..." << endl;
}
void print_a_user_info(struct user* x){
    cout << "name: " << x -> name << endl;
    cout << "sign-in date: " << x -> sign_in_date << endl;
    cout << "travels: " << endl;
}
void print_a_travel_info(struct travel* t){
    cout << "\tfrom \"" << t -> origin << "\" to \"" << t -> destination << "\"" << endl;
    cout << "\tprice: " << t -> money << "$" << endl;
}