//==============================================================================
#include "GameEngine.h"
#include "TextRenderer.h"
#include "character.h"
#include "renderer.h"
#include "object.h"
#include <unordered_set>
#include <iostream>
#include <sstream>

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
        auto currentRoom = m_world.GetPlayerRoom();
        std::shared_ptr<Object> object = currentRoom->GetObjectByName(token);
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
        std::shared_ptr<Object> object = currentRoom->GetObjectByName(token);
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
/*
    string line,command, argument;
    char ch;
    Clearmsg();

    do
    {
        cout << "Command : ";
        getline(cin, line);
    }while(line.empty());

    stringstream parser(line);
    parser >> command;

    Object* tempObj = NULL;
    if(command == "examine")
    {
        while( (ch=parser.peek()) == ' ' ) parser.get(ch);
        getline(parser, argument);

        if((tempObj = FindArgObj(argument)) == NULL) Setmsg(argument + " is not found here.");
        else Setmsg(tempObj->examine());
    }
    else if(command == "open")
    {
        while( (ch=parser.peek()) == ' ' ) parser.get(ch);
        getline(parser, argument);

        if((tempObj = FindArgObj(argument)) == NULL) Setmsg(argument + " is not found here.");
        else Setmsg(tempObj->open());
    }
    else if(command == "use") {}
    else if(command == "go")
    {
        parser >> command;
        if(command == "to")
        {
            while( (ch=parser.peek()) == ' ' ) parser.get(ch);
            getline(parser, argument);
            for(unsigned int i=0; i<theHero->Get_location()->GetExits().size(); i++)
            {

                if(argument == world[(theHero->Get_location()->GetExits()[i])]->Getname() )
                {
                    theHero->Set_location(world[(theHero->Get_location()->GetExits()[i])]);
                }
            }
        }
    }
    else Setmsg("Command not understood. Please try again.");


*/

}

//==============================================================================
/*
Object* GameEngine::FindArgObj(const std::string& argument)
{

    Object* tempObj = NULL;

    for(unsigned int i=0; i<theHero->Get_location()->Accessloot().size(); i++)
    {
        if(argument == theHero->Get_location()->Accessloot()[i]->Getname()) tempObj = theHero->Get_location()->Accessloot()[i];
    }
    for(unsigned int i=0; i<theHero->AccessInventory().size(); i++)
    {
        if(argument == theHero->AccessInventory()[i]->Getname()) tempObj = theHero->AccessInventory()[i];
    }

    return tempObj;
}
*/
void GameEngine::Render()
{
    m_renderer->Display();
}

void GameEngine::CleanUp()
{

}


