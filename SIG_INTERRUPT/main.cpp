#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;


void signalHandler(int signum){
    cout << "Interrupt signal number(" << signum << ")caught" << endl;

    exit(signum);
}

int main() {

    // register signal SIGINT and signal handler
    signal(SIGINT, signalHandler);

    while(1){
        cout << "Going to sleep..." << endl;
        sleep(1);

    }

    system("pause");
    return 0;
}
