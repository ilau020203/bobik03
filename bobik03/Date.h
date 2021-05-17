#pragma once
#include<fstream>
#include<iostream>

	class Date
	{
	public:

		//Date();
		explicit Date(int number=1, int month=1, int year=0);
		Date(std::ifstream& fin);
		Date(const Date& input);
		char* get_str_month() const;
		int get_number() const;
		int get_month() const;
		int get_year()const;
		bool eql(Date input)const;
		friend bool later_date(Date a, Date b);
		void save(std::ofstream& fout)const;
		void input_date();
	private:
		int number;
		int month;
		int year;
	};
