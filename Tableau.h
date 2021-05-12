#include <iostream> 
#include <stack>
using namespace std;
class Tableau
{
    public : 
    Tableau(stack<Carte>);
    ~Tableau();
    int *getPileVide();
    bool AccepterRoi(stack<Carte> ,int);
    bool AccepterRoi(Carte, int) ;
    bool Alternance(stack<Carte>,int);
    bool Alternance(Carte, int ) ;
    void setStack(int) ;
    void afficherTableau(int) ;
    stack<Carte> getColonne(int) ;
    void popCarte(int) ;
    void setinverser(int) ;
    bool Rech_Sol(int) ;
		void AjoutCarte(int,Carte ) ;
    private :
    stack<Carte> tableau[7];
};