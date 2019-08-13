#include <iostream>
using namespace std;
struct user{
    string name;
    int sign_in_date = 0;
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
void add_user();
void add_travel();
void remove_user();
void show_prompt();
void print_a_user_info();
void print_a_travel_info();

int main() {
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
void add_user(){
    cout << "adding a user..." << endl;
}
void add_travel(){
    cout << "adding a travel..." << endl;
}
void remove_user(){
    cout << "removing a user..." << endl;
}
void print_a_user_info(){

}
void print_a_travel_info(){

}