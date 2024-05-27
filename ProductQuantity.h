#pragma once
#include "Product.h"
class ProductQuantity
{
private:
	Product* product;
	int quantity;
	ProductQuantity* next;
public:
	ProductQuantity(Product* product, int quantity);
	Product* getProduct();
	int getQuantity();
	ProductQuantity* getNext();
	

};

