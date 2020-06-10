#pragma once
#include<iostream>
using namespace std;
class TV
{
public:
	friend class Remote;
	
	enum Pover { ON, OFF };
	TV() = default;
	TV(int sound, int number) {
		setNumber(number);
		setSound(sound);
	}
	int setPover(Pover type);
	int setSound(const int sound);
	int setNumber(const int number);
	void print();
	const char* getNametype() const;
	void nextChenel();
	void prevChannel();
	void incVolume(int plus);
	void decVolume(int minus);
private:
	Pover pover=Pover::OFF;
	int sound;
	int numberChenel;
	const size_t countChenels=100;
	const size_t maxSound=50;
};

class Remote {
public:
	Remote()= default;
	void setPover( TV& other, TV::Pover pover) {
		if (other.pover >= TV::Pover::ON && other.pover <= TV::Pover::OFF) {
		   other.pover = pover;
		}
		if (other.pover == TV::Pover::OFF) {
			cout << "Pover off" << endl;
			exit(0);
		}
    }
	const char* getNametype(TV&other) const;
	void nextChenel(TV&other);
	void prevChenel(TV& other);
	void incVolume(TV&other,int plus);
	void decVolume(TV&other,int minus);
	void foundByChenel(TV& other,int number);
};