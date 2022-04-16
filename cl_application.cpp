#include "cl_application.h"
#include "cl_branch,h.h"
#include "class_2.h"
#include "class_3.h"
#include "class_4.h"
#include "class_5.h"
#include "class_6.h"
void application::build_Tree() {
	string name_of_p, name_of_ch; // Вводимые имена 
	int temp,j=0;
	cin >> name_of_p;
	this->set_name(name_of_p);
	cl_base* head = this, * br = nullptr; // Создание головного объекта
	cin >> name_of_p;
	while (name_of_p != "endtree") {
		j++;
		cin >> name_of_ch >> temp; 
		switch (temp)
		{
		case 2:
			br = new cl_2(get_object_by_name(name_of_p), name_of_ch);
			break;
		case 3:
			br = new cl_3(get_object_by_name(name_of_p), name_of_ch);
			break;
		case 4:
			br = new cl_4(get_object_by_name(name_of_p), name_of_ch);
			break;
		case 5:
			br = new cl_5(get_object_by_name(name_of_p), name_of_ch);
			break;
		case 6:
			br = new cl_6(get_object_by_name(name_of_p), name_of_ch);
			break;
		}
		cin >> name_of_p;
	}
		
}

int application::executeApp() {
	cout << "Object tree\n"<<this->get_name() << endl;	
	this->print_tree(1); // Вызов метода для вывода дерева иерархии
	this->Status_setter();
	if (this->get_value() == 0)
		cout << this->get_name() << " is not ready";
	else
		cout << this->get_name() << " is ready";
	this->Print_status(1);
	return 0;

}






















