#include <iostream>
#include <string>
using namespace std;

#define MAX_USERS    50
#define MAX_TRAINS   5
#define MAX_TICKETS  200

struct User {
    string username;
    string password;
    string fullName;
    string role;
};

struct Train {
    string id;
    string name;
    string from;
    string to;
    string time;
    string days;
    int    totalSeats;
    int    bookedSeats;
    int    fare;
};

struct Ticket {
    string ticketId;
    string username;
    string trainId;
    string trainName;
    string from;
    string to;
    string date;
    string seat;
    int    fare;
    string status;
};

User   users[MAX_USERS];
Train  trains[MAX_TRAINS];
Ticket tickets[MAX_TICKETS];

int userCount        = 0;
int trainCount       = 0;
int ticketCount      = 0;
int currentUserIndex = -1;


void printLine() {
    cout << "  ======================================\n";
}

void printHeader(string title) {
    cout << "\n";
    printLine();
    cout << "    " << title << "\n";
    printLine();
    cout << "\n";
}

string makeTicketId() {
    int num = ticketCount + 1;
    string id = "TKT-";
    id += (char)('0' + num / 100 % 10);
    id += (char)('0' + num / 10  % 10);
    id += (char)('0' + num       % 10);
    return id;
}


string makeSeatNumber(int n) {
    string rows[] = {"A","B","C","D","E"};
    int row = (n - 1) / 8;
    int col = (n - 1) % 8 + 1;
    string seat = rows[row] + "-";
    if (col < 10) seat += "0";
    seat += (char)('0' + col);
    return seat;
}


void initData() {
    users[0].username = "admin"; users[0].password = "admin123";
    users[0].fullName = "Administrator"; users[0].role = "admin";

    users[1].username = "shah";   users[1].password = "shah123";
    users[1].fullName = "Shah";    users[1].role = "user";

    userCount = 2;

    trains[0].id="T01"; trains[0].name="Khyber Mail";
    trains[0].from="Karachi"; trains[0].to="Peshawar";
    trains[0].time="08:00"; trains[0].days="Mon/Wed/Fri";
    trains[0].totalSeats=40; trains[0].bookedSeats=0; trains[0].fare=800;

    trains[1].id="T02"; trains[1].name="Awam Express";
    trains[1].from="Karachi"; trains[1].to="Lahore";
    trains[1].time="14:00"; trains[1].days="Daily";
    trains[1].totalSeats=40; trains[1].bookedSeats=0; trains[1].fare=600;

    trains[2].id="T03"; trains[2].name="Tezgam";
    trains[2].from="Karachi"; trains[2].to="Lahore";
    trains[2].time="21:00"; trains[2].days="Daily";
    trains[2].totalSeats=40; trains[2].bookedSeats=0; trains[2].fare=750;

    trains[3].id="T04"; trains[3].name="Green Line";
    trains[3].from="Karachi"; trains[3].to="Islamabad";
    trains[3].time="16:00"; trains[3].days="Daily";
    trains[3].totalSeats=40; trains[3].bookedSeats=0; trains[3].fare=1000;

    trains[4].id="T05"; trains[4].name="Islamabad Express";
    trains[4].from="Lahore"; trains[4].to="Islamabad";
    trains[4].time="07:00"; trains[4].days="Daily";
    trains[4].totalSeats=40; trains[4].bookedSeats=0; trains[4].fare=350;

    trainCount = 5;
}


bool doLogin() {
    printHeader("LOGIN");
    string uname, pass;
    cout << "  Username : "; cin >> uname;
    cout << "  Password : "; cin >> pass;

    for (int i = 0; i < userCount; i++) {
        if (users[i].username == uname && users[i].password == pass) {
            currentUserIndex = i;
            cout << "\n  Welcome, " << users[i].fullName << "!\n";
            return true;
        }
    }
    cout << "\n  Invalid username or password!\n";
    return false;
}

void doRegister() {
    printHeader("REGISTER");
    if (userCount >= MAX_USERS) { cout << "  User limit reached!\n"; return; }

    User u;
    cout << "  Full Name : "; cin >> u.fullName;
    cout << "  Username  : "; cin >> u.username;

    for (int i = 0; i < userCount; i++) {
        if (users[i].username == u.username) {
            cout << "\n  Username already taken!\n";
            return;
        }
    }

    cout << "  Password  : "; cin >> u.password;
    u.role = "user";
    users[userCount++] = u;
    cout << "\n  Account created! Please login.\n";
}


