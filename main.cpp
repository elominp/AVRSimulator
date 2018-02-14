#include <cstdlib>
#include <iostream>
#include "AVRSimulator.h"

using athome::utils::AVRSimulator;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " firmware.hex" << std::endl;
        return EXIT_FAILURE;
    }
    AVRSimulator simulator(argv[1]);
    simulator.init();
    simulator.run();
    return 0;
}