#pragma once
#include <vector>
#include <string>

void init_local_workspace(const std::string& platform, const std::string& problem_id);

void handle_init(const std::vector<std::string>& args);
