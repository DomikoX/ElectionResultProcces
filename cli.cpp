#include "cli.h"
#include <ctime>
#include <climits>
#include <iomanip>
#include <sstream>
#include <iostream>
//#include "Windows.h"



Cli::Cli(App* target) :
	target_(target),
	menu_(ArrayList<MItem>(18,nullptr))
{
	menu_.add(MItem(string("Koniec"), &Cli::endFcion));
	menu_.add(MItem(string("Statistiky politickych strán"), &Cli::showGroupStatistics));
	menu_.add(MItem(string("Infromacie o okrese"), &Cli::findDistrict));
	menu_.add(MItem(string("Triedenie okrskov"), &Cli::sortDistricts));
	menu_.add(MItem(string("Zobrazenie kandidatov"), &Cli::showCandidates));
}


Cli::~Cli()
{
}



void Cli::printMenu()
{
	cout << "******Menu******" << endl;
	int i = 0;
	for (MItem item : menu_) {
		cout << left << setw(5) << to_string(i) << item.toString() << endl;
		i++;
	}
	cout << "Please enter a number:" << endl;
}

void Cli::run()
{
	
	printMenu();
	int result = getInteger(0, menu_.size() - 1);

	system("cls");
	cout << "***********************" << endl
		<< menu_[result].toString() << endl
		<< "***********************" << endl;
	menu_[result].run(this);
	cout << endl;
	if (result != 0) {
		run();
	}
}

int Cli::getInteger(int from, int to)
{
	string pomT = getString();
	int pom;
	try
	{
		pom = stoi(pomT);
		if (pom < from || pom > to) {
			throw exception("Invalid parameter");
		}
	}
	catch (const std::exception&)
	{
		printf("You entered bad Number\n");
		return getInteger(from, to);
	}

		
	
	return pom;

}

string Cli::getString()
{
	//cin.ignore();
	string pom;
	std::getline(std::cin, pom);
	
	return pom;
}

void Cli::showGroupStatistics()
{

	cout << "Enter index of group" << endl;
	printGroups();
	int index = getInteger(1, target_->getGroups()->size());

	Group* group = (*target_->getGroups())[index-1];

		cout << "Celkový výsledok: " << setprecision(4) <<(*group).getPercentage() << "%"<< endl <<  endl;

		cout << "Najlepši kraj: " + (*group).getBestRegionString() << endl;
		cout << "Najhorší kraj: " + (*group).getWorstRegionString() << endl;
		cout << "Najlepši okrsok: " + (*group).getBestZoneString() << endl;
		cout << "Najhorší okrsok: " + (*group).getWorstZoneString() << endl;

	

}

void Cli::printGroups()
{
	cout << setw(10) << left << "ID"
		<< setw(30) << "Name"
		<< endl << "*****************************************************" << endl;
	
	int i = 1;
	for (auto pom : *target_->getGroups()) {

		cout << setw(10) << left << i++
			<< setw(50) << pom->getName()
			<< setw(15) << pom->getCandidates()->size()
			<< endl;
	}

}

void Cli::findDistrict()
{
	cout << "Zadajte názov okresu:" << endl;
	string choose = getString();
	District ** dis = nullptr;
	if (!target_->getDistrict()->tryFind(choose, dis)) {
		cout << "Lutujem takýto okrsok sme nenašli" << endl;
		return;
	}

	cout << setw(25) << left << (*dis)->getName() << "(" << (*dis)->getDivision() << ")"
		<< endl;

	for (auto zone : *(**dis).getZones()) {
		cout <<  setw(20) << left << zone->getData()->getName()<< endl;
		Sortable_Unsorted_TableList<Group*, double>* votes = zone->getData()->getGroupPercentageVotes();
		votes->sortBy(functionCompareInverse);

		for (auto gro : *votes) {
			cout <<"        "<< setw(50) << left << gro->getKey()->getName() << setprecision(4) << gro->getData()<<"%" << endl;
			
		}

	}
}

void Cli::printDistricts()
{
	cout << setw(30) << left << "Name" << "(Obvod)"
		<< endl << "*****************************************************" << endl;

	for (auto pom : *target_->getDistrict()) {

		cout << setw(25) << left <<  pom->getData()->getName() << "(" << pom->getData()->getDivision() << ")" 
			<< endl;
	}
}

int functionCompareCanByName(  Candidate* const &a, Candidate* const &b)
{
	return a->getName().compare(b->getName());
}

void Cli::showCandidates()
{

	cout << "Enter index of group" << endl;
	printGroups();
	int index = getInteger(1, target_->getGroups()->size());

	Group* group = (*target_->getGroups())[index-1];
	

	cout << "Zoradi:" << endl
		<< "1. Abecedne" << endl
		<< "2. Poètu pref. hlasov vo zvolenom okrese " << endl;

	int sortBy = getInteger(1, 2);
	 (sortBy == 1) ? showCandidatesAlphabeticaly(group) : showCandidatesByDistrict(group);
	




}

