#pragma once

const int MAX_TRACK = 10;

class Box
{
private:
	int amountBox;
	bool busy;

public:
	class Truck;
	Box();
	Truck processLoading(Box::Truck truck);
	void creation_amount();
	void box_loading(Truck truck);
	bool check_amount();
	void infoBox();
};

class Box::Truck
{
private:
	int amountTrack;
	int numTruck;
	int infoAmountTrack;

public:
	Truck();
	bool truck_loading();
	bool truck_trip();
	void infoTruck();
};