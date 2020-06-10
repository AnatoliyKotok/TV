#include "TV.h"
#include<iostream>
using namespace std;


int TV::setPover(Pover type)
{
	if (type >= Pover::ON && type <= Pover::OFF) {
		this->pover = type;
	}
	if (this->pover == Pover::OFF) {
		cout << "Pover off" << endl;
		exit(0);
	}
	
}

int TV::setSound(const int sound)
{
	this->sound = sound;
	if (this->sound > maxSound) {
		cout << "Sound incorect" << endl;
		exit(0);
	}

}

int TV::setNumber(const int number)
{
	this->numberChenel = number;
	if (this->numberChenel > countChenels) {
		cout << "Chenels incorect" << endl;
		exit(0);
	}

}

void TV::print()
{
	cout << "Sound->" << sound << "\tNumber chenel->" << numberChenel << "\tPover->" << getNametype() << endl;;
}

const char* TV::getNametype() const
{
    const char* namePos[] = { "ON","OFF" };
	return namePos[pover];

}

void TV::nextChenel()
{
	if (numberChenel < countChenels) {
		this->numberChenel += 1;
	}
	else {
		cout << "Incorect velue!" << endl;
		exit(0);
	}
}

void TV::prevChannel()
{
	if (countChenels > 0) {
		this->numberChenel -= 1;
	}
	else {
		cout << "Incorect velue!" << endl;
		exit(0);
	}
}

void TV::incVolume(int plus)
{
	if (plus > maxSound) {
		cout << "Incorect velue!" << endl;
		exit(0);
	}
    this->sound += plus;
	if (this->sound > maxSound) {
		this->sound -= plus;
		cout << "Incorect velue!" << endl;
		exit(0);
	}
}

void TV::decVolume(int minus)
{
	if (minus < 0) {
		cout << "Incorect velue!" << endl;
		exit(0);
	}
	this->sound -= minus;
	if (this->sound < 0 ){
		this->sound += minus;
		cout << "Incorect velue!" << endl;
		exit(0);
	}
}

const char* Remote::getNametype(TV&other) const
{
	const char* namePos[] = { "ON","OFF" };
	return namePos[other.pover];
}

void Remote::nextChenel(TV& other)
{
	if (other.numberChenel < other.countChenels) {
		other.numberChenel += 1;
	}
	else {
		cout << "Incorect velue!" << endl;
		exit(0);
	}
}

void Remote::prevChenel(TV& other)
{
	if (other.countChenels > 0) {
		other.numberChenel -= 1;
	}
	else {
		cout << "Incorect velue!" << endl;
		exit(0);
	}
}

void Remote::incVolume(TV& other, int plus)
{
	if (plus > other.maxSound) {
		cout << "Incorect velue!" << endl;
		exit(0);
	}
	other.sound += plus;
	if (other.sound > other.maxSound) {
		other.sound -= plus;
		cout << "Incorect velue!" << endl;
		exit(0);
	}
}

void Remote::decVolume(TV& other, int minus)
{
	if (minus < 0) {
		cout << "Incorect velue!" << endl;
		exit(0);
	}
	other.sound -= minus;
	if (other.sound < 0) {
		other.sound += minus;
		cout << "Incorect velue!" << endl;
		exit(0);
	}
}

void Remote::foundByChenel(TV& other, int number)
{
	if (number > other.countChenels||number < 0) {
		cout << "Chenel not found" << endl;
		exit(0);
	}
	else {
		other.numberChenel = number;
	}
}
