#include <iostream>
#include<bits/stdc++.h>
/*
 * algorithm class home work number 1
 * Amirhossein Alibakhshi
 * Negin Hajisobhani
 * */
using namespace std;

struct travel{
    char origin[50];
    char destination[50];
    int money;
    int date;
    struct travel *next_travel;
};
struct user{
    int number;
    char name[50];
    int sign_in_date;
    int number_of_travels;
    int money; //amirhossein
    struct user* next;
    struct travel* user_travels;
};

/////////prototypes
struct user *create_user();
void add_user(struct user *head,struct user *new_user);
void add(struct user *head);
struct travel *create_travel();
void add_travel_node(struct travel *travelHead,struct travel *new_travel);
int user_search(struct user *head);
void add_travel(struct user *head);
void show_all_users(struct user *head);
void show_trip_details(struct user *head);
void show_everything(struct user *head);

void print_a_user_info(struct user* x);//amirhossein
void show_prompt();//amirhossein
void swap(int *xp, int *yp);//amirhossein
void bubbleSort(int arr[], int n);//amirhossein
void give_discount_by_travel_numbers(struct user* head , int n);//amirhossein
void give_discount_by_date(struct user* head , int n);//amirhossein
void remove_user(struct user** head);
void delete_node(struct user *deleted,struct user *head);//negin
void delete_user(struct user *head);//negin
void add_money(struct user *head);//negin
void add_money_2(struct user *user,struct travel *travel);//negin

//main:
int main() {//amirhossein
    struct user *head=(struct user *)malloc(sizeof(struct user));
    head->next=NULL;
    int command;
    int n = 0;
    while(true){
        show_prompt();
//        cout << "n = " << n;
        cin >> command;
        //defining a sentinel for our loop
        if (command == -1){
            cout << "end of the program";
            break;
        }
        switch (command){
            case 1:
                cout << "adding a user..." << endl;
                add(head);
                n++;
                cout << "user added\n";
                break;
            case 2:
                cout << "adding a travel..." << endl;
                add_travel(head);
                break;
            case 3:
                cout << "removing a user..." << endl;
                delete_user(head);
                n--;
                break;
            case 4:
                cout << "show all users..." << endl;
                show_all_users(head);
                break;
            case 5:
                cout << "travel info..." << endl;
                show_trip_details(head);
                break;
            case 6:
                cout << "giving discount to k users with minimum travels..." << endl;
                give_discount_by_travel_numbers(head,n);
                break;
            case 7:
                cout << "giving discount to k users by sign in date..." << endl;
                give_discount_by_date(head,n);
                break;
            case 8:
                cout << "adding money to your account..." << endl;
                add_money(head);
                break;
            case 9:
                cout << "showing EVERYTHING!" << endl;
                show_everything(head);
                break;
            default:
                cout << "bad input!" << endl;
                break;
        }
    }
    return 0;
}

struct user *create_user(){//negin
    struct user *new_user=(struct user *)malloc(sizeof(struct user));
    cout <<"enter your name\n";
    cin >>new_user->name;
    cout<<"enter your sign in date\n";
    cin>>new_user->sign_in_date;
    new_user->number_of_travels=0;
    cout<<"enter your money\n";//amirhossein
    cin>>new_user->money;//amirhossein
    struct travel *user_travel=(struct travel *)malloc(sizeof(struct travel));
    user_travel->next_travel=NULL;
    new_user->user_travels=user_travel;
    cout<<"create done\n";
    return new_user;
}
void add_user(struct user *head,struct user *new_user){//negin
    int counter=0;
    struct user *current=head;
    while(current->next != NULL){
        current = current->next;
        counter++;
    }
    new_user->next=current->next;
    current->next=new_user;
    new_user->number=(counter+1);
    cout<<"add user done\n";
}

void add(struct user *head){//negin
    struct user *new_user=create_user();
    add_user(head,new_user);
}

struct travel *create_travel(){//negin
    struct travel *new_travel=(struct travel *)malloc(sizeof(struct travel));
    cout<<"enter your origin\n";
    cin>>new_travel->origin;
    cout<<"enter your destination\n";
    cin>>new_travel->destination;
    cout<<"enter the price\n";
    cin>>new_travel->money;
    cout<<"enter the date of travel\n";
    cin>>new_travel->date;
    return new_travel;
}

