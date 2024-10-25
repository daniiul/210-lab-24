// COMSC-210 | 210-lab-24 | Daniil Malakhov
// IDE used: Codeblocks
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    set<Goat> trip;

    int op = main_menu();
    while(op != 4)
    {
       if (op == 1)
       {
           add_goat(trip, names, colors);
       }
       else if (op == 2)
       {
            delete_goat(trip);
       }
       else if (op == 3)
       {
            cout << "Current  list: " << endl;
            display_trip(trip);
       }
       op = main_menu();
    }

    return 0;
}

// displays the menu
// arguments: none
// returns: an int representing choice made by user
int main_menu()
{
    int entry;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List Goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice --> ";
    cin >> entry;
    while(entry < 1 || entry > 4)
    {
        cout << "Please enter a valid entry";
        cin >> entry;
        cout << endl;
    }

    cout << endl;

    return entry;
}

// adds a new goat to the set with a random name age and color
// arguments: address to list of current trip, array of names, array of colors
// returns: none
void add_goat(set<Goat> &trip, string names[], string colors[])
{
    string n = names[rand() % SZ_NAMES];
    string c = colors[rand() % SZ_COLORS];
    int a = rand() % MAX_AGE;
    Goat temp(n, a, c);
    trip.insert(temp);
    return;
}

// deletes specified goat from list
// arguments: address to list of current trip
// returns: none
void delete_goat(set<Goat> &trip)
{
    int entry;

    display_trip(trip);

    cout << "Select which goat to delete: ";
    cin >> entry;

    auto itd = trip.begin();
    advance(itd, entry - 1);
    trip.erase(itd);

    cout << "New List: " << endl;
    display_trip(trip);
}

// displays current trip
// arguments: address to trip list
// returns: none
void display_trip(set<Goat> trip)
{
   int i = 1;
   for(auto it = trip.begin(); it != trip.end(); it++)
   {
        Goat temp = *it;
        cout << "[" << i++ << "] " << temp.get_name() << "( " << temp.get_age() << ", " << temp.get_color() << ")" << endl;
   }
   cout << endl;
}
