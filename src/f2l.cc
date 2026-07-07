#include "ggclirouter.h"
#include "commands/init.h"
#include <iostream>

int main(int argc, char* argv[]) {
    CLIRouter router;

    router.reg_cmd("init", handle_init);

    router.set_error_handler([](const std::string& msg) {
            std::cerr << "[f2l error] " << msg << "\n";
            });

    router.dispatch(argc, argv);
    return 0;
}
