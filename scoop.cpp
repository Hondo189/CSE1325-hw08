#include "scoop.h"
#include <string>
#include <iostream>

using namespace std;

Scoop::Scoop(string name_in, string info_in, double wholesale_in, double retail_in, int stock_in) {
	p_name = name_in;
	p_info = info_in;
	p_wholesale_cost = wholesale_in;
	p_retail_cost = retail_in;
	p_stock = stock_in;
}
