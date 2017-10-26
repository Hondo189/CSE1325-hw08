#include "controller.h"
#include "view.h"
#include "items.h"
#include "scoop.h"
#include "container.h"
#include "topping.h"
#include "top_request.h"
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
		string flavor, info;
		double wholesale_cost, retail_cost;
		int stock;
	
		cout << "Ice Cream Scoop Flavor?";
		getline(cin, flavor);
	
		cout << "wholesale Cost?";
		cin >> wholesale_cost;
		cin.ignore();
	
		cout << "Retail price?";
		cin >> retail_cost;
		cin.ignore();
	
		cout << "Stock Remaining?";
		cin >> stock;
		cin.ignore();
	
		cout << "Flavor Description?";
		getline(cin, info);
	
		items.add_scoop(Scoop(flavor, info, wholesale_cost, retail_cost, stock));
	}
	else if (cmd == 2) { //add container
		string name, info;
		double wholesale_cost, retail_cost;
		int stock, capacity;
	
		cout << "Container Name?";
		getline(cin, name);
	
		cout << "wholesale Cost?";
		cin >> wholesale_cost;
		cin.ignore();
	
		cout << "Retail price?";
		cin >> retail_cost;
		cin.ignore();
	
		cout << "Stock Remaining?";
		cin >> stock;
		cin.ignore();
	
		cout << "Scoop Capacity?";
		cin >> capacity;
		cin.ignore();
	
		cout << "Container Description?";
		getline(cin, info);
	
		items.add_container(Container(name, info, wholesale_cost, retail_cost, stock, capacity));
	}
	else if (cmd == 3) { //add topping
		string name, info;
		double wholesale_cost, retail_cost;
		int stock;
	
		cout << "Ice Cream Topping Name?";
		getline(cin, name);
	
		cout << "wholesale Cost?";
		cin >> wholesale_cost;
		cin.ignore();
	
		cout << "Retail price?";
		cin >> retail_cost;
		cin.ignore();
	
		cout << "Stock Remaining?";
		cin >> stock;
		cin.ignore();
	
		cout << "Topping Description?";
		getline(cin, info);
	
		items.add_topping(Topping(name, info, wholesale_cost, retail_cost, stock));
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
	else if (cmd == 9) {//help
		view.help();	
	}
}		
