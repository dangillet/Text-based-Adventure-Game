#ifndef GAMEENGINE_H_INCLUDED
#define GAMEENGINE_H_INCLUDED

#include <memory>

#include "world.h"

class Renderer;

class GameEngine {
    public:
        GameEngine();
        ~GameEngine();
        void Run();

    private:
        void Init();
        void UserInput(const std::string& command);
        void Render();
        void CleanUp();

        bool m_running;

        World                       m_world;
        std::unique_ptr<Renderer>   m_renderer;

        //Object* FindArgObj(const std::string& argument);
};

#endif // GAMEENGINE_H_INCLUDED
