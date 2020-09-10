#pragma once
#include<iostream>
using namespace std;
class Item
{
public:
	enum Pover { ON, OFF };
    Pover pover=Pover::OFF;
	int sound;
	int numberChenel;
	const size_t countChenels=100;
	const size_t maxSound=50;
};


class TV:public Item
{
public:

};
class Radio :public Item
{
public:

};
class Remote {
	Item* item;
public:
	Remote(Item* item) :item(item) {

	}
	void setPover(  Item::Pover pover) {
		if (item->pover >= TV::Pover::ON && item->pover <= Item::Pover::OFF) {
		   item->pover = pover;
		}
		if (item->pover == Item::Pover::OFF) {
			cout << "Pover off" << endl;
			exit(0);
		}
    }
	void setNumber(int number) {
		if (number > 0 && number <= item->countChenels) {
			item->numberChenel = number;
		}
		else {
			cout << "Invalid function" << endl;
			return;
		}
	}
	void setSound(int sound) {
		if (sound > 0 && sound <= item->maxSound) {
			item->sound = sound;
		}
		else {
			cout << "invalid function" << endl;
			return;
		}
	}
	void print() {
		cout << "Number chenel->" << item->numberChenel << endl;
		cout << "Sound->" << item->sound << endl;
	}
	const char* getNametype() const;
	void nextChenel();
	void prevChenel();
	void incVolume(int plus);
	void decVolume(int minus);
	void foundByChenel(int number);
};