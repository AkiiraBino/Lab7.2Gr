#include "Box.h"
#include<iostream>
#include<ctime>



void Box::creation_amount()
{
	srand(time(NULL));
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
}

void Box::box_loading(Truck truck)
{
	busy = true;
	do
	{
		amountBox--;
	} while (truck.truck_loading() && check_amount());
	
	busy = false;
}

bool Box::Truck::truck_loading()
{
	this->amountTrack++;
	if (this->amountTrack == MAX_TRACK)
	{
		return(false);
	}
	else return true;
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
		box_loading(truck);
		return truck;
	}
	else
	{
		return truck;
	}

}