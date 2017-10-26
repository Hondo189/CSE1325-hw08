#include "scoop.h"
#include <string>
#include <iostream>
using namespace std;

Scoop::Scoop(string name_in, string info_in, double wholesale_in, double retail_in, int stock_in) {
	s_name = name_in;
	s_info = info_in;
	s_wholesale_cost = wholesale_in;
	s_retail_cost = retail_in;
	s_stock = stock_in;
}
