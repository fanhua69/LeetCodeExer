
#include "headers.h"

void pause()
{
    cout << "Paused, Press any key to continue..." << endl;
    char pause;
    cin >> pause;
}

int main()
{
    pause();
}