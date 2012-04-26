#ifndef DRAWABLE_H
#define DRAWABLE_H

class Renderer;

class Drawable
{
    public:
        virtual ~Drawable() {}

        virtual void Draw() const = 0;
    protected:
        explicit Drawable(Renderer& renderer) : m_renderer(renderer) {}
        Renderer&       m_renderer;
    private:
};

#endif // DRAWABLE_H
