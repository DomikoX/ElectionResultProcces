///////////////////////////////////////////////////////////
//  IndexedObject.h
//  Implementation of the Class IndexedObject
//  Created on:      29-apr-2016 12:21:52
//  Original author: Doxisko
///////////////////////////////////////////////////////////

#pragma once
#if !defined(EA_8FBF70A3_A240_4e92_BF3F_37439C695AFD__INCLUDED_)
#define EA_8FBF70A3_A240_4e92_BF3F_37439C695AFD__INCLUDED_

#include <string>
using namespace std;
class IndexedObject
{

public:
	virtual ~IndexedObject();

	IndexedObject(string name, int id);
	int getId();
	string getName();
	string toString();

private:
	int id_;
	string name_;

};
#endif // !defined(EA_8FBF70A3_A240_4e92_BF3F_37439C695AFD__INCLUDED_)
