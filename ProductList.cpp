#include "ProductList.h"

ProductList::ProductList()
{
    NodeProducts* current = head;
    while (current != nullptr) {
        NodeProducts* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
}

void ProductList::addProduct(Product* product)
{
    NodeProducts* newNode = new NodeProducts(product);
    newNode->setNext(head);
    head = newNode;
}

NodeProducts* ProductList::searchByID(string id)
{
    //Function to search Products by their ID
    NodeProducts* current = head;
    while (current != nullptr) {
        if (current->getProduct()->getID() == id) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

NodeProducts* ProductList::searchByName(string name)
{
    NodeProducts* current = head;
    while (current != nullptr) {
        if (current->getProduct()->getName() == name) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

bool ProductList::modifyQuantity(string id, int newQuantity)
{
    NodeProducts* node = searchByID(id);
    if (node != nullptr) {
        node->getProduct()->setQuantity(newQuantity);
        return true;
    }
    return false;
}
