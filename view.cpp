#include "view.h"
#include "dialogs.h"
#include <iostream>
#include <string>
using namespace std;

int View::show_menu() {
  string menu = R"(
<span font='18' weight='bold'>                     CSE1325 
CSE1325 MICE Management System<sup><small>TM</small></sup></span>

<span weight='bold' underline='double'>Add Item</span>
(1) Add Ice Cream Scoop
(2) Add Ice Cream Container
(3) Add Ice Cream Topping

<span weight='bold' underline='double'>Check Inventory</span>
(4) List Ice Cream Scoops
(5) List Ice Cream Containers
(6) List Ice Cream Toppings

<span weight='bold' underline='double'>Utility</span>
<span color='#007f00'><b>(9) Help</b></span>
(9) Help
(99) Populate Test Data
(0) Exit

)";

  string result = Dialogs::input(menu, "Main Menu");
  try {
    return (result == "CANCEL") ? 0 : stoi(result);
  } catch (...) {
    return -1;
  }
}


void View::list_scoops() {
	string scoop_list = "";

	for (int i=0; i<items.number_of_scoops(); i++) {
		scoop_list += std::to_string(i+1) + ") " + items.scoop_to_string(i) + "\n";
	}
	Dialogs::message(scoop_list, "List of Flavors");
}

void View::list_containers() {
	string container_list = "";

	for (int i=0; i<items.number_of_containers(); i++) {
		container_list += std::to_string(i+1) + ") " + items.cont_to_string(i) + "\n";
	}
	Dialogs::message(container_list, "List of Containers");
}

void View::list_toppings() {
	string topping_list = "";

	for (int i=0; i<items.number_of_toppings(); i++) {
		topping_list += std::to_string(i+1) + ") " + items.top_to_string(i) + "\n";
	}
	Dialogs::message(topping_list, "List of Toppings");
}

void View::help() {
	string helptext = R"(
The LMS<sup>TM</sup> tracks publication assets for a library, including those who
check out and return those publications.

<b>Scoop</b> 
	<b>Add</b> - Add new scoop flavor to inventory.
	<b>List</b> - List all scoop flavors in inventory.
<b>Container</b> 
	<b>Add</b> - Add new ice cream container to inventory.
	<b>List</b> - List all ice cream containers in inventory.
<b>Topping</b> 
	<b>Add</b> - Add new ice cream topping to inventory.
	<b>List</b> - List all ice cream toppings in inventory. 
<b>File</b>
	<b>Help</b> - Print this text.
	<b>Test Data</b> - command to pre-populate test data.
	<b>Quit</b> - Quit the program. WARNING: The current version does NOT
    		save any entered data.
  )";
	Dialogs::message(helptext, "Help");
}
