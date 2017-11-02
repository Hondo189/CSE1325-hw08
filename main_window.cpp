#include "main_window.h"

Main_window::Main_window(Controller& controller) : _controller{controller} {
	set_default_size(640, 480);
	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	add(*vbox);

	//Create menu bar
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

	//Create file menu
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);

		//Quit Program
		Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
		menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
		filemenu->append(*menuitem_quit);
	
	//Add Scoop Menu
	Gtk::MenuItem *menuitem_scoop = Gtk::manage(new Gtk::MenuItem("_Scoop", true));
	menubar->append(*menuitem_scoop);
	Gtk::Menu *scoopmenu = Gtk::manage(new Gtk::Menu());
	menuitem_scoop->set_submenu(*scoopmenu);
	
		//Append Add to Scoop Menu
		Gtk::MenuItem *menuitem_addscoop = Gtk::manage(new Gtk::MenuItem("_Add", true));
		menuitem_addscoop->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_scoop_click));
		scoopmenu->append(*menuitem_addscoop);

		//Append List to Scoop Menu
		Gtk::MenuItem *menuitem_listscoops = Gtk::manage(new Gtk::MenuItem("_List", true));
		menuitem_listscoops->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_list_scoops_click));
		scoopmenu->append(*menuitem_listscoops);
		
		vbox->show_all();	
}

Main_window::~Main_window() { } 

//callbacks
void Main_window::on_add_scoop_click() {_controller.execute_cmd(1);}
void Main_window::on_add_container_click() {_controller.execute_cmd(2);}
void Main_window::on_add_topping_click() {_controller.execute_cmd(3);}
void Main_window::on_list_scoops_click() {_controller.execute_cmd(4);}
void Main_window::on_list_containers_click() {_controller.execute_cmd(5);}
void Main_window::on_list_toppings_click() {_controller.execute_cmd(6);}
void Main_window::on_help_click() {_controller.execute_cmd(9);}
//void Main_window::on_test_data_click() {_controller.execute_cmd(99);}
void Main_window::on_quit_click() { hide(); }
