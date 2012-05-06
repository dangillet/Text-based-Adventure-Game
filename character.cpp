#include "character.h"


Character::Character() :
    m_location(nullptr),
    m_inventory()
{

}

Character::~Character()
{
    std::cout << "Character destructor";
}

std::string Character::ShowInventory()
{
    std::string tempString = "";
    if(!m_inventory.empty())
    {
         for(unsigned int i=0; i<m_inventory.size(); i++)
            {
                tempString += m_inventory[i]->GetName();
                tempString += "\n";
            }
    }
    else tempString = "Your inventory is empty.";

    return tempString;
}

void Character::AddItemToInventory(ObjectPtr obj)
{
    m_inventory.push_back(std::move(obj));
}
