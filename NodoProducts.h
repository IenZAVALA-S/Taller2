#pragma once
#include "Product.h"
class NodeProducts
{
private:
	Product* product;
	NodeProducts* next;
public:
	NodeProducts(Product* product);
	Product* getProduct();
	NodeProducts* getNext();
	void setNext(NodeProducts* next);

};

