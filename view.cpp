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

string View::get_scoops() {
	string scoop_list = "";
	for (int i=0; i<items.number_of_scoops(); i++) {
		scoop_list += std::to_string(i) + ") " + items.scoop_to_string(i) + "\n";
	}
	return scoop_list;
}

void View::list_scoops() {
	Dialogs::message(get_scoops(), "List of Flavors");
}

int View::select_scoop() {
	string result = Dialogs::input(get_scoops(), "Select A Scoop");
	
	try {
		return (result == "CANCEL") ? -1 : stoi(result);
	} catch (...) {
		Dialogs::message("Invalid entry - please type an integer");
	}
}

string View::get_containers() {
	string container_list = "";
	for (int i=0; i<items.number_of_containers(); i++) {
		container_list += std::to_string(i) + ") " + items.cont_to_string(i) + "\n";
	}
	return container_list;
}

void View::list_containers() {
	Dialogs::message(get_containers(), "List of Containers");
}

int View::select_container() {
	string result = Dialogs::input(get_containers(), "Select A Container");
	
	try {
		return (result == "CANCEL") ? -1 : stoi(result);
	} catch (...) {
		Dialogs::message("Invalid entry - please type an integer");
	}
}

string View::get_toppings() {
	string topping_list = "";
	for (int i=0; i<items.number_of_toppings(); i++) {
		topping_list += std::to_string(i) + ") " + items.top_to_string(i) + "\n";
	}
	return topping_list;
}

void View::list_toppings() {
	Dialogs::message(get_toppings(), "List of Toppings");
}

int View::select_topping() {
	string result = Dialogs::input(get_toppings(), "Select A Topping");
	
	try {
		return (result == "CANCEL") ? -1 : stoi(result);
	} catch (...) {
		Dialogs::message("Invalid entry - please type an integer");
	}
}

string View::get_servings() {
	string serving_list = "";
	for (int i=0; i<items.number_of_servings(); i++) {
		serving_list += std::to_string(i) + ") " + items.serv_to_string(i) + "\n";
	}
	return serving_list;
}

void View::list_servings() {
	Dialogs::message(get_servings(), "List of Servings");
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
