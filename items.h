#ifndef ITEMS_H
#define ITEMS_H
#include "scoop.h"
#include "container.h"
#include "topping.h"
#include "serving.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Items {
	public:
		void add_scoop(Scoop scp);
		void add_container(Container cont);
		void add_topping(Topping top);
		void add_serving(Serving serv);
		
		string scoop_to_string(int scoop_index);
		string cont_to_string(int cont_index);
		string top_to_string(int top_index);
		string serv_to_string(int serv_index);		
		
		string scoop_name(int scoop_index);
		string cont_name(int cont_index);
		string top_name(int top_index);
		
		int number_of_scoops();
		int number_of_containers();
		int number_of_toppings();
		int number_of_servings();		
	private:
		vector<Scoop> scoops;
		vector<Container> containers;
		vector<Topping> toppings;
		vector<Serving> servings;
};
#endif
