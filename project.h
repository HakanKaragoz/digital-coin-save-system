#ifndef PROJECT_H_
#define PROJECT_H_
#include <iostream>
using namespace std;

class coin
{
	private:
		string name,state;
		float buy_unit_price, buy_amount, buy_price;
		string month, day, year, hour;
		int last_line_number;

		
	public:
		int line_number;
		string matrix[9][100];
		float matrix_f[9][100];
		string assets[100][4];
		float assets_f[6][100];
		void get_coin();
		void print_coin();
		void edit_coin();
		void get_date();
		void destroy_coin();
		void write_on_txt();
		void read_on_txt();
		void last_line_number_calculator();
		void line_number_calculator();
		void find_coin_names();
		void create_list_file();
		void create_list();
		void transform_string_to_integer();
		void transform_string_to_integer_assets();
		void simplify_list_and_print();
		void simplify_list();
		void update_prices();
		void create_asset_list();
		void create_list_file_assets();
		void get_updated_prices();
		
};

class gui
{
	public:
		void passage();
};


#endif
