#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

class DataExporter {
    std::vector<Results> results;

    public:
        DataExporter(
            const std::vector<Results>& _results
        ) : results(_results) {}

        void generate() {
            std::fstream fs(filename(), std::ios::out);

            if (!fs.is_open()) {
                std::cerr << "Could not open file " << filename() << std::endl;
                return;
            }

            const std::string header = "stack;average;presort;name\n";
            fs << header;

            for (auto result : results) {
                fs << result.stack << ";" << result.average() << ";" << result.presort << ";"  << result.name << "\n";
            }

            fs.close();
        }

    private:
        std::string filename() {
            return "results.csv";
        }
};
