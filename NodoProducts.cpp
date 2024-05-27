#include "NodoProducts.h"
#include "Product.h"


using namespace std;
NodeProducts::NodeProducts(Product* product) {
	this->product = product;
	this->next = nullptr;

}

Product* NodeProducts::getProduct()
{
	return nullptr;
}

NodeProducts* NodeProducts::getNext()
{
	return nullptr;
}
void NodeProducts::setNext(NodeProducts* next) {
	this->next = next;
}
