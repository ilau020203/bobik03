#include "Date.h"
/*
 Date::Date()
{
	std::cout << "Введите дату " << std::endl << "День (от 1 до 31): ";
	std::cin >> number;

	while ((number <= 0) || (number > 31))std::cin >> number;
	std::cout << std::endl << "Номер месяца(от 1 до 12): ";
	std::cin >> month;
	while ((month <= 0) || (month > 12)) std::cin >> month;

	std::cout << std::endl << "Год : ";
	std::cin >> year;
	std::cout << std::endl;

}*/

 Date::Date(int number, int month, int year) :number(number), month(month), year(year)
{
}

 Date::Date(std::ifstream& fin)
{
	fin >> number >> month >> year;
}

 Date::Date(const Date& input) :number(input.number), month(input.month), year(input.year)
{
}

char*  Date::get_str_month() const
{
	char* month_str = new char[10];
	switch (month)
	{
	case 1: {
		strcpy(month_str, "January");
		return month_str;
	}
	case 2: {
		strcpy(month_str, "February");
		return month_str;
	}
	case 3: {
		strcpy(month_str, "March");
		return month_str;
	}
	case 4: {
		strcpy(month_str, "April");
		return month_str;
	}
	case 5: {
		strcpy(month_str, "May");
		return month_str;
	}
	case 6: {
		strcpy(month_str, "June");
		return month_str;
	}
	case 7: {
		strcpy(month_str, "July");
		return month_str;
	}
	case 8: {
		strcpy(month_str, "August");
		return month_str;
	}
	case 9: {
		strcpy(month_str, "September");
		return month_str;
	}
	case 10: {
		strcpy(month_str, "October");
		return month_str;
	}
	case 11: {
		strcpy(month_str, "November");
		return month_str;
	}
	case 12: {
		strcpy(month_str, "December");
		return month_str;
	}
	}

	return nullptr;
}

int  Date::get_number() const
{
	return number;
}

int  Date::get_month() const
{
	return month;
}

int  Date::get_year() const
{
	return year;
}

bool  Date::eql(Date input) const
{
	return (input.number==number)&&(input.month==month)&&(year==input.year);
}

void  Date::save(std::ofstream& fout) const
{
	fout << number << " "<< month <<  " " << year << " ";
}

void  Date::input_date()
{
	std::cout << "Введите дату " << std::endl << "День (от 1 до 31): ";
	std::cin >> number;

	while ((number <= 0) || (number > 31))std::cin >> number;
	std::cout << std::endl << "Номер месяца(от 1 до 12): ";
	std::cin >> month;
	while ((month <= 0) || (month > 12)) std::cin >> month;

	std::cout << std::endl << "Год : ";
	std::cin >> year;
	std::cout << std::endl;
}

bool  later_date(Date a, Date b)
{
	if (a.year > b.year) {
		return 1;
	}
	else {
		if (a.year == b.year) {
			if (a.month > b.month) {
				return 1;
			}
			else {
				if (a.number == b.number) {
					if (a.number > b.number) {
						return 1;
					}
					else {
						if (a.number == b.number) {
							return 1;
						}
						else {
							return 0;
						}
					}
				}
				else {
					return 0;
				}
			}
		}
		else {
			return 0;
		}
	}
}
