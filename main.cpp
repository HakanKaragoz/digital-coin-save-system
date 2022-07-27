#include <iostream>
using namespace std;
#include <fstream>				//file stream, for writing and reading
#include "project.cpp"


int main()
{
	gui gui;
	coin coin1;
	main_menu:

	gui.passage();
	cout << "Welcome, please select the action :"<<endl;
	gui.passage();
	cout << "\nAdd coin record			(1):"<<endl;
	cout << "Transaction history 		(2):"<<endl;
	cout << "Show assets			(3):"<<endl;
	cout << "Profit and loss calculator	(4):"<<endl;

	int menu;
	cin >>menu;

	if (menu==1)
	{
		coin1.last_line_number_calculator();
		add_coin_menu:	
		coin1.get_coin();
		confirmation:
			
		cout<<"Confirm   (Yes(1),No(2),Cancel(3))"<<endl;
		int input;
		cin>>input;
		if (input==1)
		{
			cout<<"Compleated..."<<endl<<endl;
		}

		else if (input==2)
		{
			gui.passage();
			cout<<"Enter updated informations"<<endl;
			goto add_coin_menu;
		}
		else if	(input==3)
		{
			goto main_menu;
		}
		else
		{
			goto confirmation;
		}

		coin1.get_date();
		coin1.print_coin();
		coin1.write_on_txt();
	}

	else if(menu==2)
	{
		coin1.read_on_txt();
	}
	
	else if(menu==3)
	{
		gui.passage();
		coin1.line_number_calculator();
		coin1.create_list_file();
		coin1.create_list();
		coin1.transform_string_to_integer();
		coin1.simplify_list_and_print();
	}

	else if(menu==4)
	{

		coin1.line_number_calculator();
		coin1.create_list_file();
		coin1.create_list();
		coin1.transform_string_to_integer();
		coin1.simplify_list();


		coin1.create_list_file_assets();
		coin1.create_asset_list();
		coin1.transform_string_to_integer_assets();
		coin1.get_updated_prices();

		gui.passage();
		coin1.update_prices();
	}

	gui.passage();
	cout<<"\nDo you want new action?	(Yes(1),No(2))"<<endl;
	gui.passage();

	cin>>menu;
	if (menu == 1)
	{
		goto main_menu;
	}
	else
	{
		return 0;
	}

}
