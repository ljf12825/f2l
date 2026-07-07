#include "init.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void init_local_workspace(const std::string& platform, const std::string& problem_id) {
    std::string folder_path = "test/" + platform + "_" + problem_id; // TODO: mkdir at ~

    try {
        if (!fs::exists(folder_path)) {
            fs::create_directories(folder_path);
            std::cout << "\033[32m[Success]\033[0m Created workspace directory: " << folder_path << "\n";
        } else {
            std::cout << "\033[34m[Info]\033[0m Directory " << folder_path << " already exist.\n";
        }

        std::string q_path = folder_path + "/question.md";
        std::ofstream q_file(q_path);
        if (q_file.is_open()) {
            q_file << "# Problem: " << problem_id << "\n\n";
            q_file << "## Description\n";
            q_file << "Fetched from " << platform << ". Write problem details here.\n";
            q_file.close();
            std::cout << "  |-- Created: " << q_path << "\n";
        }

        // TODO: create several standard template to copy
        std::string s_path = folder_path + "/solution.cpp";
        std::ofstream s_file(s_path);
        if (s_file.is_open()) {
            s_file << "#include <iostream>\n\n";
            s_file << "int main() {\n";
            s_file << "// TODO: code here\n";
            s_file << "    return 0;\n";
            s_file << "}\n";
            s_file.close();
            std::cout << "  |-- Created: " << s_path << "\n";
        }

        std::ofstream in_file(folder_path + "/1.in");
        if (in_file.is_open()) {
            in_file << "2 3\n";
            in_file.close();
        }
        std::ofstream out_file(folder_path + "/1.out");
        if (out_file.is_open()) {
            out_file << "5\n";
            out_file.close();
        }
        std::cout << "  |-- Created: 1.in and 1.out\n";

        } catch (const fs::filesystem_error& e) {
            std::cerr << "\033[31m[Error]\033[0m Filesystem error: " << e.what() << "\n";
        }
}

void handle_init(const std::vector<std::string>& args) {
    if (args.size() < 2) {
        std::cerr << "Usage: f2l init <platform> <problem_id>\n";
        std::cerr << "Example: f2l init cf 1234A\n";
        return;
    }

    std::string platform = args[0];
    std::string problem_id = args[1];

    init_local_workspace(platform, problem_id);
}
