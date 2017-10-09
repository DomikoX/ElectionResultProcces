///////////////////////////////////////////////////////////
//  Group.cpp
//  Implementation of the Class Group
//  Created on:      29-apr-2016 12:21:51
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "Group.h"



Group::Group(int id, string name, double percentage) :
	IndexedObject(name, id),
	percentage_(percentage),
	candidates_(new Sortable_Unsorted_TableList<int, Candidate *>(nullptr)),
	bestRegionVote_(0),
	worstRegionVote_(INT_MAX),
	bestZoneVote_(0),
	worstZoneVote_(INT_MAX)
{
}

Group::~Group() {

	for (auto pom : *candidates_) {
		delete pom->getData();
	}
	delete candidates_;
	delete bestZone_;
	delete worstZone_;
}





void Group::addCandidate(int id, string name)
{
	candidates_->insert(id, new Candidate(id, name));
}

void Group::tryBestRegion(int region, int votes)
{
	if (votes > bestRegionVote_) {
		bestRegion_ = region;
		bestRegionVote_ = votes;
	}

	if (votes < worstRegionVote_) {
		worstRegionVote_ = votes;
		worstRegion_ = region;
	}
}

void Group::tryBestZone(Zone * zone, int votes)
{

	if (votes > bestZoneVote_) {
		bestZoneVote_ = votes;
		bestZone_ = zone;
	}
	if (votes < worstZoneVote_) {
		worstZoneVote_ = votes;
		worstZone_ = zone;
	}
	}

double Group::getPercentage()
{
	return percentage_;
}

string Group::getBestZoneString()
{
	return bestZone_->getName() + ": " + to_string(bestZoneVote_) + " hlasov";
}

string Group::getWorstZoneString()
{
	return worstZone_->getName() + ": " + to_string(worstZoneVote_) + " hlasov";
}

string Group::getBestRegionString()
{
	string regions[9] = { "Bratislavský kraj",
		"Trnavský kraj",
		"Trenèiansky kraj",
		"Nitriansky kraj",
		"Žilinský kraj",
		"Banskobystrický kraj",
		"Prešovský kraj",
		"Košický kraj",
		"Zahranièie" };
	return regions[bestRegion_ - 1] + ": " + to_string(bestRegionVote_) + " hlasov";
}

string Group::getWorstRegionString()
{
	string regions[9] = { "Bratislavský kraj",
		"Trnavský kraj",
		"Trenèiansky kraj",
		"Nitriansky kraj",
		"Žilinský kraj",
		"Banskobystrický kraj",
		"Prešovský kraj",
		"Košický kraj",
		"Zahranièie" };
	return regions[worstRegion_ - 1] + ": " + to_string(worstRegionVote_) + " hlasov";
}

Sortable_Unsorted_TableList<int, Candidate *> * Group::getCandidates()
{
	return candidates_;
}

string Group::toString()
{
	return IndexedObject::toString() + " cand:" + to_string(candidates_->size());
}
