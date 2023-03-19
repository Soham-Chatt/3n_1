#include <iostream>
#include <chrono>

void info() {
    std::cout << "This program is show the Collatz conjecture." << std::endl << std::endl;
}

int main() {
    info();

    long long value; int count=0; bool print; double time; bool stop;
    std::cout << "Give a value: ";
    std::cin >> value;
    std::cout << "Print steps? (1 = yes, 0 = no): ";
    std::cin >> print;
    std::cout << "Do you want the program to stop after a certain time? (no = 0, yes = specify time in seconds): ";
    std::cin >> time;
    time *= 1000; // Convert to milliseconds
    stop = time > 0; // Only keep track of time if time var > 0
    auto beg = std::chrono::high_resolution_clock::now(); // Start the clock

    while (value != 1) {
        if (stop) {
            auto lapse = std::chrono::high_resolution_clock::now(); // Lapse the clock
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(lapse - beg);
            if (duration.count() > time) {
                std::cout << "Sequence took longer than " << time << " seconds to calculate. We have performed " <<
                          count << " steps. Program terminated." << std::endl;
                break;
            }
        }
        if (print) {
            std::cout << value << " ";
        }
        value = (value % 2 == 0) ? value/2 : 3*value+1; // Follow the conjecture
        count++;
    }
    std::cout << std::endl << "Sequence finished successfully in " << count << " steps." << std::endl;
    return 0;
}
