#include "main.h"

using namespace std;

int main()
{
    GameEngine adventure;
    if(!adventure.Init()) return 1;
    adventure.Render();

    while(adventure.Running)
    {
        adventure.UserInput();
        adventure.Render();
    }
    adventure.CleanUp();

    return 0;
}
