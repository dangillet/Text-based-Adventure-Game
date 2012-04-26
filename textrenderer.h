#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include "Renderer.h"


class TextRenderer : public Renderer
{
    public:
        TextRenderer();
        ~TextRenderer();

        void DrawRoom(const Room& room);

    protected:
    private:
};

#endif // TEXTRENDERER_H
