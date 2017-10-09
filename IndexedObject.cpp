///////////////////////////////////////////////////////////
//  IndexedObject.cpp
//  Implementation of the Class IndexedObject
//  Created on:      29-apr-2016 12:21:52
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "IndexedObject.h"




IndexedObject::~IndexedObject() {

}

IndexedObject::IndexedObject(string name, int id) :
	name_(name),
	id_(id)
{
}

int IndexedObject::getId() {

	return id_;
}

string IndexedObject::getName() {

	return name_;
}

string IndexedObject::toString()
{
	return to_string(id_) + " " + name_;
}

