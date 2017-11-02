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
		void help();
	private:
		Items& items;
};
#endif
