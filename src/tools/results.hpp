#include <vector>

class Results
{
    public:
        std::string name;
        std::vector<int> durations;
        int presort;
        int stack;

        Results(
            std::string name,
            int stack,
            int presort
        ) : name(name), stack(stack), presort(presort) {}

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
