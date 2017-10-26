#include "view.h"
#include <iostream>
#include <string>
using namespace std;

void View::show_menu() {
	string menu = R"(
==============================
CSE1325 MICE Management System
==============================

Add Item
-----
(1) Add Ice Cream Scoop
(2) Add Ice Cream Container
(3) Add Ice Cream Topping

Check Inventory
---------------
(4) List Ice Cream Scoops
(5) List Ice Cream Containers
(6) List Ice Cream Toppings

Utility
-------
(9) Help
(99) Populate Test Data
(0) Exit
)";

	cout << menu << endl;
}

void View::list_scoops() {
	string header = R"(
------------------------
List of Ice Cream Scoops
------------------------
)";
	cout << header;
	for (int i=0; i<items.number_of_scoops(); i++) {
		cout << i << ") " items.scoop_to_string(i) << endl;
	}
}

void View::list_containers() {
	string header = R"(
----------------------------
List of Ice Cream Containers
----------------------------
)";
	cout << header;
	for (int i=0; i<items.number_of_containers(); i++) {
		cout << i << ") " items.cont_to_string(i) << endl;
	}
}

void View::list_toppings() {
	string header = R"(
--------------------------
List of Ice Cream Toppings
--------------------------
)";
	cout << header;
	for (int i=0; i<items.number_of_toppings(); i++) {
		cout << i << ") " items.top_to_string(i) << endl;
	}
}
