///////////////////////////////////////////////////////////
//  Group.h
//  Implementation of the Class Group
//  Created on:      29-apr-2016 12:21:51
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#pragma once
#if !defined(EA_C58C81DA_2F19_4386_85BE_CE4CA2714720__INCLUDED_)
#define EA_C58C81DA_2F19_4386_85BE_CE4CA2714720__INCLUDED_

#include "Candidate.h"
#include "District.h"
#include "Zone.h"
#include "IndexedObject.h"
#include "Table_ArrayList_Unsorted.h"

using namespace DS;

class Group : public IndexedObject
{
public:

	Group(int id, string name, double percentage);
	virtual ~Group();

	void addCandidate(int id, string name);
	void tryBestRegion(int region, int votes);
	void tryBestZone(Zone * zone, int votes);
	double getPercentage();
	string getBestZoneString();
	string getWorstZoneString();
	string getBestRegionString();
	string getWorstRegionString();

	Sortable_Unsorted_TableList<int, Candidate *> * getCandidates();
	string  toString();

private:
	Sortable_Unsorted_TableList<int, Candidate *>  *candidates_;
	double percentage_;

	Zone* bestZone_;
	Zone* worstZone_;
	int bestZoneVote_;
	int worstZoneVote_;


	int bestRegion_;
	int worstRegion_;
	int bestRegionVote_;
	int worstRegionVote_;

};
#endif // !defined(EA_C58C81DA_2F19_4386_85BE_CE4CA2714720__INCLUDED_)
