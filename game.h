#include <stack>
using namespace std ;
class Game
{
    public:
    Game() ;
    ~Game();
    bool test(stack<Carte> ,Carte) ;
    stack<Carte> initialisation();
    bool endJeu(Pioche , Tableau , PileColeur);
    void afficher(Tableau , PileColeur , Pioche) ;
    void Help(Tableau , Pioche) ;
};