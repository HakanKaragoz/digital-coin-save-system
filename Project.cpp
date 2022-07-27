#include <iostream>
using namespace std;
#include "project.h"
#include <sstream>
#include <ctime>		
#include <fstream>		
#include <string.h>
#include <string>

void coin::get_coin()	//gets coin informations
{

	cout<<"\n\nEnter the name of the coin		: "<<endl;
	cin >> name;
	cout<<"\nEnter trading status of "<<name<<" (buy/sell)	:"<<endl;
	cin	>> state;
	cout<<"\nEnter the unit price of coin		: "<<endl;
	cin >> buy_unit_price;
	cout<<"\nEnter the total price of coin		: "<<endl;
	cin >> buy_price;

	buy_amount=buy_price/buy_unit_price;
	cout<<"\nInformation of coin is below"<<endl;
	cout <<"State		: "<< state<<endl;
	cout <<"Coin name	: "<< name<<endl;
	cout <<"Coin price	: "<< buy_unit_price<<"$"<<endl;
	cout <<"Amount		: "<< buy_amount<<" "<<name<<endl;
	cout <<"Total price	: "<< buy_price<<"$"<<endl<<endl;
	
}

void coin::get_date()	//gets date of system
{
	time_t now = time(0);
	char* dt = ctime(&now);

    string line = dt;
    string arr[5];
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < 5){
        ssin >> arr[i];
        ++i;
    }

    month=arr[1];
    day =arr[2];
    year=arr[4];
    hour=arr[3];

}

void coin::print_coin()	//	prints coin informations
{
	cout << state <<"  "<< name  << "  " << buy_unit_price<<"$  "<<buy_price<<"$  "<<buy_amount<<" "<<name<<endl;
	cout << month <<" "<< day <<"	"<<year <<" "<< hour << endl;
}

void coin::write_on_txt()	// write on txt file new coin informations
{
	ofstream write;
	write.open("database.txt",ios::app);	// for program does not delete the txt file when I close
	write <<last_line_number<<"	"<<state<< "	"<<name<< "	" <<buy_unit_price<<"		  "<<
	buy_amount<<"	  "<<buy_price<<"		"<<day<< " " <<month<<" "<<year<<"  "<<hour<<endl;
	write.close();

}

void coin::read_on_txt()	//reads all coin data from txt file
{
	cout << "Transection history is below	:"<<endl<<endl;;
	cout << "no |	state | name |	unit price	| amount	| asset($) | date"<<endl;
	ifstream read;
	string line;
	read.open("database.txt");
	while (getline(read,line))		//reads line by line
	{
		cout << line <<endl;
	}
	cout<<endl;
	read.close();

}

void coin::last_line_number_calculator()	// calculates last line of txt
{
	last_line_number=1;
	ifstream file("database.txt");
	string line;
	while(getline(file,line))
	{
		last_line_number=last_line_number+1;
	}
	file.close();
}
void coin::line_number_calculator()	//	calculates total line number of txt
{
	line_number=0;
	ifstream file("database.txt");
	string line;
	while(getline(file,line))
	{
		line_number=line_number+1;
	}

	file.close();
}
void coin::create_list_file()	// creates a new txt file previous txt to create a list.
{
	int matrix[10][line_number];
	string element;
	ifstream read_file("database.txt");		//file read
	ofstream write_file	;					//file write
	write_file.open("list.txt");
	while(read_file>>element)
	{
		write_file<< element <<endl;
	}
	read_file.close();
	write_file.close();
}

void coin::create_list()		// creates a list of all data of coins
{

	ifstream file;
	string line;
	file.open("list.txt");
	matrix[10][line_number];

	for(int i=0; i<line_number; i++)
	{
		for(int j=0; j<10; j++)
		{
			getline(file,line);
			matrix[i][j] = line;
			//matrix[i][0]=coin row
			//matrix[i][1]=coin state
			//matrix[i][2]=coin name
			//matrix[i][3]=coin unit price
			//matrix[i][4]=coin quantity
			//matrix[i][5]=coin total price
			//matrix[i][6]=coin asset
			//matrix[i][7]=coin month
			//matrix[i][8]=coin year
			//matrix[i][9]=coin hour

		}

	}
	file.close();
}

void coin::transform_string_to_integer()	//transform float to string informations
{
	for(int i=0; i<line_number; i++)
	{
		for(int j=3; j<=5; j++)
		{
			matrix_f[i][j] = std::stof(matrix[i][j]);
		}
	}
}

