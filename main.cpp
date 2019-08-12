#include <iostream>
using namespace std;
struct user{
    string name;
    int sign_in_date;
    struct travel *user_travels;
    struct user* prev_user;
    struct user* next_user;
};

struct travel{
    string origin;
    string destination;
    int money;
    struct travel* prev_travel;
    struct travel* next_travel;
};

int main() {

    return 0;
}