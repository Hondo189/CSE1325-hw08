#include "topping.h"
#include <string>
#include <iostream>
using namespace std;

string Topping::to_string() {
	string top = "\nName: " +name+ " Wholesale Cost: " +std::to_string(wholesale_cost)+ 
		" Retail Price: " +std::to_string(retail_cost)+ " Stock Remaing: " +std::to_string(stock)+
		+"\nDescription: " +info;
	return top;
}

string Topping::get_name() {
	return name;
}