void showSchedule() {
    printHeader("TRAIN SCHEDULE");
    cout << "  ID   Name               From        To          Time    Fare\n";
    cout << "  ---  -----------------  ----------  ----------  ------  ----\n";
    for (int i = 0; i < trainCount; i++) {
        Train& t = trains[i];
        int avail = t.totalSeats - t.bookedSeats;
        cout << "  " << t.id << "  ";
        cout.width(17); cout << left << t.name << "  ";
        cout.width(10); cout << left << t.from << "  ";
        cout.width(10); cout << left << t.to   << "  ";
        cout << t.time << "  Rs." << t.fare;
        if (avail <= 5) cout << "  [Only " << avail << " left!]";
        cout << "\n";
    }
    cout << "\n";
}



void bookTicket() {
    printHeader("BOOK TICKET");
    showSchedule();

    string tid;
    cout << "  Enter Train ID (T01-T05): "; cin >> tid;

    int tIndex = -1;
    for (int i = 0; i < trainCount; i++) {
        if (trains[i].id == tid) { tIndex = i; break; }
    }

    if (tIndex == -1) { cout << "\n  Train not found!\n"; return; }

    Train& t = trains[tIndex];
    if (t.bookedSeats >= t.totalSeats) {
        cout << "\n  Sorry! Train is fully booked.\n";
        return;
    }

    string date;
    cout << "  Travel Date (DD-MM-YYYY): "; cin >> date;

    string seat = makeSeatNumber(t.bookedSeats + 1);
    string tid2 = makeTicketId();

    cout << "\n  ---- Booking Summary ----\n";
    cout << "  Ticket ID : " << tid2   << "\n";
    cout << "  Train     : " << t.name << "\n";
    cout << "  Route     : " << t.from << " --> " << t.to << "\n";
    cout << "  Date      : " << date   << "\n";
    cout << "  Seat      : " << seat   << "\n";
    cout << "  Fare      : Rs. " << t.fare << "\n";
    cout << "  -------------------------\n";

    char confirm;
    cout << "\n  Confirm? (Y/N): "; cin >> confirm;
    if (confirm != 'Y' && confirm != 'y') {
        cout << "  Booking cancelled.\n";
        return;
    }

    Ticket tk;
    tk.ticketId  = tid2;
    tk.username  = users[currentUserIndex].username;
    tk.trainId   = t.id;
    tk.trainName = t.name;
    tk.from      = t.from;
    tk.to        = t.to;
    tk.date      = date;
    tk.seat      = seat;
    tk.fare      = t.fare;
    tk.status    = "Confirmed";

    tickets[ticketCount++] = tk;
    t.bookedSeats++;

    cout << "\n  Ticket Booked! ID: " << tk.ticketId << "\n";
    cout << "  Save this ID for cancellation.\n";
}


void viewTickets() {
    printHeader("MY TICKETS");
    bool found = false;

    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].username == users[currentUserIndex].username) {
            found = true;
            Ticket& tk = tickets[i];
            cout << "  -------------------------\n";
            cout << "  Ticket ID : " << tk.ticketId  << "\n";
            cout << "  Train     : " << tk.trainName << "\n";
            cout << "  Route     : " << tk.from << " --> " << tk.to << "\n";
            cout << "  Date      : " << tk.date       << "\n";
            cout << "  Seat      : " << tk.seat       << "\n";
            cout << "  Fare      : Rs. " << tk.fare   << "\n";
            cout << "  Status    : " << tk.status     << "\n";
        }
    }

    if (!found) cout << "  No tickets found.\n";
    cout << "\n";
}


