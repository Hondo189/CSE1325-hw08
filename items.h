#ifndef ITEMS_H
#define ITEMS_H
#include "scoop.h"
#include "container.h"
#include "topping.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Items {
	public:
		void add_scoop(Scoop scp);
		void add_container(Container cont);
		void add_topping(Topping top);
		
		string scoop_to_string(int scoop_index);
		string cont_to_string(int cont_index);
		string top_to_string(int top_index);
		
		int number_of_scoops();
		int number_of_containers();
		int number_of_toppings();
		
		void test_data();
	private:
		vector<Scoop> scoops;
		vector<Container> containers;
		vector<Topping> toppings;
};
#endif
