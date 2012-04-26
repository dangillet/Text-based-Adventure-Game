#ifndef RENDERER_H
#define RENDERER_H

class Room;

class Renderer
{
    public:
        Renderer() {}
        virtual ~Renderer() {}

        virtual void DrawRoom(const Room& room) = 0;

    protected:
    private:

};

#endif // RENDERER_H
