#ifndef RENDERER_H
#define RENDERER_H

class Drawable;

class Renderer
{
    public:
        Renderer() {}
        virtual ~Renderer() {}

        virtual void Draw(const Drawable& drawable) = 0;

        virtual void DrawText(const std::string& text) = 0;
        virtual void Display() = 0;
        virtual void Clear() = 0;

    protected:
    private:

};

#endif // RENDERER_H
