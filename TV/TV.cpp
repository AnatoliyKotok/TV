#include "TV.h"
#include<iostream>
using namespace std;




const char* Remote::getNametype() const
{
	const char* namePos[] = { "ON","OFF" };
	return namePos[item->pover];
}

void Remote::nextChenel()
{
	if (item->numberChenel < item->countChenels) {
		item->numberChenel += 1;
	}
	else {
		cout << "Incorect velue!" << endl;
		exit(0);
	}
}

void Remote::prevChenel()
{
	if (item->countChenels > 0) {
		item->numberChenel -= 1;
	}
	else {
		cout << "Incorect velue!" << endl;
		exit(0);
	}
}

void Remote::incVolume( int plus)
{
	if (plus > item->maxSound) {
		cout << "Incorect velue!" << endl;
		exit(0);
	}
	item->sound += plus;
	if (item->sound > item->maxSound) {
		item->sound -= plus;
		cout << "Incorect velue!" << endl;
		exit(0);
	}
}

void Remote::decVolume(int minus)
{
	if (minus < 0) {
		cout << "Incorect velue!" << endl;
		exit(0);
	}
	item->sound -= minus;
	if (item->sound < 0) {
		item->sound += minus;
		cout << "Incorect velue!" << endl;
		exit(0);
	}
}

void Remote::foundByChenel( int number)
{
	if (number > item->countChenels||number < 0) {
		cout << "Chenel not found" << endl;
		exit(0);
	}
	else {
		item->numberChenel = number;
	}
}
