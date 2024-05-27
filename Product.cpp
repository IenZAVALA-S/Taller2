#include "Product.h"
#pragma once

Product::Product(string name, float price, string iD, int stock, string category, string subcategory) {
	this->name = name;
	this->price = price;
	this->iD = iD;
	this->stock = stock;
	this->category = category;
	this->subcategory = subcategory;
}
float Product::getPrice() {
	return price;
}
string Product::getID() {
	return iD;
}
string Product::getName()
{
	return name;
}
int Product::getQuantity()
{
	return stock;
}
void Product::setPrice(float price) {
	this->price = price;
}
void Product::setID(string iD) {
	this->iD = iD;
}

void Product::setQuantity(int newStock)
{
	this->stock = newStock;
}
