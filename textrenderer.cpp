#include "drawable.h"
#include "textrenderer.h"
#include <iostream>

TextRenderer::TextRenderer() : m_textOutput()
{
    //ctor
}

TextRenderer::~TextRenderer()
{
    //dtor
}

void TextRenderer::Draw(const Drawable& drawable)
{
    drawable.Draw(*this);
}

void TextRenderer::DrawText(const std::string& text)
{
    m_textOutput << text;
}

void TextRenderer::Display()
{
    std::cout << m_textOutput.rdbuf();
    m_textOutput.str("");
}

void TextRenderer::Clear()
{

}
