#include "container.h"
#include <string>
#include <iostream>
using namespace std;

Container::Container(string name_in, string info_in, double wholesale_in, double retail_in, int stock_in, int capacity_in) {
	c_name = name_in;
	c_info = info_in;
	c_wholesale_cost = wholesale_in;
	c_retail_cost = retail_in;
	c_stock = stock_in;
	c_capacity = capacity_in;
}
