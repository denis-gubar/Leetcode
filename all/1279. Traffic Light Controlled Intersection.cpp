class TrafficLight {
    mutex m;
    condition_variable cv;
    int carCount1;
    int carCount2;
    int greenRoad;
public:
    TrafficLight() {
        carCount1 = carCount2 = 0;
        greenRoad = 1;
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        unique_lock lock(m);
        if (roadId == 1) ++carCount1;
        else ++carCount2;
        cv.notify_all();
        cv.wait(lock, [=]
                {
                    if (roadId == greenRoad)
                        return true;
                    if (roadId == 1 && carCount2 == 0)
                        return true;
                    if (roadId == 2 && carCount1 == 0)
                        return true;
                    return false;
                });        
        if (roadId != greenRoad)
        {
            greenRoad = roadId;
            turnGreen();
        }
        crossCar();
        if (roadId == 1) --carCount1;
        else --carCount2;
        cv.notify_all();
    }
};