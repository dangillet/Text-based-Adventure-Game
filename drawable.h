#ifndef DRAWABLE_H
#define DRAWABLE_H

class Renderer;

class Drawable
{
    public:
        virtual ~Drawable() {}

        virtual void Draw(Renderer& renderer) const = 0;
    protected:
        Drawable() {}
    private:
};

#endif // DRAWABLE_H
