///////////////////////////////////////////////////////////
//  App.h
//  Implementation of the Class App
//  Created on:      29-apr-2016 12:21:47
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#pragma once
#if !defined(EA_9E771F7E_E509_462e_BF26_D18B1E12E48D__INCLUDED_)
#define EA_9E771F7E_E509_462e_BF26_D18B1E12E48D__INCLUDED_

#include "Group.h"
#include "District.h"
#include "Table_ArrayList_Sorted.h"
#include "Table_ArrayList_Unsorted.h"
#include "ImplicitQueue.h"
using namespace DS;

class App
{
private:

	ArrayList<Group*> *groups_;
	Table_ArrayList_Sorted<string, District*> *districts_;
	void loadGroups();
	void loadDistricts();
	void loadGroupsVotes();
	void loadZonesRegisteredPeople();
	void computeAdditionalData();


public:
	App();
	virtual ~App();
	void initialize();


	ArrayList<Group*> *getGroups();
	Table_ArrayList_Sorted<string, District*> *getDistrict();



};
#endif // !defined(EA_9E771F7E_E509_462e_BF26_D18B1E12E48D__INCLUDED_)
