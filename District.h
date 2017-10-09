///////////////////////////////////////////////////////////
//  District.h
//  Implementation of the Class District
//  Created on:      29-apr-2016 12:21:50
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#pragma once
#if !defined(EA_CF2F6F4C_9CCB_4fdb_A885_7A7EFFE87202__INCLUDED_)
#define EA_CF2F6F4C_9CCB_4fdb_A885_7A7EFFE87202__INCLUDED_


#include "IndexedObject.h"
#include "Table_ArrayList_Unsorted.h"

class Zone;
class District : public IndexedObject
{

public:
	District(int id, string name,string division);
	virtual ~District();
	void addZone(Zone* zone);
	DS::Table_ArrayList_Unsorted<int, Zone*> * getZones();
	string getDivision();

private:
	DS::Table_ArrayList_Unsorted<int, Zone*> *zones_;
	string division_;

};
#endif // !defined(EA_CF2F6F4C_9CCB_4fdb_A885_7A7EFFE87202__INCLUDED_)
