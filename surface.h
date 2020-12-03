#ifndef SURFACE_H
#define SURFACE_H


class surface
{
    public:
        surface();
        virtual ~surface();
        virtual int getVitesse() const ;
        virtual bool getMorte() const ;
    private:
        int d_vitesse;
        bool d_estMorte;
};

#endif // SURFACE_H
