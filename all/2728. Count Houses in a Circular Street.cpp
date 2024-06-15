/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void openDoor();
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 *     void moveLeft();
 * };
 */
class Solution {
public:
    int houseCount(Street* street, int k) {
        for(int i = 0; i < k; ++i)
            street->openDoor(), street->moveRight();
        int result = 0;
        while(street->isDoorOpen())
            street->closeDoor(), street->moveRight(), ++result;
        return result;
    }
};