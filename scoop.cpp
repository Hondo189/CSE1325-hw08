#include "scoop.h"
#include <string>
#include <iostream>
using namespace std;

string Scoop::to_string() {
	string scp = "\nFlavor: " +name+ " Wholesale Cost: " +std::to_string(wholesale_cost)+ 
		" Retail Price: " +std::to_string(retail_cost)+ " Stock Remaing: " +std::to_string(stock)+
		"\nDescription: " +info;
	return scp;
}
