#ifndef TOPPING_H
#define TOPPING_H
#include <iostream>
#include <string>
using namespace std;

class Topping {
	public:
		Topping (string t_name,
				 string t_info,
				 double t_wholesale_cost,
				 double t_retail_cost,
				 int t_stock) :
				  
				 name(t_name),
				 info(t_info),
				 wholesale_cost(t_wholesale_cost),
				 retail_cost(t_retail_cost),
				 stock(t_stock) { }
		string to_string();
		
	private:
		string name;
		string info;
		double wholesale_cost;
		double retail_cost;
		int stock;
		int capacity;
};
#endif
