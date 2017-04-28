#include "stdafx.h"
#include "Element.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Element::Element()
{
}


Element::~Element()
{
}
//Getters
int Element::getAtomicNumber() { return atomicnumber; }
string Element::getChemName() { return chemname; }
string Element::getChemSum() { return chemsum; }
int Element::getGroup() { return group; }
int Element::getPeriod() { return period; }
float Element::getAtomicWeight() { return atomicweight; }
float Element::getMeltPt() { return meltpt; }
float Element::getBoilPt() { return boilpt; }
float Element::getHhBondL() { return hhbondl; }
string Element::getEConfig() { return econfig; }
string Element::getOxState() { return oxstate; }
float Element::getFIonP() { return fionp; }
float Element::getEAffinity() { return eaffinity; }
bool Element::getSearchedFor() { return searchedfor; }

//Setters
void Element::setAtomicNumber(int g) { atomicnumber = g; }
void Element::setChemName(string g) { chemname = g; }
void Element::setChemSum(string g) { chemsum = g; }
void Element::setGroup(int g) { group = g; }
void Element::setPeriod(int g) { period = g; }
void Element::setAtomicWeight(float g) { atomicweight = g; }
void Element::setMeltPt(float g) { meltpt = g; }
void Element::setBoilPt(float g) { boilpt = g; }
void Element::setHhBondL(float g) { hhbondl = g; }
void Element::setEConfig(string g) { econfig = g; }
void Element::setOxState(string g) { oxstate = g; }
void Element::setFIonP(float g) { fionp = g; }
void Element::setEAffinity(float g) { eaffinity = g; }
void Element::setSearchedFor(bool g) { searchedfor = g; }

void Element::getFileData(int filenumber) {
	string filename = "C:\\Users\\michi\\Desktop\\Project Input Files\\ELE\\ELE" + to_string(filenumber);
	//cout << filename << endl;
	ifstream element;
	string dummy;
	string dummy2;
	string dummy3;
	string dummy4;

	element.open(filename);
	if (element.is_open()) {
		element >> atomicnumber;
		//cout << "Atomicnumber: " << atomicnumber << endl;
		element.ignore();

		getline(element, chemname);
		//cout << "Chemname: " << chemname << endl;

		element >> chemsum;
		//cout << "chemsum: " << chemsum << endl;
		element.ignore();

		getline(element, dummy3);
		//std::cout << "dummy3 " << dummy3 << endl;
		if (dummy3.empty()) {}
		else {
			if(dummy3.length() == 1){
				group = atoi(dummy3.c_str());
			}
			else {
				if (dummy3.at(1) == '-') {
					group = 0;
				}
				else {
					group = atoi(dummy3.c_str());
					//cout << "Group: " << group << endl;
				}
			}
		}

		element >> period;
		//cout << "Period: " << period << endl;
		
		element >> atomicweight;
		//cout << "atomicweight " << atomicweight << endl;
		
		element.ignore();
		std::getline(element, dummy);
		//std::cout << "dummy " << dummy << endl;
		if (dummy.empty()) { cout << "empty meltpt" << endl; }
		else {
			if (dummy.at(1) == '-') {
				meltpt = 0;
			}
			else {
				//dummy2 = new char[sizeof(dummy) + 1];
				//meltpt = strtof(dummy2, NULL);
				meltpt = strtof((dummy).c_str(), 0);
			}
		}
		//cout << "meltpt: " << meltpt << endl;

		std::getline(element, dummy4);
		//std::cout << "dummy4 " << dummy4 << endl;
		if (dummy4.empty()) {}
		else {
			if (dummy4.at(1) == '-') {
				boilpt = 0;
			}
			else {
				boilpt = strtof((dummy4).c_str(), 0);
				//dummy5 = new char[sizeof(dummy4) + 1];
				//boilpt = strtof(dummy5, NULL);
			}
		}
		//cout << "Boilpt: " << boilpt << endl;


		element.ignore();
		//element >> hhbondl;
		std::getline(element, dummy2);
		//std::cout << "dummy2 " << dummy2 << endl;
		if (dummy2.empty()) {}
		else {
			if (dummy2.at(1) == '-') {
				hhbondl = 0;
			}
			else {
				hhbondl = strtof((dummy2).c_str(), 0);
			}
		}
		//cout << "hhbondl: " << hhbondl << endl;

		element.ignore();
		std::getline(element, econfig);
		//cout << "econfig: " << econfig << endl;

		element.ignore();
		std::getline(element, oxstate);
		//cout << "oxstate: " << oxstate << endl;

		element >> fionp;
		//cout << "fionp: " << fionp << endl;

		element >> eaffinity;
		//cout << "eaffinity " << eaffinity << endl;
		
	}
	else {
		cout << "File did not open successfully";
	}
	element.close();
}

/*Element Element::searchbyGroup(int groupnumber, Element elementobj[107]) {
	for (int i = 0; i < 107; i++) {
		if (elementobj[i].getGroup == groupnumber) {
			elementobj[i].setSearchedFor(true);
		}
		else {
			elementobj[i].setSearchedFor(false);
		}
	}
}*/