///////////////////////////////////////////////////////////
//  Candidate.cpp
//  Implementation of the Class Candidate
//  Created on:      29-apr-2016 12:21:49
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "Candidate.h"


Candidate::Candidate(int id, string name) :
	IndexedObject(name, id),
	bestZone_(nullptr),
	bestZoneValue_(0),
	disPrefVotes_(new DS::Sortable_Unsorted_TableList<District*, int>(nullptr)) {

}

void Candidate::tryAddBestZone(Zone * zone, int votes)
{
	if (bestZone_ == nullptr || bestZoneValue_ < votes) {
		bestZone_ = zone;
		bestZoneValue_ = votes;
	}
}

DS::Sortable_Unsorted_TableList<District*, int>* Candidate::getDisPrefVotes()
{
	return disPrefVotes_;
}

Zone * Candidate::getBestZone()
{
	return bestZone_;
}

int Candidate::getBestZoneVotes()
{
	return bestZoneValue_;
}

Candidate::~Candidate() {
	delete bestZone_;
	delete disPrefVotes_;
}

void Candidate::addDisPrefVote(District * d, int votes)
{
	disPrefVotes_->insert(d, votes);
}

int compareCand(const Candidate* & a, const Candidate* & b)
{
	return 0;
}
