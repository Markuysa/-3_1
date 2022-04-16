#include "cl_base.h"
#include <iomanip>
cl_base::cl_base(cl_base* p_head, string name) {
	this->obj_name = name; // Присваивание имени объекту
	if (p_head) { // Если не nullptr
		this->p_head = p_head;
		set_p(p_head);
	}
}
void cl_base::set_p(cl_base* ptr) {
	int size = p_head->childes.size(); // Размер массива наследников текущего гол.объекта
	for (int i = 0; i < size; i++) // Проход по всем потомкам родительского объекта и удаление объекта, который перестал подчиняться родительскому
	{
		if (p_head->childes[i] == this)
		{
			p_head->childes.erase(p_head->childes.begin() + i);
			break;
		}
	}
	p_head->childes.push_back(this); //Добавление указателя на текущий объект
	this->p_head = p_head;
}
cl_base* cl_base::get_object_by_name(string name)
{
	if (this->get_name() == name)
		return this;
	for (int i = 0; i < this->childes.size(); i++)
		if (this->childes[i]->get_object_by_name(name) != nullptr)
			return this->childes[i]->get_object_by_name(name);
	return nullptr;
}
void cl_base::set_name(string name) {
	this->obj_name = name; // Установка имени объекта
}
string cl_base::get_name() {
	return obj_name; // Возврат имени объекта
}

void cl_base::print_tree(int num_of_tabs) {
	string tabulaion=string(num_of_tabs*4,' ');

	for (int i = 0; i < this->childes.size(); i++) {
		cout << tabulaion << this->childes[i]->get_name() << endl;
		if (this->childes[i]->childes.size() != 0) {
			this->childes[i]->print_tree(num_of_tabs+1);
			}
		}
	}

void cl_base::Status_setter() {
	string name;
	int temp;
	int j = 7;
	while (j != 0) {
		j--;
		cin >> name >> temp;
		if (get_object_by_name(name)->get_phead() != nullptr && get_object_by_name(name)->get_phead()->get_value() == 0)
			get_object_by_name(name)->set_value(0);
		else
			get_object_by_name(name)->set_value(temp);
	}
}

void cl_base::Print_status(int num_of_tabs) {
	string tabulaion = string(num_of_tabs * 4, ' ');
	for (int i = 0; i < this->childes.size(); i++)
	{
		if (this->childes[i]->get_value() == 0) {
			cout << endl << tabulaion << this->childes[i] -> get_name() << " is not ready";
		}
		else {
			cout << endl << tabulaion << this->childes[i] -> get_name() << " is ready";
		}
			if (this->childes[i]->childes.size() != 0)
			{
				this->childes[i]->Print_status(num_of_tabs + 1);
			}
	}
}
