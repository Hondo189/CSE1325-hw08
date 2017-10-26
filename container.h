#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <string>
using namespace std;

class Container {
	public:
		Container (string name_in, string info_in, double wholesale_in, double retail_in, int stock_in, int capacity_in);
		string c_name;
		string c_info;
		double c_wholesale_cost;
		double c_retail_cost;
		int c_stock;
		int c_capacity;
		
	private:
		string name;
		string info;
		double wholesale_cost;
		double retail_cost;
		int stock;
		int capacity;
};
#endif