void add_travel_node(struct travel *travelHead,struct travel *new_travel){//negin
    struct travel *current=travelHead;
    while(current->next_travel!=NULL){
        current = current->next_travel;
    }
    //cout<<"hi2\n";
    new_travel->next_travel=current->next_travel;
    current->next_travel=new_travel;
    cout<<"add TRAVEL done\n";
}

void add_travel(struct user *head){
    int userNumber=user_search(head);
    cout<<userNumber<<endl;
    if(userNumber==-1){
        cout<<"user does not exist\n";
    }else {
        struct user *current=head;
        if(head->next!=NULL){
            do{
                current=current->next;
            } while(userNumber != current->number);
            struct travel *new_travel=create_travel();
            add_travel_node(current->user_travels,new_travel);
            if((new_travel->money) > (current->money)){
                cout<<"You don't have enough money,please add money to your account\n";
                add_money_2(current,new_travel);
                current->money =(current->money - new_travel->money);
            }else{
                current->money =(current->money - new_travel->money);
            }
            (current->number_of_travels)++;
        }else{
            cout<<"no user exists\n";
        }
    }
}

int user_search(struct user *head){//negin
    int found=0;
    struct user *current=head;
    char name[50];
    cout<<"enter your name\n";
    cin>>name;
    while(current!=NULL){
        if(strcmp(current->name,name)==0){
            found++;
            return current->number;
        }
        current=current->next;
    }if(found==0){
        cout<<"user not found\n";
        return -1;
    }

}
void print_a_user_info(struct user* x){
    cout << "name: " << x -> name << endl;
    cout << "sign-in date: " << x -> sign_in_date << endl;
    cout << "number of travels: " << x -> number_of_travels << endl;
    cout << "account: " << x -> money << "$" << endl;
}

void show_all_users(struct user *my_head){//amirhossein
    int num = 1;
    if (my_head == NULL){
        cout << "NO USER FOUND!" << endl;
        return;
    }
    struct user* pointer = my_head -> next;
    while (pointer != NULL){
        cout << num << ")-------------" << endl;
        print_a_user_info(pointer);
        pointer = pointer-> next;
        num++;
    }
}
void remove_user(struct user** head){
    cout << "select a number to delete a user:" << endl;
    int choice_number;// a number from 1 to n
    cin >> choice_number;
    choice_number--;// a number from 0 to n-1

    struct user* temp = *head;
    // if we ar going to delete the first user:
    if (choice_number == 0){
        *head = temp -> next;
        free(temp);
        return;
    }
    struct user *next = temp->next->next;
    // Free memory
    free(temp->next);

    temp-> next = next;
}

void show_trip_details(struct user *head) {
    int userNumber = user_search(head);
    cout << userNumber << endl;
    if (userNumber == -1) {
        cout << "user does not exist\n";
    } else {
        struct user *current = head;
        if (head->next != NULL) {
            do {
                current = current->next;
            } while (userNumber != current->number);
            struct travel *travelHead=current->user_travels;
            struct travel *now=travelHead->next_travel;
            if(now==NULL){
                cout<<"No travel exists\n";
            }else{
                int i = 1;
                while(now!=NULL){//amirhossein
                    cout<<"\n"<<i<<")--------------------------"<<endl;
                    cout<<"    "<<now->origin;
                    cout<<" -> "<<now->destination<<endl;
                    cout<<"    "<<"Price:"<<now->money<<endl;
                    cout<<"    "<<"Date:"<<now->date<<endl;
                    i++;
                    now=now->next_travel;
                }
            }
        }
    }
}

