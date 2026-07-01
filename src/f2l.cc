// f2l
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

class ArgParser {
    std::vector<std::string> args;
public:
    ArgParser(int argc, char* argv[]) {
        args.assign(argv + 1, argv + argc);
    }

    bool has(const std::string& option) {
        for (const auto& arg : args) {
            if (arg == option) return true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    ArgParser parser(argc, argv);

    if (parser.has("-v") || parser.has("--version")) {
        std::cout << "f2l(Fetch to Local) version 0.1.0" << std::endl;
        return 0;
    }

    if (parser.has("-h") || parser.has("--help")) {
        std:: cout << "Help Info" << std::endl;
        return 0;
    }

    return 0;
}
