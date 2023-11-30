#include "class.hpp"

void Owner::owner_interact() {
    srand(time(0));
    for (auto& pet : vpets) {
        for (int i = 0; i < 3; ++i) {
            int action = rand() % 3;  // Generiraj slučajan broj (0, 1, ili 2)
            switch (action) {
            case 0:
                pet.feed();
                break;
            case 1:
                pet.sleep();
                break;
            case 2:
                pet.play();
                break;
            default:
                break;
            }
        }
    }
}

