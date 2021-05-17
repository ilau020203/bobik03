#include "supplier.h"

supplier::supplier(const char* name, const char* uadres, int type, double saldo)
	:name(name),uadres(uadres),saldo(saldo)
{

	switch (type)
	{
	case 1:
		this->type = Type::Raw;
		break;
	case 2:
		this->type = Type::Equipment;
		break;
	default:
		break;
	}
}

supplier::supplier(std::ifstream& is)
:name(is),uadres(is)
{
	int buf;
	is >> saldo >> buf;
	switch (buf)
	{
	case 1:
		this->type = Type::Raw;
		break;
	case 2:
		this->type = Type::Equipment;
		break;
	default:
		break;
	}
}

void supplier::input()
{
	char buf[256];
	std::cout << "input name: " << std::endl; 
	std::cin >> buf;
	name = buf;
	std::cout << "input uadres: " << std::endl;
	std::cin >> buf;
	uadres = buf;
	std::cout << "input type(1 or 2)" << std::endl;
	int bf;
	std::cin >> bf;
	while((bf>2)||(bf<1)) 
		std::cin >> bf;
	switch (bf)
	{
	case 1:
		this->type = Type::Raw;
		break;
	case 2:
		this->type = Type::Equipment;
		break;
	default:
		break;
	}
	std::cout << "input saldo:" << std::endl;
	std::cin >> saldo;

}

int supplier::cmp_name(const supplier& right) const
{
	return name.cmp(right.name);
}

int supplier::cmp_name(const char* right) const
{
	return name.cmp(right);
}


void supplier::save(std::ofstream& os) const
{
	name.save(os);
	uadres.save(os);
	os << saldo << " " << (int)type<<std::endl;
}

const char* supplier::get_name()const
{
	return name.get_const_point_str();
}

const char* supplier::get_uadres()const
{
	return uadres.get_const_point_str();
}

double supplier::get_saldo()const
{
	return saldo;
}

int supplier::get_type()const
{
	return (int)type;
}

const char* supplier::get_type_str() const
{
	switch (type)
	{
	case Type::Raw:
		return"Raw";
		break;
	case Type::Equipment:
		return"Equipment";
		break;
	default:
		break;
	}
	return nullptr;
}

supplier& supplier::operator=(const supplier& in)
{
	if (&in != this) {
		name = in.name;
		uadres = in.uadres;
		type = in.type;
		saldo = in.saldo;
		return *this;
	}
	return *this;

}

std::istream& operator>>(std::istream& os, supplier& right)
{
	char buf[256];
	std::cout << "input name: " << std::endl;
	os >> buf;
	right.name = buf;
	std::cout << "input uadres: " << std::endl;
	os >> buf;
	right.uadres = buf;
	std::cout << "input type(1 or 2)" << std::endl;
	int bf;
	os >> bf;
	while ((bf > 2) || (bf < 1))
		os >> bf;
	switch (bf)
	{
	case 1:
		right.type = Type::Raw;
		break;
	case 2:
		right.type = Type::Equipment;
		break;
	default:
		break;
	}
	std::cout << "input saldo:" << std::endl;
	os >> right.saldo;

	return os;
}
