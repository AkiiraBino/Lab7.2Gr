#include<iostream>
#include"Box.h"


void simulation(Box arrayBox, Box::Truck arrayTruck)
{
	while (arrayBox.check_amount())
	{
		arrayTruck = arrayBox.processLoading(arrayTruck);
		arrayTruck.truck_trip();
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	char q[10];

	Box arrayBox;
	Box::Truck arrayTruck;

	simulation(arrayBox, arrayTruck);

	arrayBox.infoBox();
	arrayTruck.infoTruck();
	
	std::cin >> q;
}
