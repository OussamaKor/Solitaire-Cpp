#include <iostream>
using namespace std ;
class Carte 
{
    public:
    enum Formes {coeur = 0, pique = 1, carreau = 2, trefle = 3 };
    enum Valeurs {As = 1 ,deux = 2 ,trois = 3 ,quatre = 4 ,cinq = 5 ,six = 6 ,sept = 7 ,huit = 8 ,neuf = 9 ,dix = 10 ,Valet = 11 ,Dame = 12 ,Roi = 13};
    enum Visibles {V,C};
    Carte();
    Carte(Formes , Valeurs , Visibles ) ;
    Carte(const Carte&) ;
    ~Carte();
    Formes getForme () const;
    Valeurs getValeur () const;
    void setVisible (Visibles) ;
    bool estRouge () const;
    bool estVisible () const;
    void inverser () ;
    bool operator==(const Carte &c) ;
    void operator= (const Carte &c) ;
    void afficherCarte() ;
    void afficherForme();
    void afficherValeur();
    private:
    Formes Forme ;
    Valeurs Valeur ;
    Visibles Visible ;
};