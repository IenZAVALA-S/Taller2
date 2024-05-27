#include <iostream>
#include "Product.h"

#pragma once
using namespace std;

class Customer
{
private:
	string name;
	int priority;
	int number_in_line;
public:
	Customer(string name,int priority, int number_in_line);

};

