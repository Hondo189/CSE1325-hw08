#ifndef VIEW_H
#define VIEW_H
#include "items.h"

class View {
	public:
		View(Items& _items) : items(_items) { }
		int show_menu();
		void list_scoops();
		void list_containers();
		void list_toppings();
		void list_servings();
		int select_scoop();
		int select_container();
		int select_topping();
		void help();
	private:
		Items& items;
		string get_scoops();
		string get_containers();
		string get_toppings();
		string get_servings();		
};
#endif
