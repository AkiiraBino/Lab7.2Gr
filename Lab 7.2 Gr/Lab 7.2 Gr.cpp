#include<iostream>
#include"Box.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	Box arrayBox;
	arrayBox.infoBox();
	Box::Truck arrayTruck;
	arrayTruck.infoTruck();
	arrayTruck = arrayBox.processLoading(arrayTruck);
	arrayTruck.infoTruck();
	arrayBox.infoBox();

}
