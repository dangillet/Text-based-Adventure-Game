#ifndef GAMEENGINE_H_INCLUDED
#define GAMEENGINE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "character.h"
#include "world.h"

class GameEngine {
    public:
        GameEngine();
        bool Init();
        void UserInput();
        void Render();
        void CleanUp();


        bool Running;

    private:
        World           m_world;
        std::string     message;

        Object* FindArgObj(const std::string argument);
};

#endif // GAMEENGINE_H_INCLUDED
