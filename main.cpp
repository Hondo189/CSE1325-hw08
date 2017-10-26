#include "controller.h"
#include "items.h"

int main() {
	Items items;
	Controller controller(items);
	controller.cli();
}
