class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        if (sensor1 == sensor2)
            return -1;
        int result = 0;
        int N = sensor1.size();
        for (int i = 0; i < N; ++i)
        {
            if (equal(sensor1.begin() + i, sensor1.end() - 1, sensor2.begin() + i + 1, sensor2.end()))
            {
                if (result == 0 || result == 1)
                    result = 1;
                else
                    return -1;
            }
            if (sensor1[i] != sensor2[i])
                break;
        }
		for (int i = 0; i < N; ++i)
		{
            if (equal(sensor2.begin() + i, sensor2.end() - 1, sensor1.begin() + i + 1, sensor1.end()))
            {
                if (result == 0 || result == 2)
                    result = 2;
                else
                    return -1;
            }
			if (sensor1[i] != sensor2[i])
				break;
		}
        if (result == 0)
            result = -1;
        return result;
    }
};
