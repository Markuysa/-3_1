#ifndef branch_H2
#define branch_H2
#include <iostream>
#include <string>
#include <vector>
#include "cl_base.h"
class cl_2 :public cl_base {

public:
	cl_2(cl_base* root, string name) :cl_base(root, name) {}; // Наследованный от базового класса параметризированный коснструктор
	
};
#endif