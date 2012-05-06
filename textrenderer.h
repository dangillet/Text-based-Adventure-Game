#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include <sstream>
#include "Renderer.h"

class TextRenderer : public Renderer
{
    public:
        TextRenderer();
        ~TextRenderer();

        void Draw(const Drawable& drawable);

        void DrawText(const std::string& text);

        void Display();
        void Clear();

    protected:
    private:
        std::stringstream       m_textOutput;
};

#endif // TEXTRENDERER_H
