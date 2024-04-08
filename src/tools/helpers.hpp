#include <vector>
#include <random>
#include <algorithm>

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
        const bool isAsc = percentage >= 0;
        const int start = data.size() * (percentage / 100);

        if (isAsc) {
            std::sort(data.begin(), data.begin() + start);
        } else {
            std::sort(data.begin(), data.end(), std::greater<int>());
        }
    }
}
