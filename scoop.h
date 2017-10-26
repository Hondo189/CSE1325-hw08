#ifndef SCOOP_H
#define SCOOP_H
#include <iostream>
#include <string>
using namespace std;

class Scoop {
	public:
		Scoop (string name_in, string info_in, double wholesale_in, double retail_in, int stock_in);
		string s_name;
		string s_info;
		double s_wholesale_cost;
		double s_retail_cost;
		int s_stock;
		
	private:
		string name;
		string info;
		double wholesale_cost;
		double retail_cost;
		int stock;
};
#endif
