#include <iostream> 
#include <stack>
using namespace std;
class PileColeur
{
    public : 
    PileColeur() ;
    ~PileColeur() ;
    bool AccepterAs(Carte,int) ;
    bool Unicite(Carte,int) ;
    stack<Carte> getPile(int) ;
    void Supp_Carte(int) ;
    int sizePile(int) ;
    void afficherPileColeur(int);
    private :
    stack<Carte> pilecoleur[4] ;
};