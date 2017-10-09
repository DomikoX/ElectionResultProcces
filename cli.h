#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include "App.h"




class MenuI;
class Cli
{

	using mFcion = void(Cli::*)();
public:
	
	Cli(App* target);
	~Cli();

	
	void printMenu();
	void run();
	int getInteger(int from, int to);
	string getString();
	

	void showGroupStatistics();
	void printGroups();

	void findDistrict();
	void printDistricts();

	void showCandidates();
	
	
	void sortDistricts();
	

	void endFcion();
	



private:
	void showCandidatesAlphabeticaly(Group *group);
	void showCandidatesByDistrict(Group *group);



	class MItem {
	public: 
		MItem(string &text, mFcion fcion);
		string& toString();
		void run(Cli *owner);
	private:
		string text_;
		mFcion fcion_;

	};

	ArrayList<MItem> menu_;
	App *target_;
	

};







