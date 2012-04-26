//==============================================================================
#include "GameEngine.h"

using namespace std;
//==============================================================================
void GameEngine::UserInput()
{
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

Object* GameEngine::FindArgObj(const string argument)
{

    Object* tempObj = NULL;
    /*
    for(unsigned int i=0; i<theHero->Get_location()->Accessloot().size(); i++)
    {
        if(argument == theHero->Get_location()->Accessloot()[i]->Getname()) tempObj = theHero->Get_location()->Accessloot()[i];
    }
    for(unsigned int i=0; i<theHero->AccessInventory().size(); i++)
    {
        if(argument == theHero->AccessInventory()[i]->Getname()) tempObj = theHero->AccessInventory()[i];
    }
    */
    return tempObj;
}
