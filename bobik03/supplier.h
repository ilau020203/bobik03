#pragma once
#include"String.h"
/*
1. �������� ����� ����������: ��������� ������
    ����������� ����� : ��������� ������
   ��� ����������( 1- ��������� �����, 2- ��������� ������������):
                                   ������������� ���
������ (������������� - ������ ����������, �������������-��������):
                 ������� �����
2. C������ ��������� �������� ������ (��)
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
    supplier& operator=(const supplier  & in);//���������� � ������
    friend std::istream& operator>>(std::istream&,supplier& right);
};

