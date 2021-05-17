#include "storage.h"

int storage::count = 0;

storage::storage(const char* name, const char* uadres, int type, double saldo, double price, int quant, int num, int number, int month, int year)
	:base(name,uadres,type,saldo),date(number,month,year),num(num),price(price),quant(quant)
{
	count++;
}

storage::storage(std::ifstream& is):
base(is),date(is)
{
	is >> quant >> num >> price;
}

storage::~storage()
{
	count--;
}

void storage::save(std::ofstream& os)const
{
	base.save(os);
	date.save(os);
	os <<' '<< quant << ' ' << num << ' ' << price<<std::endl;
}

int storage::cmp_name(const storage& right) const
{
	return base.cmp_name(right.base);
}

int storage::cmp_name(const char* right) const
{
	return base.cmp_name(right);
}

storage& storage::operator=(const storage& in)
{
	base = in.base;
	quant = in.quant;
	date = in.date;
	num = in.num;
	price = in.price;
	return *this;
}

void storage::print_hedder()
{
	std::cout << std::setw(lenght_name) << "name" << std::setw(lenght_uadres) << "uadres" << std::setw(lenght_type) << "type" <<
		std::setw(lenght_saldo) << "saldo" << std::setw(lenght_num) << "num" << std::setw(lenght_quant) << "quant"
		<< std::setw(lenght_price) << "price" << std::setw(lenght_month + lenght_number + lenght_year) << "date" << std::endl;
}

void storage::print() const
{
	std::cout << std::setw(lenght_name) << base.get_name() << std::setw(lenght_uadres) << base.get_uadres() << std::setw(lenght_type) << base.get_type_str() <<
		std::setw(lenght_saldo) << base.get_saldo()
		<< std::setw(lenght_num) << num 
		<< std::setw(lenght_quant) << quant
		<< std::setw(lenght_price) << price << std::setw(lenght_number)<<date.get_number()
		<< std::setw(lenght_month) << date.get_str_month() << std::setw(lenght_year) << date.get_year()<< std::endl;
}

void storage::input()
{
	std::cout << "input num: " << std::endl;
	std::cin >> num;
	
	std::cout << "input price: " << std::endl;
	std::cin >> price;
	std::cout << "input quant: " << std::endl;
	std::cin >> quant;
	std::cin>>base;
	std::cout << "input date " << std::endl;
	date.input_date();
}

const char* storage::get_name()const
{
	return base.get_name();
}

int storage::get_num() const
{
	return num;
}

double storage::get_saldo() const
{
	return base.get_saldo();
}

double storage::get_price()const
{
	return price;
}

int storage::get_quant()const
{
	return quant;
}

int cmp_price(const storage& left, const storage& right)
{
	if (left.price > right.price) {
		return	1;
	}
	else if (left.price < right.price) {
		return -1;
	}
	else return 0;
}
