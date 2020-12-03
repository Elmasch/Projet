#ifndef SURFACE_H
#define SURFACE_H


class surface
{
    public:
        surface();
        virtual ~surface();
        virtual double getVitesse() const =0;
        virtual bool getMorte() const =0;
        virtual int getCouleur() const = 0;
    private:
};

#endif // SURFACE_H