void cancelTicket() {
    printHeader("CANCEL TICKET");

    
    bool found = false;
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].username == users[currentUserIndex].username &&
            tickets[i].status   == "Confirmed") {
            found = true;
            cout << "  Ticket ID: " << tickets[i].ticketId
                 << " | " << tickets[i].trainName
                 << " | " << tickets[i].date
                 << " | Seat: " << tickets[i].seat << "\n";
        }
    }

    if (!found) {
        cout << "  No confirmed tickets to cancel.\n";
        return;
    }

    string tid;
    cout << "\n  Enter Ticket ID to cancel: "; cin >> tid;

    for (int i = 0; i < ticketCount; i++) {
        Ticket& tk = tickets[i];
        if (tk.ticketId == tid &&
            tk.username == users[currentUserIndex].username) {

            if (tk.status == "Cancelled") {
                cout << "\n  Ticket already cancelled!\n";
                return;
            }

            tk.status = "Cancelled";
            int refund = tk.fare * 85 / 100;

            for (int j = 0; j < trainCount; j++) {
                if (trains[j].id == tk.trainId) {
                    trains[j].bookedSeats--;
                    break;
                }
            }

            cout << "\n  Ticket " << tid << " cancelled.\n";
            cout << "  Refund : Rs. " << refund << " (85%)\n";
            cout << "  Will be processed in 3-5 days.\n";
            return;
        }
    }
    cout << "\n  Ticket not found!\n";
}


void adminPanel() {
    if (users[currentUserIndex].role != "admin") {
        cout << "\n  Access Denied! Admins only.\n";
        return;
    }

    int choice;
    do {
        printHeader("ADMIN PANEL");

        int confirmed = 0, cancelled = 0, revenue = 0;
        for (int i = 0; i < ticketCount; i++) {
            if (tickets[i].status == "Confirmed") { confirmed++; revenue += tickets[i].fare; }
            else cancelled++;
        }

        cout << "  Total Bookings : " << ticketCount  << "\n";
        cout << "  Confirmed      : " << confirmed    << "\n";
        cout << "  Cancelled      : " << cancelled    << "\n";
        cout << "  Total Revenue  : Rs. " << revenue  << "\n";
        cout << "  Total Users    : " << userCount    << "\n\n";

        cout << "  1. View All Tickets\n";
        cout << "  2. View All Users\n";
        cout << "  0. Back\n";
        cout << "\n  Choice: "; cin >> choice;

        if (choice == 1) {
            printHeader("ALL TICKETS");
            if (ticketCount == 0) { cout << "  No tickets yet.\n"; }
            for (int i = 0; i < ticketCount; i++) {
                Ticket& tk = tickets[i];
                cout << "  " << tk.ticketId
                     << " | " << tk.username
                     << " | " << tk.from << "->" << tk.to
                     << " | " << tk.date
                     << " | Rs." << tk.fare
                     << " | " << tk.status << "\n";
            }
            cout << "\n";
        }
        else if (choice == 2) {
            printHeader("ALL USERS");
            for (int i = 0; i < userCount; i++) {
                cout << "  " << users[i].username
                     << " | " << users[i].fullName
                     << " | " << users[i].role << "\n";
            }
            cout << "\n";
        }

    } while (choice != 0);
}



void mainMenu() {
    int choice;
    do {
        printHeader("MAIN MENU");
        cout << "  Hello, " << users[currentUserIndex].fullName << "!\n\n";
        cout << "  1. Book Ticket\n";
        cout << "  2. My Tickets\n";
        cout << "  3. Cancel Ticket\n";
        cout << "  4. Train Schedule\n";
        if (users[currentUserIndex].role == "admin")
        cout << "  5. Admin Panel\n";
        cout << "  0. Logout\n";
        cout << "\n  Choice: "; cin >> choice;

        if      (choice == 1) bookTicket();
        else if (choice == 2) viewTickets();
        else if (choice == 3) cancelTicket();
        else if (choice == 4) showSchedule();
        else if (choice == 5) adminPanel();

        if (choice != 0) {
            cout << "\n  Press Enter to continue...";
            cin.ignore(); cin.get();
        }

    } while (choice != 0);

    currentUserIndex = -1;
    cout << "\n  Logged out!\n\n";
}


int main() {
    initData();

    int choice;
    do {
        printHeader("PAKRAIL TICKET SYSTEM");
        cout << "  Demo: admin/admin123  |  shah/shah123\n\n";
        cout << "  1. Login\n";
        cout << "  2. Register\n";
        cout << "  0. Exit\n";
        cout << "\n  Choice: "; cin >> choice;

        if      (choice == 1) { if (doLogin()) mainMenu(); }
        else if (choice == 2) doRegister();

    } while (choice != 0);

    cout << "\n  Thank you! Goodbye.\n\n";
    return 0;
}
