///////////////////////////////////////////////////////////
//  Zone.cpp
//  Implementation of the Class Zone
//  Created on:      29-apr-2016 12:21:54
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include "Zone.h"
#include "Group.h"
#include "Candidate.h"


Zone::Zone(int id, string name, District *district):
IndexedObject(name,id),
registeredPeolpe_(0),
district_(district),
prefVotes_(new DS::Sortable_Unsorted_TableList<Group*, int>(DS::functionCompare)),
groupVotes_(new DS::Sortable_Unsorted_TableList<Group*, int>(DS::functionCompare)),
groupVotesPercentage_(new DS::Sortable_Unsorted_TableList<Group*, double>(DS::functionCompare)){

}

void Zone::addPrefVote(Group *group, int votes)
{
	prefVotes_->insert(group,votes);
}

void Zone::addGroupVote(Group * group, int votes)
{
	groupVotes_->insert(group, votes);
}



void Zone::addGroupVotePercentage(Group * group, double votes)
{
	groupVotesPercentage_->insert(group, votes);
}

DS::Sortable_Unsorted_TableList<Group*, int>* Zone::getGroupVotes()
{
	return groupVotes_;
}

DS::Sortable_Unsorted_TableList<Group*, int>* Zone::getGroupPrefVotes()
{
	return prefVotes_;
}

Sortable_Unsorted_TableList<Group*, double>* Zone::getGroupPercentageVotes()
{
	return groupVotesPercentage_;
}

District * Zone::getDistrict()
{
	return district_;
}

void Zone::setRegisteredPeople(int value)
{
	registeredPeolpe_ = value;
}

int Zone::getRegisteredPeople()
{
	return registeredPeolpe_;
}

Zone::~Zone(){
	
	delete prefVotes_;
	delete groupVotes_;
	delete groupVotesPercentage_;
}