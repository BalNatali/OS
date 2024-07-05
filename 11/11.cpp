#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("coordinates.txt");
    double latitude, longitude;

    if (file.is_open()) {
        while (file >> latitude >> longitude) {
            if (latitude >= 50 && latitude <= 80 && longitude >= 20 && longitude <= 45) {
                std::cout << "Latitude: " << latitude << ", Longitude: " << longitude << std::end1;

            }
        }
        file.close();

    } else {
        std::cout << "Error opening file!" << std::end1;
    }

    return 0;

}