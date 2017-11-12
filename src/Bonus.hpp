#ifndef MJAM2017_BONUS_HPP
#define MJAM2017_BONUS_HPP


#include "Body.hpp"
#include "Perso.hpp"

class Perso;

class Bonus : public Body {
public:
    explicit Bonus(Perso* monPerso);
    virtual ~Bonus();
    virtual void effet() = 0;
    virtual void bouger()=0;
    virtual void mort(Perso* p);
    void display(SDL_Renderer *rdr);
    bool getUtilise() const;

protected:
    Perso* monPerso;
    bool utilise;
};


#endif //MJAM2017_BONUS_HPP
