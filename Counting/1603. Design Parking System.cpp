class ParkingSystem {
public:
	ParkingSystem(int big, int medium, int small): b(big), m(medium), s(small) {

	}

	bool addCar(int carType) {
		bool result = true;
		if (carType == 1)
		{
			result = b > 0;
			--b;
		}
		if (carType == 2)
		{
			result = m > 0;
			--m;
		}
		if (carType == 3)
		{
			result = s > 0;
			--s;
		}
		return result;
	}
	int b, m, s;
};


/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */