#include "TV.h"
#include<iostream>
using namespace std;

int main() {
	TV tv;
	Radio radio;
	Remote remote(&tv);
	remote.setPover(Item::Pover::ON);
	remote.setNumber(11);
	remote.nextChenel();
	remote.setSound(34);
	remote.print();
	Remote remote2(&radio);
	remote2.setPover(Item::Pover::ON);
	remote2.setNumber(34);
	remote2.setSound(43);
	remote2.print();
}