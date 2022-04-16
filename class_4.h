#ifndef branch_H4
#define branch_H4
#include <iostream>
#include <string>
#include <vector>
#include "cl_base.h"
class cl_4 :public cl_base {

public:
	cl_4(cl_base* root, string name) :cl_base(root, name) {}; // Наследованный от базового класса параметризированный коснструктор

};
#endif