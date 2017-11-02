#include "controller.h"
#include "view.h"
#include "items.h"
#include "scoop.h"
#include "container.h"
#include "topping.h"
#include "top_request.h"
#include "dialogs.h"
#include <iostream>
#include <string>

using namespace std;

void Controller::cli() {
	int cmd = -1;
	while(cmd != 0) {
		view.show_menu();
		cout << "Command? ";
		cin >> cmd;
		cin.ignore(); //consume \n
		execute_cmd(cmd);
	}
}

void Controller::execute_cmd(int cmd) {
	if (cmd == 1) { //add scoop
	string name, info; 
	double wholesale, retail; 
	int remaining;
	bool cancel = false;

	Gtk::Dialog *dialog = new Gtk::Dialog();
	dialog->set_title("Create New Flavor");


	//Name of the Flavor
	Gtk::HBox b_name;
	
	Gtk::Label l_name{"Name of Flavor:"};
	l_name.set_width_chars(30);
	b_name.pack_start(l_name, Gtk::PACK_SHRINK);

	Gtk::Entry e_name;
	e_name.set_max_length(50);
	b_name.pack_start(e_name, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

	//Description of the Flavor
	Gtk::HBox b_info;
	
	Gtk::Label l_info{"Description:"};
	l_info.set_width_chars(30);
	b_info.pack_start(l_info, Gtk::PACK_SHRINK);

	Gtk::Entry e_info;
	e_info.set_max_length(50);
	b_info.pack_start(e_info, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_info, Gtk::PACK_SHRINK);

	//Whole sale price
	Gtk::HBox b_wholesale;
	
	Gtk::Label l_wholesale{"Whole sale price ($):"};
	l_wholesale.set_width_chars(30);
	b_wholesale.pack_start(l_wholesale, Gtk::PACK_SHRINK);

	Gtk::Entry e_wholesale;
	e_wholesale.set_max_length(50);
	b_wholesale.pack_start(e_wholesale, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_wholesale, Gtk::PACK_SHRINK);

	//Retail Price
	Gtk::HBox b_retail;
	
	Gtk::Label l_retail{"Retail price ($): "};
	l_retail.set_width_chars(30);
	b_retail.pack_start(l_retail, Gtk::PACK_SHRINK);
	
	Gtk::Entry e_retail;
	e_retail.set_max_length(50);
	b_retail.pack_start(e_retail, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_retail, Gtk::PACK_SHRINK);

	//Amount remaining
	Gtk::HBox b_remaining;
	
	Gtk::Label l_remaining{"Amount remaining in stock:"};
	l_remaining.set_width_chars(30);
	b_remaining.pack_start(l_remaining, Gtk::PACK_SHRINK);

	Gtk::Entry e_remaining;
	e_remaining.set_max_length(50);
	b_remaining.pack_start(e_remaining, Gtk::PACK_SHRINK);
	dialog->get_vbox()->pack_start(b_remaining, Gtk::PACK_SHRINK);

	dialog->add_button("Cancel", 0);
	dialog->add_button("OK", 1);
	dialog->show_all();
	int result = dialog->run();
	
	dialog->close();
	while (Gtk::Main::events_pending()) Gtk::Main::iteration();

	name = e_name.get_text();
	info = e_info.get_text();
	wholesale = std::stod(e_wholesale.get_text());
	retail = std::stod(e_retail.get_text());
	remaining = std::stoi(e_remaining.get_text());

	if (result = 1) {
				items.add_scoop(Scoop(name, info, wholesale, retail, remaining)); 
	}
	

	}
	else if (cmd == 2) { //add container
		string name, info;
		double wholesale, retail;
		int remaining, capacity;

		Gtk::Dialog *dialog = new Gtk::Dialog();
		dialog->set_title("Create Container");

		//Name
		Gtk::HBox b_name;
	
		Gtk::Label l_name{"Name of Container:"};
		l_name.set_width_chars(30);
		b_name.pack_start(l_name, Gtk::PACK_SHRINK);
	
		Gtk::Entry e_name;
		e_name.set_max_length(50);
		b_name.pack_start(e_name, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

		//Description
		Gtk::HBox b_info;
	
		Gtk::Label l_info{"Description:"};
		l_info.set_width_chars(30);
		b_info.pack_start(l_info, Gtk::PACK_SHRINK);

		Gtk::Entry e_info;
		e_info.set_max_length(50);
		b_info.pack_start(e_info, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(b_info, Gtk::PACK_SHRINK);

		//Whole sale price
		Gtk::HBox b_wholesale;
	
		Gtk::Label l_wholesale{"Wholesale price ($):"};
		l_wholesale.set_width_chars(30);
		b_wholesale.pack_start(l_wholesale, Gtk::PACK_SHRINK);

		Gtk::Entry e_wholesale;
		e_wholesale.set_max_length(50);
		b_wholesale.pack_start(e_wholesale, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(b_wholesale, Gtk::PACK_SHRINK);

		//Retail price
		Gtk::HBox b_retail;
	
		Gtk::Label l_retail{"Retail price ($):"};
		l_retail.set_width_chars(30);
		b_retail.pack_start(l_retail, Gtk::PACK_SHRINK);

		Gtk::Entry e_retail;
		e_retail.set_max_length(50);
		b_retail.pack_start(e_retail, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(b_retail, Gtk::PACK_SHRINK);

		//Remaining 
		Gtk::HBox b_remaining;

		Gtk::Label l_remaining{"Amount in stock:"};
		l_remaining.set_width_chars(30);
		b_remaining.pack_start(l_remaining, Gtk::PACK_SHRINK);

		Gtk::Entry e_remaining;
		e_remaining.set_max_length(50);
		b_remaining.pack_start(e_remaining, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(b_remaining, Gtk::PACK_SHRINK);
		
		//Scoop Capacity
		Gtk::HBox b_capacity;

		Gtk::Label l_capacity{"Scoop Capcity:"};
		l_capacity.set_width_chars(30);
		b_capacity.pack_start(l_capacity, Gtk::PACK_SHRINK);

		Gtk::Entry e_capacity;
		e_capacity.set_max_length(50);
		b_capacity.pack_start(e_capacity, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(b_capacity, Gtk::PACK_SHRINK);

		dialog->add_button("Cancel", 0);
		dialog->add_button("OK", 1);
		dialog->show_all();
		int result = dialog->run();

		dialog->close();
		while(Gtk::Main::events_pending()) Gtk::Main::iteration();

		name = e_name.get_text();
		info = e_info.get_text();
		wholesale = std::stod(e_wholesale.get_text());
		retail = std::stod(e_retail.get_text());
		remaining = std::stoi(e_remaining.get_text());
		capacity = std::stoi(e_capacity.get_text());

		if (result == 1) {
			items.add_container(Container(name, info, wholesale, retail, remaining, capacity)); 
		}
		
	}
	else if (cmd == 3) { //add topping
		string name, info;
		double wholesale, retail;
		int remaining;

	
		Gtk::Dialog *dialog = new Gtk::Dialog();
		dialog->set_title("Create a new Topping");

		//Name
		Gtk::HBox b_name;

		Gtk::Label l_name{"Name of Topping:"};
		l_name.set_width_chars(30);
		b_name.pack_start(l_name, Gtk::PACK_SHRINK);

		Gtk::Entry e_name;
		e_name.set_max_length(50);
		b_name.pack_start(e_name, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

		//Description
		Gtk::HBox b_info;
	
		Gtk::Label l_info{"Description:"};
		l_info.set_width_chars(30);
		b_info.pack_start(l_info, Gtk::PACK_SHRINK);
	
		Gtk::Entry e_info;
		e_info.set_max_length(50);
		b_info.pack_start(e_info, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(b_info, Gtk::PACK_SHRINK);

		//Wholesale price
		Gtk::HBox b_wholesale;
	
		Gtk::Label l_wholesale{"Wholesale price ($):"};
		l_wholesale.set_width_chars(30);
		b_wholesale.pack_start(l_wholesale, Gtk::PACK_SHRINK);
	
		Gtk::Entry e_wholesale;
		e_wholesale.set_max_length(50);
		b_wholesale.pack_start(e_wholesale, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(b_wholesale, Gtk::PACK_SHRINK);

		//Retail price
		Gtk::HBox b_retail;
	
		Gtk::Label l_retail{"Retail price ($):"};
		l_retail.set_width_chars(30);
		b_retail.pack_start(l_retail, Gtk::PACK_SHRINK);
	
		Gtk::Entry e_retail;
		e_retail.set_max_length(50);
		b_retail.pack_start(e_retail, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(b_retail, Gtk::PACK_SHRINK);
	
		//Remaining in stock
		Gtk::HBox b_remaining;
	
		Gtk::Label l_remaining{"Amount in stock:"};
		l_remaining.set_width_chars(30);
		b_remaining.pack_start(l_remaining, Gtk::PACK_SHRINK);
	
		Gtk::Entry e_remaining;
		e_remaining.set_max_length(50);
		b_remaining.pack_start(e_remaining, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(b_remaining, Gtk::PACK_SHRINK);

		dialog->add_button("Cancel", 0);
		dialog->add_button("OK", 1);
		dialog->show_all();
		int result = dialog->run();

		dialog->close();
		while(Gtk::Main::events_pending()) Gtk::Main::iteration();

		name = e_name.get_text();
		info = e_info.get_text();
		wholesale = std::stod(e_wholesale.get_text());
		retail = std::stod(e_retail.get_text());
		remaining = std::stoi(e_remaining.get_text());

		if (result == 1) {
			items.add_topping(Topping(name, info, wholesale, retail, remaining)); }

	}
	else if (cmd == 4) {//list scoops
		view.list_scoops();
	}
	else if (cmd == 5) {//list containers
		view.list_containers();
	}
	else if (cmd == 6) {//list toppings
		view.list_toppings();
	}
	else if (cmd == 7) {//add serving
		
	}
	else if (cmd == 9) {//help
		view.help();	
	}
	else if (cmd == 99) {//populate test data
		items.add_scoop(Scoop("Vanilla", "Classic Vanilla Flavor", .5, 2, 500));
		items.add_scoop(Scoop("Chocolate", "Classic Chocolate Flavor", .6, 2, 500));
		items.add_scoop(Scoop("Strawberry", "Fresh Strawberry Flavor", .7, 2.25, 300));
		items.add_container(Container("Sugar Cone", "Classic Cripsy Cone", .25, 1, 200, 2));
		items.add_container(Container("Waffle Cone", "Freshly Made Waffle Cone", .4, 1.5, 150, 3));
		items.add_container(Container("Paper Bowl", "Disposable Paper Bowl", .05, .1, 500, 4));		
		items.add_topping(Topping("Chocolate Sprinkles", "Chocolate Flavored Sprinkles", .01, .25, 1000));
		items.add_topping(Topping("Rainbow Sprinkles", "Multi-Colored Sprinkles", .01, .25, 2000));
		items.add_topping(Topping("Roasted Peanuts", "Crushed Roasted Peanuts", .1, .5, 800));
	}
}		
