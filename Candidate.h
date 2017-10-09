///////////////////////////////////////////////////////////
//  Candidate.h
//  Implementation of the Class Candidate
//  Created on:      29-apr-2016 12:21:49
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#pragma once
#if !defined(EA_7A409EEF_08F2_4f8e_AF68_E655240FDA21__INCLUDED_)
#define EA_7A409EEF_08F2_4f8e_AF68_E655240FDA21__INCLUDED_

#include "Zone.h"
#include "IndexedObject.h"
#include "Sortable_Unsorted_TableList.h"
class Candidate : public IndexedObject
{

public:
	Candidate(int id, string name);
	void tryAddBestZone(Zone* zone, int votes);
	void addDisPrefVote(District * d, int votes);

	DS::Sortable_Unsorted_TableList<District*, int> * getDisPrefVotes();
	Zone * getBestZone();
	int getBestZoneVotes();
	virtual ~Candidate();
private:
	
	Zone *bestZone_;
	int bestZoneValue_;
	DS::Sortable_Unsorted_TableList<District*, int> *disPrefVotes_;


};

int compareCand(const Candidate* & a, const Candidate* & b);
#endif // !defined(EA_7A409EEF_08F2_4f8e_AF68_E655240FDA21__INCLUDED_)
