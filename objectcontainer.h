#ifndef OBJECTCONTAINER_H
#define OBJECTCONTAINER_H

#include <vector>
#include <memory>
#include <string>

class Object;
typedef std::shared_ptr<Object> ObjectPtr;

class ObjectContainer
{
    public:
        explicit ObjectContainer();
        virtual ~ObjectContainer();

        void AddObject(ObjectPtr object);
        void RemoveObject(ObjectPtr object);
        ObjectPtr GetObjectByName(const std::string& name);

        std::string Inventory() const;
    protected:
        std::vector<ObjectPtr>    m_container;
    private:
};

#endif // OBJECTCONTAINER_H
