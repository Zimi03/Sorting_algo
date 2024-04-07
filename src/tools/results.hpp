#include <vector>

class Results
{
    public:
        std::vector<int> durations;

        void push(int duration)
        {
            durations.push_back(duration);
        }

        float average() {
            if (durations.empty()) return 0;
            auto const count = durations.size();
            return std::reduce(durations.begin(), durations.end()) / count;
        }
};
