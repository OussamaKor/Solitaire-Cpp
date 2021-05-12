#include <iostream>
#include <stack>
#include "Carte.h"
using namespace std ;
class Pioche 
{
    public:
    Pioche(stack<Carte>);
    void Melanger(Carte C);
    Carte Retourner_Carte();
    stack<Carte> getPioche() ;
    ~Pioche();  
    void Ajouter_Carte(Carte ) ;
    void sup_Carte() ;

    private:
    stack<Carte> pioche ; 
};