void show_prompt(){//amirhossein
    cout << "Enter a command:" << endl;
    cout << " 1) add a user\n"
            " 2) add a travel\n"
            " 3) remove a user\n"
            " 4) show all users information\n"
            " 5) show travel info for a user\n"
            " 6) give discount to users with minimum travels\n"
            " 7) give discount to users signed in after a date\n"
            " 8) add money to a user\n"
            " 9) show everything!\n"
            "-1) end of the program\n";
}
void swap(int *xp, int *yp){//amirhossein
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n){//amirhossein
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void give_discount_by_travel_numbers(struct user* head , int n){
    int k;
    cout << "How many users are you\ngoing to give discount?"<<endl;
    cin >> k;
    int array[n];
    struct user* ptr = head -> next;
    int i = 0;
    while (ptr){
        array[i] = ptr ->number_of_travels;
        ptr = ptr->next;
        i++;
    }
    bubbleSort(array,n);
    ptr = head;
    cout << "how much?"<< endl;
    int x;
    cin >> x;
    bool flag;
    while (ptr){
        flag=false;
        for (int j = 0; j < k; ++j) {
            if( ptr -> number_of_travels == array[j]  ){
                ptr -> money += x;
                flag = true;
            }
        }
        if(flag){
            cout<<ptr->name<<"'s "<<"account: "<<ptr->money-x<<"$"<< " -> " << ptr->money <<"$"<<endl ;//amirhossein
            cout<<"----------------------------------\n";
        }
        ptr = ptr->next;
    }
    cout << "done" << endl;
}

void give_discount_by_date(struct user* head , int n){
    struct user* ptr = head -> next;
    bool done_or_not = false;
    int t;
    cout<<"from when?"<<endl;
    cin>>t;
    ptr = head->next ;
    cout << "how much?"<< endl;
    int x;
    cin >> x;
    bool flag;
    while (ptr){
        flag= false;
        if(ptr->sign_in_date > t){
            ptr -> money += x;
            done_or_not = true;
            flag = true;
        }
        if(flag){
            cout<<"User number"<<ptr->number<<endl;
            cout<<"user name:"<<ptr->name<<endl;
            cout<<"sign in date:"<<ptr->sign_in_date<<endl;
            cout<<"number of travels:"<<ptr->number_of_travels<<endl;
            cout<<"money:"<<ptr->money-x<<"$"<< " -> " << ptr->money <<"$"<<endl ;
            cout<<"----------------------------------\n";
        }
        ptr = ptr->next;
    }
    if( done_or_not)
        cout << "done:)" << endl;
    else
        cout<<"no user found to add discount"<<endl;
}

void show_everything(struct user *head){
    int num = 1;
    if (head == NULL){
        cout << "NO USER FOUND!" << endl;
        return;
    }
    struct user* pointer = head -> next;
    while (pointer != NULL){
        cout << num << ")---------------------------------" << endl;
        print_a_user_info(pointer);
        cout << "travels: " << endl;
        struct travel* ptr = pointer -> user_travels -> next_travel;
        if(ptr ==NULL){
            cout<<"|    "<<"No travel exists!\n";
        }else{
            int i = 1;
            while(ptr!=NULL){//amirhossein
                cout<<"|    "<<i<<") - - - - - - - - - - - - - -"<<endl;
                cout<<"|    "<<ptr->origin;
                cout<<" -> "<<ptr->destination<<endl;
                cout<<"|    "<<"Price:"<<ptr->money<<endl;
                cout<<"|    "<<"Date:"<<ptr->date<<endl;
                i++;
                ptr=ptr->next_travel;
            }
        }

        pointer = pointer-> next;
        num++;
    }
    puts("");
}
void delete_node(struct user *deleted,struct user *head){
    struct user *current=head;
    while(current->next!=deleted){
        current=current->next;
    }
    struct user * temp=deleted->next;
    free(deleted);
    current->next=temp;
}

void delete_user(struct user *head){
    int found=0;
    struct user *current=head;
    char name[50];
    cout<<"enter your name\n";
    cin>>name;
    while(current!=NULL){
        if(strcmp(current->name,name)==0) {
            found++;
            struct user *deleted=current;
            delete_node(deleted,head);
        }
        current=current->next;
    }if(found==0){
        cout<<"user not found\n";
    }
}
void add_money(struct user *head){
    int found=0;
    struct user *current=head;
    char name[50];
    cout<<"enter your name\n";
    cin>>name;
    while(current!=NULL){
        if(strcmp(current->name,name)==0) {
            found++;
            cout<<"User found\n";
            int extraMoney;
            cout<<"How much money do you want to add?\n";
            cin>>extraMoney;
            current->money += extraMoney;
        }
        current=current->next;
    }if(found==0){
        cout<<"user not found\n";
    }
}
void add_money_2(struct user *user,struct travel *travel){
    int money;
    cout<<"your current money is:"<<user->money<<" the travel's money is:"<<travel->money<<endl;
    cout<<"how much money do you want to add?\n";
    cin>>money;
    user->money = user->money +=money;
}