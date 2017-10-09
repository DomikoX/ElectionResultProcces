///////////////////////////////////////////////////////////
//  District.cpp
//  Implementation of the Class District
//  Created on:      29-apr-2016 12:21:50
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "District.h"
#include "Zone.h"


District::District(int id, string name, string division) :
	IndexedObject(name, id),
	division_(division),
	zones_(new DS::Table_ArrayList_Unsorted<int, Zone*>(DS::functionCompare)) {

}

District::~District() {
	for (auto pom : *zones_) {
		delete pom->getData();
	}
}

void District::addZone(Zone * zone)
{
	zones_->insert(zone->getId(), zone);
}

DS::Table_ArrayList_Unsorted<int, Zone*>* District::getZones()
{
	return zones_;
}

string District::getDivision() {

	return division_;
}