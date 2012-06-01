//==============================================================================
#include "GameEngine.h"
#include "TextRenderer.h"
#include "character.h"
#include "renderer.h"
#include "object.h"
#include <unordered_set>
#include <iostream>
#include <sstream>
#include <array>

GameEngine::GameEngine() :
    m_running(true),
    m_world(),
    m_renderer(std::unique_ptr<Renderer>(new TextRenderer()))
{

}

GameEngine::~GameEngine() {}

void GameEngine::Run()
{
    Init();
    m_renderer->Draw(m_world);
    Render();
    while(m_running)
    {
        std::string command;
        std::getline(std::cin, command);
        UserInput(command);
        Render();
    }
    CleanUp();
}

void GameEngine::Init()
{
    m_world.LoadWorld("world.txt");
}

void GameEngine::UserInput(const std::string& command)
{
    if(command == "quit")
    {
        m_running = false;
        return;
    }

    std::stringstream ss(command);
    std::string token;
    ss >> token;

    if(token == "examine")
    {
        std::ws(ss);
        std::getline(ss, token);
        std::shared_ptr<Object> object = m_world.GetObjectByName(token);
        if(object)
        {
            m_renderer->DrawText(object->Examine() + "\n");
        }
        else
        {
            m_renderer->DrawText(token + " is nowhere to be found here.\n");
        }
        return;
    }
    if(token == "open")
    {
        std::ws(ss);
        std::getline(ss, token);
        auto currentRoom = m_world.GetPlayerRoom();
        auto object = currentRoom->GetObjectByName(token);
        if(object)
        {
            m_renderer->DrawText(object->Open() + "\n");
        }
        else
        {
            m_renderer->DrawText(token + " is nowhere to be found here.\n");
        }
        return;
    }
    if(token == "use")
    {
        std::array<std::string, 2> arguments;
        int i = 0;
        ss.unsetf(std::ios::skipws);
        std::ws(ss);
        std::getline(ss, token);
        auto position = token.find("with");
        if(position == std::string::npos)
        {
            m_renderer->DrawText("Command unknown.\n");
            return;
        }
        arguments[0] = token.substr(0, position - 1);
        arguments[1] = token.substr(position + 5);

        auto currentRoom = m_world.GetPlayerRoom();
        auto object1 = currentRoom->GetObjectByName(arguments[0]);
        if(!object1)
        {
            m_renderer->DrawText(arguments[0] + " is nowhere to be found.\n");
            return;
        }
        auto object2 = currentRoom->GetObjectByName(arguments[1]);
        if(!object2)
        {
            m_renderer->DrawText(arguments[1] + " is nowhere to be found.\n");
            return;
        }

        m_renderer->DrawText(object1->UseWith(object2));
        return;
    }
    if(token == "inventory")
    {
        //Show inventory
    }
    if(token == "go")
    {
        if(ss >> token && token == "to")
        {
            //Skip whitespaces
            std::ws(ss);
            std::getline(ss, token);
            auto player = m_world.GetPlayer();
            auto newRoom = player->GetLocation()->GetExitTo(token);
            if(newRoom)
            {
                player->SetLocation(newRoom);
                m_renderer->Draw(m_world);
            }
            else
            {
                m_renderer->DrawText(token + " is not a valid exit.\n");
            }

        return;
        }
    }
}

void GameEngine::Render()
{
    m_renderer->Display();
}

void GameEngine::CleanUp()
{

}


