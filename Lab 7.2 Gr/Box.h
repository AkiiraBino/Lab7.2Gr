#pragma once

class Box
{
private:
	int amountBox;
	bool busy;

public:
	class Truck;
	Box();
	void infoBox();
	Truck processLoading(Box::Truck truck);
public:
	void creation_amount();
	Truck box_loading(Truck truck);
	bool check_amount();
};

class Box::Truck
{
private:
	int MAX_TRACK = 10;
	int amountTrack;
	int numTruck;
	int infoAmountTrack;

public:
	Truck();
	bool loadTruck;
	Truck truck_loading();
	bool truck_trip();
	void infoTruck();
};