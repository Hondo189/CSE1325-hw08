#include "container.h"
#include <string>
#include <iostream>
using namespace std;

string Container::to_string() {
	string cont = "\nName: " +name+ " Wholesale Cost: " +std::to_string(wholesale_cost)+ 
		" Retail Price: " +std::to_string(retail_cost)+ " Stock Remaing: " +std::to_string(stock)+
		" Scoop Capacity: " +std::to_string(capacity)+
		"\nDescription: " +info;
	return cont;
}

string Container::get_name() {
	return name;
}
