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
		void add_scoop(Scoop scoop);
		void add_container(Container cont);
		void add_topping(Topping top);
		void test_data();
	private:
		vector<Scoop> scoops;
		vector<Container> containers;
		vector<Topping> toppings;
};
#endif
