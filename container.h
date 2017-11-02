#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <string>
using namespace std;

class Container {
	public:
		Container(string c_name,
				  string c_info,
				  double c_wholesale_cost,
				  double c_retail_cost,
				  int c_stock,
				  int c_capacity) :
				  
				  name(c_name),
				  info(c_info),
				  wholesale_cost(c_wholesale_cost),
				  retail_cost(c_retail_cost),
				  stock(c_stock),
				  capacity(c_capacity) { }
		string to_string();
		string get_name();
		
	private:
		string name;
		string info;
		double wholesale_cost;
		double retail_cost;
		int stock;
		int capacity;
};
#endif
