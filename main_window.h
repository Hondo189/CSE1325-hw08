#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "controller.h"
#include <gtkmm.h>

class Main_window : public Gtk::Window
{
    public:
        Main_window(Controller& controller);
        virtual ~Main_window();
    protected:
        void on_add_scoop_click();        //Add Scoop to inventory
        void on_add_container_click();    //Add container to inventory
		void on_add_topping_click();	  //Add topping to inventory
		void on_list_scoops_click();	  //List scoop inventory
		void on_list_containers_click();  //list container inventory
		void on_list_toppings_click();    //list topping inventory
		void on_help_click();			  //help dialog
		//void on_test_data_click();		  //populate test data
		void on_quit_click();			  //quit program
    private:
        Gtk::Label *msg;                  // Status message display
        Controller& _controller;          // The controller instance for MICE
};
#endif 

