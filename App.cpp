///////////////////////////////////////////////////////////
//  App.cpp
//  Implementation of the Class App
//  Created on:      29-apr-2016 12:21:47
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include "App.h"
#include "Sortable_Unsorted_TableList.h"


using namespace std;

App::App():
groups_(new ArrayList<Group*>()),
districts_(new Table_ArrayList_Sorted<string,District*>(functionCompare)){
}



App::~App(){
	
	for (auto pom : *districts_) {
		delete pom->getData();
	}
	delete districts_;
	for (auto pom : *groups_) {
		delete pom;
	}
	delete groups_;
}

void App::initialize()
{

	loadGroups();
	loadDistricts();
	loadGroupsVotes();
	loadZonesRegisteredPeople();
	computeAdditionalData();

}

void App::loadGroups()
{
	cout << "Please wait start proceding: Vysledky_pre_PS_SR.csv" << endl;

	ifstream file;
	file.open("Vysledky_pre_PS_SR.csv");

	for (int i = 0; i < 23; i++)
	{
		string idS;
		getline(file, idS, ';');
		string name;
		getline(file, name, ';');
		string votesS;
		getline(file, votesS);
		int id = stoi(idS);
		double votes = stod(votesS);
		groups_->add(new Group(id, name, votes));


	}
	file.close();
	
	cout << "Finish proceding: Vysledky_pre_PS_SR.csv" << endl;


}



void App::loadDistricts()
{
	cout << "Please wait start proceding: Vysledky_prednostneho_hlasovania_okrsky.csv" << endl;

	ifstream file;
	file.open("Vysledky_prednostneho_hlasovania_okrsky.csv");
	ifstream secondfile;
	secondfile.open("Vysledky_prednostneho_hlasovania_okresy.csv");



	string pomS;
	getline(file, pomS, ';');
	getline(file, pomS, ';');
	getline(file, pomS, ';');
	getline(file, pomS, ';');
	
	// dostane prvy nazov strany
	getline(file, pomS, ';');
	
	//zisti kolko kandidatov ma každá strana
	ImplicitQueue<int> members = ImplicitQueue<int>(groups_->size());;
	
	for each (auto var in *groups_)
	{
		int cc = 0;
		do {
			cc++;
			getline(file, pomS, ';');
		} while (pomS == "");
		
		members.push(cc);
		
	}
	getline(file, pomS, ';');
	getline(file, pomS, ';');
	getline(file, pomS, ';');
	
	//naèita kandidatov pre každu stranu
	for each (auto var in *groups_)
	{
			int count = members.pop();
		for (int i = 0; i < count; i++)
		{

			getline(file, pomS, ';');

			stringstream linestream(pomS);
			string name;
			string surname;

			linestream >> name;
			linestream >> surname;
			pomS = surname + " " + name;
			var->addCandidate(i, pomS);
		}

	}

	getline(file, pomS);
	
	
	//naèita okrsky a hlasy pre kandidatov
	int zoneIndex = 0;

	int oldDistrictIndex = 0;
	District* dis = nullptr;
	bool readFromSecondFile = false;
	string secFilePom;
	stringstream ls2;

	// pre každý riadok v subore 
	while (getline(file, pomS))
	{
		stringstream linestream(pomS);
		string value;
		string division;
		getline(linestream, division, ';');

		string idOS;
		getline(linestream, idOS, ';');
		string district;
		getline(linestream, district, ';');
		string zoneS;
		getline(linestream, zoneS, ';');
		int idO = stoi(idOS);

		// na každom riadku kontrolujem èi som stále v tom isto okrese alebo dalšie zony už patria do iného okresu ako na predchadzajuom riadku
		if (idO != oldDistrictIndex) {
			oldDistrictIndex = idO;
			dis = new District(idO, district, division);
			districts_->insert(dis->getName(), dis);
			// ak máme nový okres tak naèitavame aj z druhého súboru (preferenène hlasy kandidatov v okresoch)
			readFromSecondFile = true;
			getline(secondfile, secFilePom);
			ls2 = stringstream(secFilePom);

		}
		else {
			readFromSecondFile = false;
		}

		
		Zone* zone = new Zone(++zoneIndex, zoneS,dis);

		dis->addZone(zone);
		for each (auto var in *groups_)
		{
			int prefVotes = 0;
				for (auto cand : *var->getCandidates()) {
					getline(linestream, value, ';');
					int number = value == "" ? 0 : stoi(value);
					prefVotes += number;
					cand->getData()->tryAddBestZone(zone, number);

					// naèitavnie len vžd yked je nový okres
					if (readFromSecondFile) {
						
						string numberPom;
						getline(ls2, numberPom, ';');
						int number2 = numberPom == "" ? 0 : stoi(numberPom);
						cand->getData()->addDisPrefVote(dis, number2);
					}

					
					
				}

				zone->addPrefVote(var, prefVotes);
							
		}

	}
	cout << "Finish proceding: Vysledky_prednostneho_hlasovania_okrsky.csv" << endl;

	file.close();
	secondfile.close();
}

void App::loadGroupsVotes()
{
	cout << "Please wait start proceding: Vysledky_pre_PS_okrsky.csv" << endl;

	ifstream file;
	file.open("Vysledky_pre_PS_okrsky.csv");
	string pomS;
	string value;
	int number;
	for (auto dis : *districts_) {
		for (auto zon : *dis->getData()->getZones()) {
			getline(file, pomS);
			stringstream linestream(pomS);
			
			for (auto gro : *groups_) {
				
				getline(linestream, value, ';');
				int number = value == "" ? 0 : stoi(value);
				zon->getData()->addGroupVote(gro, number);
				getline(linestream, value, ';');
				double numberD = value == "" ? 0 : stod(value);
				zon->getData()->addGroupVotePercentage(gro, numberD);

			}

		}

	}

		

	cout << "Finish proceding: Vysledky_pre_PS_okrsky.csv" << endl;

	file.close();
}

void App::loadZonesRegisteredPeople()
{
	cout << "Please wait start proceding: Suhrnne_vysledky_okrsky.csv" << endl;

	ifstream file;
	file.open("Suhrnne_vysledky_okrsky.csv");
	string pomS;


	int number;
	for (auto dis : *districts_) {
		for (auto zon : *dis->getData()->getZones()) {
			
			getline(file, pomS);
			int number = pomS == "" ? 0 : stoi(pomS);

			zon->getData()->setRegisteredPeople(number);

		}

	}


	file.close();
	cout << "Finish proceding: Suhrnne_vysledky_okrsky.csv" << endl;

	
}

void App::computeAdditionalData()
{

	
	for (auto dis : *districts_) {
		
			for (auto zone : *dis->getData()->getZones()) {
				
				for (auto gro : *zone->getData()->getGroupVotes()) {

					gro->getKey()->tryBestZone(zone->getData(), gro->getData());
	
				}
			}	

		}



	cout << "Please wait start proceding: Vysledky_pre_PS_kraje.csv" << endl;

	ifstream file;
	file.open("Vysledky_pre_PS_kraje.csv");
	string pomS;

	for (int i = 1; i <= 9; i++) {

		for (auto gro : *groups_) {
			getline(file, pomS, ';');
			int number = pomS == "" ? 0 : stoi(pomS);
			gro->tryBestRegion(i, number);

		}

	}

	file.close();

	cout << "Finish proceding: Vysledky_pre_PS_kraje.csv" << endl;


}

ArrayList< Group*>* App::getGroups()
{
	return groups_;
}

Table_ArrayList_Sorted<string, District*>* App::getDistrict()
{
	return districts_;
}


