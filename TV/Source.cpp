#include "TV.h"
#include<iostream>
using namespace std;

int main() {
	TV tv1{23,12 };
	Remote rem1;
	rem1.setPover(tv1, TV::Pover::ON);
	tv1.print();
	TV tv2{ 32,34 };
	rem1.setPover(tv2, TV::Pover::ON);
	//rem1.nextChenel(tv2);
	rem1.prevChenel(tv2);
	//rem1.incVolume(tv2, 18);
	rem1.decVolume(tv2, 30);
	rem1.foundByChenel(tv2, 55);
    tv2.print();
}