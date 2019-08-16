#include <iostream>
using namespace std;

struct user{
    char name[50];
    char sign_in_date[50];
    int number_of_travels ;
    int account;
//    struct travel* user_travels ;
    struct user* next_user ;
}user;

struct travel{
    char origin;
    char destination;
    int price ;
    int date;
    struct travel* next_travel;
}travel;

//function proto-types:
void add_user(struct user** main_head);
void add_travel(struct user** travel_head);
void remove_user(struct user** main_head);
void show_prompt();
void print_a_user_info(struct user* x);
void print_a_travel_info();
void print_all_users_with_numbers(struct user* node);
void print_all_travels_with_numbers(struct travel* a_users_travel_head);// for one user

//global variables:

int main() {
    struct user *head = NULL;
    struct user* new_user = (struct user*)malloc(sizeof(struct user));
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
                cout << "adding a user..." << endl;
                add_user(&head);
                break;
            case 2:
                cout << "adding a travel..." << endl;
//                add_travel();
                break;
            case 3:
                cout << "removing a user..." << endl;
                print_all_users_with_numbers(head);
                if(head)
                    remove_user(&head);
                break;
            case 4:
                cout << "show all users..." << endl;
                print_all_users_with_numbers(head);
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
            " 4) show all users information\n"
            "-1) end of the program\n";
}
void add_user(struct user** head){

    struct user* new_user = (struct user*)malloc(sizeof(struct user));
    struct user *last = *head;

    cout << "please enter the user's name:" << endl;
    cin >> new_user -> name;

    cout << "please enter the user's sign-in date:" << endl;
    cin >> new_user -> sign_in_date;

    cout << "please enter the user's money:" << endl;
    cin >> new_user -> account;

    //set a initial number for user's travel numbers...
    new_user -> number_of_travels = 0;

    new_user->next_user = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head == NULL)
    {
        *head = new_user;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next_user != NULL)
        last = last->next_user;

    /* 6. Change the next of last node */
    last->next_user = new_user;
    return;
}
void add_travel(struct user** head){
    struct travel* new_travel = (struct travel*)malloc(sizeof(struct travel));

    cout << "please enter the travel's origin:" << endl;
    cin >> new_travel -> origin;

    cout << "please enter the travel's destination:" << endl;
    cin >> new_travel -> destination;

    cout << "please enter the travel's price:" << endl;
    cin >> new_travel -> price;

    cout << "please enter the travel's date:" << endl;
    cin >> new_travel -> date;

    //boro bebinam che mikoni =)
}
void remove_user(struct user** head){
    cout << "select a number to delete a user:" << endl;
    int choice_number;// a number from 1 to n
    cin >> choice_number;
    choice_number--;// a number from 0 to n-1

    struct user* temp = *head;
    // if we ar going to delete the first user:
    if (choice_number == 0){
        *head = temp -> next_user;
        free(temp);
        return;
    }
    struct user *next = temp->next_user->next_user;
    // Free memory
    free(temp->next_user);

    temp-> next_user = next;
}

void print_a_user_info(struct user* x){
    cout << "name: " << x -> name << endl;
    cout << "sign-in date: " << x -> sign_in_date << endl;
    cout << "account: " << x -> account << "$" << endl;
}
void print_a_travel_info(struct travel* t){
    cout << "\tfrom \"" << t -> origin << "\" to \"" << t -> destination << "\"" << endl;
    cout << "\tdate: " << t -> date <<  endl;
    cout << "\tprice: " << t -> price << "$" << endl;
}
void print_all_users_with_numbers(struct user* my_head){
    int num = 1;
    if (my_head == NULL){
        cout << "NO USER FOUND!" << endl;
        return;
    }
    struct user* pointer = my_head;
    while (pointer != NULL){
        cout << num << ")-------------" << endl;
        print_a_user_info(pointer);
        pointer = pointer-> next_user;
        num++;
    }
}

void print_all_travels_with_numbers(struct travel* my_head){
    int num = 1;
    if (my_head == NULL){
        cout << "NO TRAVELS FOUND!" << endl;
        return;
    }
    struct travel* pointer = my_head;
    while (pointer != NULL){
        cout << num << ")-------------" << endl;
        print_a_travel_info(pointer);
        pointer = pointer-> next_travel;
        num++;
    }
}