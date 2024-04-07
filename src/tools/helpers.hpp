#include <vector>
#include <random>

namespace Helpers {
    std::vector<int> generateArray(const int size) {
        std::random_device rd;
        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
        std::vector<int> numbers;

        for (int i = 0; i < size; ++i) {
            numbers.push_back(dist(gen));
        }

        return numbers;
    }

    void preSort(std::vector<int>& data, const float percentage) {
        const int start = data.size() * percentage / 100;
        std::cout << "Presorting " << start << " elements for " << data.size() << std::endl;
        std::sort(data.begin(), data.begin() + start);
    }
}
