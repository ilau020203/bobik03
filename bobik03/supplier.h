#pragma once
#include"String.h"
/*
1. Название фирмы поставщика: текстовая строка
    юридический адрес : текстовая строка
   тип поставщика( 1- поставщик сырья, 2- поставщик оборудования):
                                   перечисляемый тип
сальдо (положительное - должны поставщику, отрицательное-наоборот):
                 дробное число
2. Cчетчик созданных объектов класса (СД)
*/
enum class Type:int{
    Raw=1,
    Equipment=2
};
class supplier
{
	String name;
    String uadres;
    Type  type;
    double saldo;
public:
    supplier(const char* name="",const char* uadres="",int type=1,double saldo=0);
    supplier(std::ifstream & is);

    void input();
    int cmp_name(const supplier& right)const;
    int cmp_name(const char* right)const;
    void save(std::ofstream&os)const;
    const char* get_name()const;
    const char* get_uadres()const;
    double get_saldo()const ;
    int get_type()const;
    const char * get_type_str()const;
    supplier& operator=(const supplier  & in);//перегрузил в стринг
    friend std::istream& operator>>(std::istream&,supplier& right);
};