void Cli::showCandidatesAlphabeticaly(Group *group)
{


	Sortable_Unsorted_TableList<int, Candidate *>  *candidates = (*group).getCandidates();

	candidates->sortBy(functionCompareCanByName);

	for (auto can : *candidates) {
		cout << setw(25) << left << can->getData()->getName()
			<< setw(30) << can->getData()->getBestZone()->getName()
			<< setw(5) << can->getData()->getBestZoneVotes() << " hlasov"
			<< endl;
		
	}


}

void Cli::showCandidatesByDistrict(Group * group)
{

	cout << "Zadajte názov okresu:  (0 ak chcete zoradi na celom Slovensku)" << endl;
	string choose = getString();
	DS::Sortable_Unsorted_TableList<Candidate*, int> prefVotes(functionCompare);


	try
	{
		if (stoi(choose) == 0) {
			// Spoèitam hodnoty na celom slovensku 

			for (auto can : *(*group).getCandidates()) {

				int votes = 0;
				for (auto dis : *can->getData()->getDisPrefVotes()) {
					votes += dis->getData();
				}
				prefVotes.insert(can->getData(), votes);
			}

		}
		else {
			throw std::exception();
		}
	}
	catch (const std::exception&)
	{
		District ** dis = nullptr;
		if (!target_->getDistrict()->tryFind(choose, dis)) {
			cout << "Lutujem takýto okrsok sme nenašli" << endl;
			return;
		}
		for (auto can : *(*group).getCandidates()) {
			int* votes = nullptr;
			if (can->getData()->getDisPrefVotes()->tryFind(*dis, votes)) {
				prefVotes.insert(can->getData(), *votes);

			}
		}
	}

	prefVotes.sortBy(functionCompareInverse);

	for (auto can : prefVotes) {
		cout << setw(25) << left << can->getKey()->getName()
			<< setw(5) << can->getData() << " hlasov"
			<< endl;
	}

}

int zoneCompareByRegisteredPeople(Zone* const &a, Zone* const &b) {
	return functionCompareInverse(a->getRegisteredPeople(), b->getRegisteredPeople());
}

void Cli::sortDistricts()
{
	cout << "Zadajte názov okresu:  (0 ak chcete zoradi všetky okresy)" << endl;
	string choose = getString();
	Sortable_Unsorted_TableList<int, Zone*> zones = nullptr;
	try
	{
		if (stoi(choose) == 0) {
			// zoradi všetky okrsky
			for (auto dis : *target_->getDistrict()) {
				for (auto zon : *dis->getData()->getZones()) {
					zones.insert(zon->getKey(), zon->getData());
				}
			}

		}
		else {
			throw std::exception();
		}
	}
	catch (const std::exception&)
	{
			District ** dis = nullptr;
			if (!target_->getDistrict()->tryFind(choose, dis)) {
				cout << "Lutujem takýto okrsok sme nenašli" << endl;
				return;
			}
			for (auto zon : *(*dis)->getZones()) {
				zones.insert(zon->getKey(), zon->getData());
			}
	}

	cout << "Zoradi podla:" << endl
		<< "1. Poctu zapisaných volicov" << endl
		<< "2. Realtivneho výsledku danej politickej strany" << endl
		<< "3. Absolutneho výsledku danej politickej strany" << endl
		<< "4. Poètu pref. hlasov ktoré dosali spolu clenovia vybranej politickej strany " << endl;

	int sortBy = getInteger(1,4);

	if (sortBy == 1) {
		zones.sortBy(zoneCompareByRegisteredPeople);

		for (auto zon : zones) {
			cout << left << setw(35) << zon->getData()->getName() 
				<<  zon->getData()->getRegisteredPeople() << "ludi " << endl;
		}
		return;
	}


	cout << "Enter index of group" << endl;
	printGroups();
	int index = getInteger(1, target_->getGroups()->size());

	Group* group = (*target_->getGroups())[index-1];
	

	Sortable_Unsorted_TableList<Zone*, double> votesZones(functionCompare);


	switch (sortBy)
	{

	case 2:

		for (auto zon : zones) {
			double *votes;
			if (zon->getData()->getGroupPercentageVotes()->tryFind((group), votes)) {
				votesZones.insert(zon->getData(), *votes);
			}
		}
		break;

	case 3:
		for (auto zon : zones) {
			int *votes;
			if (zon->getData()->getGroupVotes()->tryFind((group), votes)) {
				votesZones.insert(zon->getData(), *votes);
			}
		}

		break;

	case 4:

		for (auto zon : zones) {
			int *votes;
			if (zon->getData()->getGroupPrefVotes()->tryFind((group), votes)) {
				votesZones.insert(zon->getData(), *votes);
			}
		}
		break;
	default:
		break;
	}
	

	votesZones.sortBy(functionCompareInverse);

	for (auto zon : votesZones) {
		cout << left << setw(35) << zon->getKey()->getName()
			<< setprecision(4) << zon->getData() <<  ((sortBy == 2) ?  " %"  : " hlasov") << endl;
	}
	
}

void Cli::endFcion()
{
	cout << "Thanks for Using our system please come back again. :)" << endl;
}

Cli::MItem::MItem(string & text, mFcion fcion):
	text_(text),
	fcion_(fcion)
{
}

string& Cli::MItem::toString()
{
	return text_;
}

void Cli::MItem::run(Cli * owner)
{
	(owner->*fcion_)();
}