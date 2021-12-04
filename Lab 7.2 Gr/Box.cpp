#include "Box.h"
#include<iostream>
#include<ctime>



void Box::creation_amount()
{
	amountBox = rand() % 1000;
}

Box::Box()
{
	creation_amount();
	busy = false;
}

Box::Truck::Truck()
{
	amountTrack = 0;
	infoAmountTrack = 0;
	numTruck = 0;
	loadTruck = true;
}

Box::Truck Box::box_loading(Truck truck)
{
	busy = true;
	do
	{
		amountBox--;
		truck.truck_loading();
	} while (truck.loadTruck  && check_amount());
	
	busy = false;
	return truck;
}

Box::Truck Box::Truck::truck_loading()
{
	this->amountTrack++;
	if (this->amountTrack == MAX_TRACK)
	{
		this->loadTruck = false;

	}
	return *this;
}

bool Box::Truck::truck_trip()
{
	amountTrack--;
	infoAmountTrack++;
	if (amountTrack != 0)
	{
		this->truck_trip();
	}
	else
	{
		return true;
	}
}

bool Box::check_amount()
{
	if (amountBox != 0)
	{
		return true;
	}
	else return false;
}

void Box::infoBox()
{
	std::cout << "Количество оставшегося груза в боксе: " << amountBox << "\n";
	std::cout << "Занят ли бокс: " << busy << "\n";
}

void Box::Truck::infoTruck()
{
	std::cout << "Количество оставшегося груза в грузовике: " << amountTrack << "\n";
	std::cout << "Номер грузовика: " << numTruck << "\n";
	std::cout << "Всего перевезено груза: " << infoAmountTrack << "\n";
}

Box::Truck Box::processLoading(Truck truck)
{
	if (busy == false)
	{
		truck = box_loading(truck);
		return truck;
	}
	else
	{
		return truck;
	}

}