void coin::simplify_list_and_print()		// decreases multiple inputs to only one input and print
{
	ofstream file;
	file.open("asset.txt");
	for(int i=0; i<line_number; i++)
	{
		string name=matrix[i][2];

		float amount=matrix_f[i][4];
		float total=matrix_f[i][5];
		
		float u_priceXamount=matrix_f[i][3]*matrix_f[i][4];
		float sum_total=u_priceXamount;
		
		for(int j=i+1; j<line_number; j++)
		{


			if (matrix[i][2]==matrix[j][2])					
			{
				if(matrix[j][1]=="buy")
				{
					amount=amount + matrix_f[j][4];
					u_priceXamount = matrix_f[j][3]*matrix_f[j][4];
					sum_total=sum_total+u_priceXamount;
					matrix[j][2]=" ";
				}


				else if(matrix[j][1]=="sell")
				{
					amount=amount - matrix_f[j][4];
					u_priceXamount = matrix_f[j][3]*matrix_f[j][4];
					sum_total=sum_total-u_priceXamount;
					matrix[j][2]=" ";

				}
			}
		}
		
		if(matrix[i][2]!=" ")
		{
			float avg_unit_price = sum_total/amount;
			total = avg_unit_price*amount;
			cout<<name<<"	"<<endl;
			cout<<"average unit price	:"<<avg_unit_price<<endl;
			cout<<"total amount 		:"<<amount<<endl;
			cout<<"total asset		:"<<total<<"$"<<endl<<endl;

			file<<name<<"	"<<avg_unit_price<<"	"<<amount<<"	"<<total<<"	"<<endl;
		}
	}
	file.close();
}
void coin::simplify_list()				//decreases multiple inputs to only one input without print
{
	ofstream file;
	file.open("asset.txt");
	for(int i=0; i<line_number; i++)
	{
		string name=matrix[i][2];

		float amount=matrix_f[i][4];
		float total=matrix_f[i][5];

		for(int j=i+1; j<line_number; j++)
		{


			if (matrix[i][2]==matrix[j][2])					//if 2 same coin name
			{
				if(matrix[j][1]=="buy")
				{
					total=total + matrix_f[j][5];
					amount=amount + matrix_f[j][4];
					matrix[j][2]=" ";
				}


				else if(matrix[j][1]=="sell")
				{
					total=total - matrix_f[j][5];
					amount=amount - matrix_f[j][4];
					matrix[j][2]=" ";

				}
			}
		}

		if(matrix[i][2]!=" ")
		{
			float unit_price=total/amount;
			file<<name<<"	"<<unit_price<<"	"<<amount<<"	"<<total<<"	"<<endl;
		}
	}
	file.close();
}
void coin::create_list_file_assets()	// creates a new txt file with assets
{
	int matrix[4][line_number];
	string element;
	ifstream read_file("asset.txt");		
	ofstream write_file	;					
	write_file.open("list.txt");
	while(read_file>>element)
	{
		write_file<< element <<endl;
	}
	read_file.close();
	write_file.close();
}

void coin::create_asset_list()		// creates a list with using txt file informations
{
	line_number=0;
	ifstream x("asset.txt");
	string l;
	while(getline(x,l))
	{
		line_number=line_number+1;
	}
	x.close();
	
	ifstream file;
	string line;
	file.open("list.txt");
	assets[line_number][4];
	cout<<"--------------------------------"<<endl;

	for(int i=0; i<line_number; i++)
	{
		for(int j=0; j<4; j++)
		{
			getline(file,line);
			assets[i][j] = line;
			//matrix[i][0]=coin name
			//matrix[i][1]=average buy price
			//matrix[i][2]=total asset
		}
	}
	file.close();
	
}

void coin::transform_string_to_integer_assets()	//transform strings informations to integer
{
	for(int i=0; i<line_number; i++)
		{
			for(int j=1; j<=3; j++)
			{
				assets_f[i][j] = std::stof(assets[i][j]);
			}
		}
}
void coin::get_updated_prices()		//gets updates prices from user
{
	cout<<"set updated prices :"<<endl;

	for(int i=0; i<line_number; i++)
	{
		cout<<"\ncoin adi : "<<assets[i][0]<<endl;
		cin>>assets_f[i][5];							//current rate
	}
}

void coin::update_prices()		//updates prices
{



	for(int i=0; i<line_number; i++)
	{
		assets_f[i][6]=assets_f[i][1]-assets_f[i][5];	
		float profit=(assets_f[i][2]*assets_f[i][5])-assets_f[i][3];
		float rate= 100*profit/assets_f[i][3];

		cout<<"\ncoin name : "<<assets[i][0]<<endl;
		cout<<"profit :"<<profit<<"$"<<"		"<<"profit/losss rate :"<<"% "<<rate<<endl;

	}

}

void gui::passage()
{
	cout<<("\n----------------------------------------------------")<<endl;
}
