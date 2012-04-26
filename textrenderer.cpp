#include "textrenderer.h"
#include "room.h"

TextRenderer::TextRenderer()
{
    //ctor
}

TextRenderer::~TextRenderer()
{
    //dtor
}

void TextRenderer::DrawRoom(const Room& room)
{
    std::cout << "-----------------------------------------------------------------" << "\n";
    std::cout << room.GetName() << "\n";
    std::cout << "-----------------------------------------------------------------" << "\n\n";
    std::cout << room.GetDescription() << "\n\n";
}


