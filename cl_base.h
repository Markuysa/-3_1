#ifndef _cl_base_
#define _cl_base_
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class cl_base {
private:	 
	string obj_name; // Имя объекта
	cl_base* p_head; // Указатель на головной объект
	int value=0;
	vector<cl_base*> childes; // Вектор наследников
public:
	
	int get_value() { return this->value; }
	void set_value(int value) { this->value = value; }
	cl_base(cl_base* p_head, string name = "root"); // Параметризированный конструктор
	void set_name(string name); // Сеттер имени объекта
	string get_name(); // Геттер имени объекта
	void print_tree(int num_of_tabs); // Метод для вывода дерева иерархии
	void set_p(cl_base* ptr); // Метод установки указателя на родителя
	cl_base* get_phead() { return this->p_head; }; // Метод для получения указателя на г.объект
	cl_base* get_object_by_name(string name);
	void Status_setter();
	void Print_status(int num_of_tabs);
};
#endif 


















