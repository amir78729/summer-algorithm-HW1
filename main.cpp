#include <iostream>
using namespace std;
struct user{
    string name;
    int sign_in_date;
    int number_of_travels;
    struct travel *user_travels;
    struct user* prev_user;
    struct user* next_user;
}user;

struct travel{
    string origin;
    string destination;
    int money;
    struct travel* prev_travel;
    struct travel* next_travel;
}travel;

//function proto-types:
void add_user();
void add_travel();
void remove_user();

int main() {

    return 0;
}