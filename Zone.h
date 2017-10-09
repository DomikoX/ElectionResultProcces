///////////////////////////////////////////////////////////
//  Zone.h
//  Implementation of the Class Zone
//  Created on:      29-apr-2016 12:21:54
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#pragma once
#if !defined(EA_41BA3D62_2EDC_465d_91AB_14252EB6C7BE__INCLUDED_)
#define EA_41BA3D62_2EDC_465d_91AB_14252EB6C7BE__INCLUDED_

#include "District.h"
#include "IndexedObject.h"
#include "Sortable_Unsorted_TableList.h"
#include "Table_ArrayList_Unsorted.h"
class Group;
class Candidate;
class Zone : public IndexedObject
{

public:
	Zone(int id, string name, District *district);
	void addPrefVote(Group *group, int votes);
	void addGroupVote(Group *group, int votes);
	void addGroupVotePercentage(Group *group, double votes);
	DS::Sortable_Unsorted_TableList<Group*, int>* getGroupVotes();
	DS::Sortable_Unsorted_TableList<Group*, int>* getGroupPrefVotes();
	DS::Sortable_Unsorted_TableList<Group*, double>* getGroupPercentageVotes();
	District *getDistrict();
	void setRegisteredPeople(int value);
	int getRegisteredPeople();
	
	virtual ~Zone();
	
private:
	int registeredPeolpe_;
	District *district_;
	DS::Sortable_Unsorted_TableList<Group*, int> *prefVotes_;
	DS::Sortable_Unsorted_TableList<Group*, int> *groupVotes_;
	DS::Sortable_Unsorted_TableList<Group*, double> *groupVotesPercentage_;

};
#endif // !defined(EA_41BA3D62_2EDC_465d_91AB_14252EB6C7BE__INCLUDED_)
