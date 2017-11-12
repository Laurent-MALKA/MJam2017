#ifndef MJAM2017_BONUS_HPP
#define MJAM2017_BONUS_HPP


#include "Body.hpp"
#include "Perso.hpp"
#include "Image.hpp"

class Perso;

class Bonus : public Body {
public:
    explicit Bonus(Perso* monPerso, SDL_Texture* txt);
    virtual ~Bonus();
    virtual void effet() = 0;
    virtual void bouger()=0;
    virtual void mort(Perso* p);
    void display(SDL_Renderer *rdr);
    bool isUtilise() const;
    bool isRamasse() const;
    void setRamasse(bool ram);

protected:
    Perso* monPerso;
    bool utilise;
    SDL_Texture* txt;
    bool ramasse;
};


#endif //MJAM2017_BONUS_HPP
