#ifndef SCOOP_H
#define SCOOP_H
#include <iostream>
#include <string>
using namespace std;

class Scoop {
	public:
		Scoop(string s_name,
			  string s_info,
			  double s_wholesale_cost,
			  double s_retail_cost,
			  int s_stock) :
			  
			  name(s_name),
			  info(s_info),
			  wholesale_cost(s_wholesale_cost),
			  retail_cost(s_retail_cost),
			  stock(s_stock) { }
		string to_string();
		string get_name();
		
	private:
		string name;
		string info;
		double wholesale_cost;
		double retail_cost;
		int stock;
};
#endif
