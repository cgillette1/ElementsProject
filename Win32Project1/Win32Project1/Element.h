#pragma once
#include<string>
#include <fstream>
#include <iostream>

using namespace std;

class Element
{
protected:
	int atomicnumber;
	string chemname;
	string chemsum;
	int group;
	int period;
	float atomicweight;
	float meltpt;
	float boilpt;
	float hhbondl;
	string econfig;
	string oxstate;
	float fionp;
	float eaffinity;
	bool searchedfor;
public:
	Element();
	~Element();

	void getFileData(int filenumber);
	Element searchbyGroup(int groupnumber, Element elementobj[107]);

	//Getters
	int getAtomicNumber();
	string getChemName();
	string getChemSum();
	int getGroup();
	int getPeriod();
	float getAtomicWeight();
	float getMeltPt();
	float getBoilPt();
	float getHhBondL();
	string getEConfig();
	string getOxState();
	float getFIonP();
	float getEAffinity();
	bool getSearchedFor();

	//Setters
	void setAtomicNumber(int g);
	void setChemName(string g);
	void setChemSum(string g);
	void setGroup(int g);
	void setPeriod(int g);
	void setAtomicWeight(float g);
	void setMeltPt(float g);
	void setBoilPt(float g);
	void setHhBondL(float g);
	void setEConfig(string g);
	void setOxState(string g);
	void setFIonP(float g);
	void setEAffinity(float g);
	void setSearchedFor(bool g);
};

