#include <iostream>
#include "Pioche.h"
#include "PileColeur.h"
#include "Tableau.h"
#include "game.h"
#include<stack>
#include <cstdlib> 
#include <stdio.h>
#include <time.h>


Carte::Carte() {
};
Carte::Carte(Formes F, Valeurs V, Visibles Vi=C ) : Forme(F) ,Valeur(V) ,Visible(Vi) 
{}
Carte::Carte(const Carte& obj)
{ 
    Forme=obj.Forme;
    Valeur=obj.Valeur;
    Visible=obj.Visible ;
    //construteur de recopie
}
Carte::~Carte() {}
bool Carte::operator== ( const Carte& c) {

    return c.Valeur==Valeur && c.Forme==Forme ;
}
void Carte::operator= ( const Carte& c) {

    Valeur= c.Valeur;
    Forme= c.Forme ;
    Visible= c.Visible ;
}
Carte::Formes Carte::getForme() const {return Forme ;}
Carte::Valeurs Carte::getValeur() const {return Valeur ;}
void Carte::setVisible (Visibles Vis = V)  {Visible = Vis  ;}
bool Carte::estRouge() const 
{
    if (Forme == coeur || Forme == carreau )
    {
        return true ;
    }
    else
    {
        return false ;
    }
}
bool Carte::estVisible() const 
{
    if (Visible == V)
    {
        return true ;
    }
    else
    {
        return false ;
    }
}
void Carte::inverser()
{
    if (Visible == V)
    {
        Visible = C ;
    }
    else
    {
        Visible = V ;
    }
}
void Carte::afficherForme(){
  switch(Forme)
  {
    case coeur : 
    {
      cout<<"♡" ;
      break ;
    }
    case carreau : 
    {
      cout<<"♢" ;
      break ;
    }
    case trefle : 
    {
      cout<<"♧" ;
      break ;
    }
    case pique : 
    {
      cout<<"♤" ;
      break ;
    }
    
  }

}
void Carte::afficherValeur(){
  switch(Valeur)
  {
    case As:
    {
      cout<<"As" ;
      break ;
    }
    case deux :
    {
      cout<<"2" ;
      break ;
    }
    case trois:
    {
      cout<<"3" ;
      break ;
    }
    case quatre:
    {
      cout<<"4" ;
      break ;
    }
    case cinq:
    {
      cout<<"5" ;
      break ;
    }
    case six:
    {
      cout<<"6" ;
      break ;
    }
    case sept:
    {
      cout<<"7" ;
      break ;
    }
    case huit:
    {
      cout<<"8" ;
      break ;
    }
    case neuf:
    {
      cout<<"9" ;
      break ;
    }
    case dix:
    {
      cout<<"10" ;
      break ;
    }
    case Valet:
    {
      cout<<"Valet" ;
      break ;
    }
    case Dame:
    {
      cout<<"Dame" ;
      break ;
    }
    case Roi:
    {
      cout<<"Roi" ;
      break ;
    }
  }
}
void Carte::afficherCarte(){
    cout<<"( " ;
    Carte::afficherValeur() ;
    cout<<" , " ;
    Carte::afficherForme() ;
    cout<<"  ) "<<endl;
}
//******************************
Pioche::Pioche(stack<Carte> c)
{
    Carte p;
    while (c.size() != 0)
    {
        p = c.top() ;
        pioche.push(p) ;
        c.pop() ;
    }
}
Pioche::~Pioche() {} 
void Pioche::Melanger(Carte C)
{
    stack<Carte> pile ;
    while(pioche.size() != 0 )
    {
        pile.push(pioche.top()) ;
        pioche.pop() ;
    }
    C.setVisible(Carte::C) ;
    pile.push(C) ;
    while (pile.size() != 0)
    {
        pioche.push(pile.top()) ;
        pile.pop();
    }

}
void Pioche::Ajouter_Carte(Carte C){
  pioche.push(C) ;
}
void Pioche::sup_Carte() 
{
  pioche.pop() ;
}
stack<Carte> Pioche::getPioche(){
  return pioche ;
}

Carte Pioche::Retourner_Carte()
{
    Carte c ; 
    c = pioche.top() ;
    pioche.pop() ;
    c.setVisible(Carte::V) ;
    return c ;
}
//******************
PileColeur::PileColeur()
{ }
PileColeur::~PileColeur() {}
bool PileColeur::AccepterAs(Carte C, int k)
{
    if ( pilecoleur[k].size() == 0 )
    {
        if (C.getValeur()== Carte::As)
        {
            pilecoleur[k].push(C) ;
            return true ;
        }
        else
        {
            cout<<"il faut implémenter cette pile par un As"<<endl ;
        }
    }
    else
    {
        cout<<"Cette pile n'est pas vide pour qu'elle puisse accepter un As"<<endl;
    }
    return false ;
}
bool PileColeur::Unicite(Carte C,int k) 
{
    int q = C.getValeur()-1 ;
    Carte::Valeurs d ;
    d=(Carte::Valeurs)q ;
    if (pilecoleur[k].top().getValeur() == d  && pilecoleur[k].top().getForme() == C.getForme() )
    // kifeh ne5dhou il successeur fil énumération ?
    {
        pilecoleur[k].push(C) ;
        return true ;
    }
    else
    {
        cout<<"impossoble d'ajouter cette carte à cette position"<<endl ;
        return false ;
    }
}
void PileColeur::Supp_Carte(int k){
  pilecoleur[k].pop() ;
} 
stack<Carte> PileColeur::getPile(int k){
  return pilecoleur[k] ;
}
int PileColeur::sizePile(int k) {
    return pilecoleur[k].size() ;
}
void PileColeur::afficherPileColeur(int k){
    cout<<"la"<<k<<"eme Pile de couleur "<<endl ;
    if (pilecoleur[k].size() == 0)
    {
        cout<<"empty"<<endl ;
    }
    else
    {
        pilecoleur[k].top().afficherCarte();
    }
}
//****************************
//****************************
//****************************
Tableau::Tableau(stack<Carte> pile)
{
    for (int i=0 ; i<7 ; i++)
    {
        for (int j=0 ; j<=i ; j++)
        {
            Carte c ;
            c=pile.top() ;
            tableau[i].push(c) ;
            pile.pop();
        }
        tableau[i].top().inverser();
    }
}
Tableau::~Tableau(){}
int *Tableau::getPileVide()
{
    int *T ;
    T=new int[7] ;
    int j=0;
    for (int i= 0 ; i<7 ; i++)
    {
        if (tableau[i].size() == 0)
        {
            T[j] = i ;
            j++ ;
        }
    }
    return T ;
}
void Tableau::setinverser(int k) {
  tableau[k].top().setVisible(Carte::Visibles::V) ;
}
bool Tableau::AccepterRoi (stack<Carte> C,int k)
{
    if (tableau[k].size() == 0)
    {
        stack<Carte> C1 ;
        while(C.size() != 0)
        {
            C1.push(C.top());
            C.pop();
        }
        if (C1.top().getValeur() == Carte::Roi)
        {
            while (C1.size() !=0)
            {
                tableau[k].push(C1.top()) ;
                C1.pop() ;
            }
            return true ;
        }
        else 
        {
            cout<<"cette case ne peut accepter qu'un Roi"<<endl ;
            while (C1.size() !=0)
            {
                C.push(C1.top()) ;
                C1.pop() ;
            }
        }
    }
    else
    {
        cout<<"choisir une autre destination : Pile vide"<<endl;
    }
    return false ;
}
bool Tableau::AccepterRoi (Carte C,int k)
{
    if (tableau[k].size() == 0)
    {
        if (C.getValeur() == Carte::Roi)
        {
            tableau[k].push(C) ;
            return true ;
        }
        else 
        {
            cout<<"il faut implémenter cette pile par un Roi"<<endl ;
        }
    }
    else
    {
        cout<<"Cette pile n'est pas vide pour qu'elle puisse accepter un Roi"<<endl;
    }
    return false ;
}
void Tableau::popCarte(int k){
  tableau[k].pop() ;
}
bool Tableau::Alternance(stack<Carte> C, int k)
{
    stack<Carte> C1 ;
    while(C.size() != 0)
    {
        C1.push(C.top());
        C.pop();
    }
    int q = C1.top().getValeur()+1 ;
    Carte::Valeurs d ;
    d=(Carte::Valeurs)q ;
    if (tableau[k].top().getValeur() == d && tableau[k].top().estRouge() != C1.top().estRouge() )
    // kifeh ne5dhou il successeur fil énumération ?
    {
        while (C1.size() != 0)
        {
            tableau[k].push(C1.top()) ;
            C1.pop();
        }
        return true ;

    }
    else
    {
        cout<<"impossible d'ajouter cette pile a cette position"<<endl ; 
        while (C1.size() != 0)
        {
            C.push(C1.top()) ;
            C1.pop();
        }
        return false ;

    }
}
bool Tableau::Alternance(Carte C, int k)
{
    bool b=false ;
    int q = C.getValeur() +1 ;
    Carte::Valeurs d ;
    d=(Carte::Valeurs)q ;
    if (tableau[k].top().getValeur() == d && tableau[k].top().estRouge() != C.estRouge() )
    // kifeh ne5dhou il successeur fil énumération ?
    {
        tableau[k].push(C) ;
        Tableau::afficherTableau(k) ;
        b=true ;
    }
    else
    {
        cout<<"impossoble d'ajouter cette carte à cette position"<<endl ;
    }
    return b ;
}
void Tableau::setStack(int k)
{
  tableau[k].pop() ;
}
stack<Carte> Tableau::getColonne(int k) {
  return tableau[k] ;
}


bool Tableau::Rech_Sol(int k){
  stack<Carte> S,S1 ;
  bool b11=false ;
  S=Tableau::getColonne(k) ;
  while(S.empty() == false && b11 == false )
  {
		if (S.top().estVisible() == true )
		{
			S1.push(S.top());
			S.pop() ;
		}
		else
		{
			b11=true ;
		}
	}
	int w=0 ;
	bool b=false;

	while(w<7 && b == false && S1.empty()==false) 
	{
		if(w != k)
		{
			int q =S1.top().getValeur()+1 ;
			Carte::Valeurs d ;
			d=(Carte::Valeurs)q ;
			if(tableau[w].empty() && S1.top().getValeur() == Carte::Roi)
			{
				int f ;
				f=S1.size() ;
				cout<<"On peut faire un deplacement de"<<f<<"Carte de la colonne "<<k+1<<"vers la colonne "<<w+1<<endl ;
				b=true ;
			}
			else if (tableau[w].top().getValeur() == d && tableau[w].top().estRouge() != S1.top().estRouge())
			{
				int f ;
				f=S1.size() ;
				cout<<"On peut faire un deplacement de"<<f<<"Carte de la colonne "<<k+1<<"vers la colonne "<<w+1<<endl ;
				b=true ;
			}
		}
		w++ ;
  }
  return b ;
}
void Tableau::AjoutCarte(int k,Carte C){
	tableau[k].push(C) ;
}
void Tableau::afficherTableau(int k) {
    cout<<"la"<<k+1<<"eme pile :" <<endl;
    stack<Carte> S1 ;
      if(tableau[k].size() == 0)
      {
          cout<<"Empty"<<endl ;
      }
      else
      {
        stack<Carte> S ;
        S = tableau[k] ;
        int x=0 ;
          while((x < S.size() && (tableau[k].top().estVisible() == true ) ) )
          {
            x++ ;
            S1.push(tableau[k].top()) ;
            tableau[k].pop() ;
          }
          int i ;
          i= tableau[k].size() ;
          for (int j =0 ; j<i ; j++)
          {
              cout<<"( , )"<<endl ;
          } 

          while(S1.size() != 0)
          {
              S1.top().afficherCarte() ;
              tableau[k].push(S1.top()) ;
              S1.pop() ;
          }
      }
}
//********************************************
//********************************************
//********************************************
Game::Game(){}
Game::~Game(){}
bool Game::test(stack<Carte> S,Carte C)
{
    stack<Carte> S1;
    bool T=false ;
    while(S.size() != 0 && T == false )
    {
        if(S.top() == C)
        {
            T=true ;
        }
        else
        {
            S1.push(S.top()) ;
            S.pop() ;
        }

    }
    while(S1.size() != 0)
    {
        S.push(S1.top());
        S1.pop() ;

    }
    return T ;
}
stack<Carte> Game::initialisation(){
    int i=0 ;
    stack<Carte> S ;
    while (S.size() <52 ){
        int V1,V2;
        V1 = rand() % 4 ;
        V2 = rand() % 13 +1 ;
        Carte::Formes f ;
        Carte::Valeurs v;
        f=(Carte::Formes) V1 ;
        v=(Carte::Valeurs) V2 ;
        Carte C1(f,v,Carte::C) ;
        if(S.size()== 0)
        {
            S.push(C1) ;
            i++ ;
          
        }
        else if (test(S,C1) == false)
        {
          S.push(C1);
          i++ ;
        }
    }
    cout<<i <<" Cartes"<<endl ;
    return S ;
}
bool Game::endJeu(Pioche P, Tableau T, PileColeur PC){
  bool b = false ;
    if (PC.sizePile(0)==13 && PC.sizePile(1)==13 && PC.sizePile(2)==13 && PC.sizePile(3)==13 )
    {
        cout<<"***tu as gagné !! BRAVO ***" << endl;
        b= true ;
    } 
    else 
    {
      cout<<"***continuez à jouer!!!!***" << endl ;
    }
    return b ;
}
void Game::Help(Tableau T, Pioche P){
  bool t=false ;
  for(int i= 0 ;i<7 && t==false ; i++)
  {
    t=T.Rech_Sol(i) ;
  }
  if (t== false)
  {
    if (P.getPioche().empty() == false )
    {
      if (P.getPioche().top().estVisible())
      {
        Carte C ;
        C=P.getPioche().top() ;
        bool b1=false ;
        int x=0 ;
        while(x<7 && b1 == false)
        {
          if(T.getColonne(x).empty())
          {
            b1=T.AccepterRoi(C, x) ;
            if (b1 == true)
            {
              T.popCarte(x) ;
              cout<<"la carte visible de la pioche peux etre utiliser dans la colonne"<<x+1<<endl ;
            }

          }
          else
          {
            b1=T.Alternance(C, x) ;
            if (b1 == true)
            {
              T.popCarte(x) ;
              cout<<"la carte visible de la pioche peux etre utiliser dans la colonne"<<x<<endl ;
            }

          }
          x++;
        }
      }

    }
  }

}

void Game::afficher(Tableau T, PileColeur PC , Pioche P){


    for (int i=0 ; i<7 ; i++)
    {
        T.afficherTableau(i) ;
    }
    for (int i=0 ; i<4 ; i++)
    {
        PC.afficherPileColeur(i) ;
    }
    if (P.getPioche().top().estVisible())
    {
      cout<<"Il existe une Carte visible dans la Pioche qui est :"<<endl ;
      P.getPioche().top().afficherCarte() ;
    }
}


int main() {
	srand((int)time(0));
  std::cout << "Hello !\n";
  Game New_Game ;
  stack<Carte> S ;
  time_t start = time (NULL);
  S=New_Game.initialisation() ;
  stack<Carte> S1 ;
  while(S1.size()< 24 )
    {
      S1.push(S.top()) ;
      S.pop() ;
    }
  Pioche P(S1) ;
  Tableau T(S) ;
  PileColeur PC ;
  New_Game.afficher(T,PC,P) ;
  int z=0 ;
  while (New_Game.endJeu(P, T ,PC) == false && z!= 5 )
{ 
    cout<<"le temps passé est "<<(int) (time (NULL) - start)<<" secondes"<<endl;
    cout<<"Appuyer sur << 1 >> si tu veux piocher la pioche " <<endl ;
    cout<<"Appuyer Sur << 2 >> si tu veux faire un deplacement dans le tableau"<<endl ;
    cout<<"Appuyer sur << 3 >> si tu veux utiliser une carte de pile couleur"<<endl ;
    cout<<"Appuyer sur << 4 >> si tu veux utiliser la carte visible de la pioche"<<endl;
    cout<<"Appuyer sur << 5 >> si tu veux arreter le jeu"<<endl ;
    cout<<"Appuyer sur << 6 >> si tu veux une astuce"<<endl ;
    int rep ;
    cin>> rep ;
    switch(rep) 
{
  case 1:
  {
    if(P.getPioche().top().estVisible())
    {
      Carte C1 ;
      C1=P.Retourner_Carte() ;
      P.Melanger(C1) ;
    }
    Carte C ;
    C= P.Retourner_Carte() ;
    C.afficherCarte() ;
    P.Ajouter_Carte(C) ;
    cout<<"Appuyer sur << 1 >> si tu veux utiliser cette Carte dans le tableau"<<endl;
    cout<<"Appuyer sur << 2 >> si tu veux utiliser cette Carte dans la PileCouleur" <<endl;
    cout<<"Appuyer sur << 3 >> si tu ne veux pas utiliser cette carte" <<endl ;
    int rep1 ;
    cin>> rep1 ;
    switch(rep1) {
                    case 1:
                    {
                      bool t1=false ;
                      bool t2=false ;
                      cout<<"entrer le numéro de colonne du tableau "<<endl ;
                      int rep11 ;
                      cin>> rep11 ;
                      if(T.getColonne(rep11-1).empty())
                      {
                        t1=T.AccepterRoi(P.getPioche().top(), rep11-1) ;
                        if(t1 == true)
                        {
                          P.sup_Carte() ;
                        }
                      }
                      else if (t1 == false)
                      {
                        t2=T.Alternance(P.getPioche().top(), rep11-1) ;

                        if (t2 == true)
                        {
                          P.sup_Carte();
                        }
                      }
                      else if (t1== false && t2 == false){}
                      break;
                    }
                    case 2:
                      {
                      bool t1=false ;
                      bool t2=false ;
                      cout<<"entrer le numéro de pile de la pilecouleur "<<endl ;
                      int rep11 ;
                      cin>> rep11 ;
                      if(PC.getPile(rep11).empty())
                      {
                        t1=PC.AccepterAs(P.getPioche().top(), rep11) ;
                        if(t1 == true)
                        {
                           P.sup_Carte();
                        }
                      }
                      else if (t1 == false)
                      {
                        t2=PC.Unicite(P.getPioche().top(), rep11) ;
                        if (t2 == true)
                        {
                           P.sup_Carte();
                        }
                      }
                      else if (t1== false && t2 == false){}
                      break;
                    }
                    case 3 :
                  {
                    break ;
                  }
                  }
  break ;
  }
  case 2:
  {
    bool t3=false ;
    bool t4=false ;
    cout<<"selectionner une pile" <<endl ;
    int nump ;
    cin>> nump ;
    cout<<"Appuyer sur << 1 >> si tu veux faire un deplacement vers une autre colonne"<<endl ;
    cout<<"Appuyer sur << 2 >> si tu veux faire un deplacement vers une pilecouleur"<<endl ;
    int rep21 ;
    cin>> rep21 ;
    switch(rep21) {
      case 1 : {
    
                  cout<<"Combien de carte voulez vous prendre de cette pile"<<endl ;
                  int nbrC ;
                  cin>>nbrC ;
                  cout<<"choisir une autre colonne destination"<<endl ;
                  int numdest ;
                  cin>> numdest ;
                  stack<Carte> S2,S3,S4 ;
                  S4=T.getColonne(nump-1) ;
                  while(S2.size()<nbrC && S4.empty()==false)
                  {
                    S2.push(S4.top()) ;
                    S4.pop() ;
                  }
                  while(S3.size()<nbrC && S2.empty()==false)
                  {
                    S3.push(S2.top()) ;
                    S2.pop() ;
                  }
                  if (T.getColonne(numdest-1).empty())
                  {
                    t3=T.AccepterRoi(S3, numdest-1) ;
                    if (t3==true )
                    {
                      for(int j=0 ; j<nbrC  ; j++)
                      {
                        T.popCarte(nump-1) ;
                      }
                      if (T.getColonne(nump-1).empty()==false)
											{
                      	T.setinverser(nump-1)  ;
											}     
                    }
                  }
                  else
                  {
                    t4=T.Alternance(S3, numdest-1) ;
                    if (t4==true )
                    {
                      for(int j=0 ; j<nbrC && T.getColonne(nump-1).empty()== false ; j++)
                      {
                        T.popCarte(nump-1) ;
                      }
											if (T.getColonne(nump-1).empty()==false)
											{
                      	T.setinverser(nump-1)  ;
											}    
                    }
                  }
                  New_Game.afficher(T, PC, P) ;


                  break;
      } 
      case 2 : {
               cout<<"choisir une pile couleur comme destination "<<endl;
               int rep22 ;
               cin>> rep22 ;
               Carte CP ;
               bool t1=false ;
               CP = T.getColonne(nump-1).top() ;
               if ( PC.getPile(rep22).empty())
              {

                     t1=PC.AccepterAs(CP,rep22) ;
                     if (t1) 
                      {
                       T.popCarte(nump-1) ;

                      }
              }
               else  
               {
                        t1=PC.Unicite(CP, rep22);
                        if (t1) 
                        {

                          T.popCarte(nump-1) ;
                       }

               }
               New_Game.afficher( T,  PC,P) ;
               break ;


               
               
      }
    } 
    break ;
  }
  case 3: {
                  cout<<"chosir la pile couleur qu'on veut la depiler par une carte " <<endl ;
                  int nump12 ; 
                  cin>> nump12 ;
                  cout<<"chosir une colonne de tableau comme destination"<<endl ;
                  int numc12 ;
                  cin>> numc12;
                  Carte CP1 ;
                  bool t2=false ;
                  CP1= PC.getPile( nump12).top();
                  if (T.getColonne(numc12-1).empty()) 
                  {
                    t2=T.AccepterRoi(CP1, numc12-1) ;
                    if(t2)
                    {
                      PC.Supp_Carte(nump12-1);

                    }
                  }
                  else 
                  {
                    t2=T.Alternance(CP1, numc12-1) ;
                    if (t2)
                    {
                      PC.Supp_Carte(nump12-1) ;
                    }
                    
                  }
                  break ;
                
           }
  case 4 :
  { 
    cout<<"Appuyer sur << 1 >> si tu veux utiliser cette Carte dans le tableau"<<endl;
    cout<<"Appuyer sur << 2 >> si tu veux utiliser cette Carte dans la PileCouleur" <<endl;
    int rep4 ;
    cin>> rep4 ;
    switch(rep4) 
    {
      case 1 :
      {
                      bool t1=false ;
                      bool t2=false ;
                      cout<<"entrer le numéro de colonne du tableau "<<endl ;
                      int rep11 ;
                      cin>> rep11 ;
                      if(T.getColonne(rep11-1).empty())
                      {
                        t1=T.AccepterRoi(P.getPioche().top(), rep11-1) ;
                        if(t1 == true)
                        {
                          P.sup_Carte() ;
                        }
                      }
                      else if (t1 == false)
                      {
                        t2=T.Alternance(P.getPioche().top(), rep11-1) ;

                        if (t2 == true)
                        {
                          P.sup_Carte();
                        }
                      }
                      else if (t1== false && t2 == false){}

        break ;
      }
      case 2:
                      {
                      bool t1=false ;
                      bool t2=false ;
                      cout<<"entrer le numéro de pile de la pilecouleur "<<endl ;
                      int rep11 ;
                      cin>> rep11 ;
                      if(PC.getPile(rep11).empty())
                      {
                        t1=PC.AccepterAs(P.getPioche().top(), rep11) ;
                        if(t1 == true)
                        {
                           P.sup_Carte();
                        }
                      }
                      else if (t1 == false)
                      {
                        t2=PC.Unicite(P.getPioche().top(), rep11) ;
                        if (t2 == true)
                        {
                          P.sup_Carte();
                        }
                      }
                      else if (t1== false && t2 == false){}
                      break;
                    }

    }
    break ;
  }
  case 5 :
  {
    z=5 ;
    break ;
  }
  case 6 :
  {
    New_Game.Help(T, P) ;
    break ;
  }
  
}

  
}



/*Carte Y4(Carte::trefle,Carte::deux,Carte::V) ;
Carte Y5(Carte::coeur,Carte::As,Carte::V) ;
stack<Carte> Z ;
Z.push(Y4) ;
Z.push(Y5) ;
T.Alternance(Z, 0) ;
T.afficherTableau(0) ;*/








/*Carte Y(Carte::coeur,Carte::neuf,Carte::V) ;
T.Alternance(Y, 6) ;
T.afficherTableau(6)  ;
for(int e=0 ; e<8 ; e++)
{
  T.popCarte(6) ;
}
T.afficherTableau(6) ;
Carte Y1(Carte::coeur,Carte::Roi,Carte::V) ;
T.AccepterRoi(Y1, 6) ;
Carte Y2(Carte::trefle,Carte::Dame,Carte::V) ;
Carte Y3(Carte::coeur,Carte::Valet,Carte::V) ;
T.Alternance(Y2, 6) ;
T.Alternance(Y3, 6) ;
Carte Y4(Carte::trefle,Carte::dix,Carte::V) ;
Carte Y5(Carte::coeur,Carte::neuf,Carte::V) ;
stack<Carte> Z ;
Z.push(Y4) ;
Z.push(Y5) ;
T.Alternance(Z, 6) ;
T.afficherTableau(6) ; */












/*  stack<Carte> S ;
    while (S.size() <28 ){
        int V1,V2;
        V1 = rand() % 4 ;
        V2 = rand() % 13 +1 ;
        Carte::Formes f ;
        Carte::Valeurs v;
        f=(Carte::Formes) V1 ;
        v=(Carte::Valeurs) V2 ;
        Carte C1(f,v,Carte::C) ;
        S.push(C1) ;
    }
  Tableau T(S) ;
  for(int i=0 ; i<7 ; i++)
  {
  T.afficherTableau(i) ;
  }
  Carte C(Carte::coeur,Carte::dix,Carte::V) ;
  Carte C1(Carte::coeur,Carte::Roi,Carte::V) ;
  T.AccepterRoi(C, 3) ;
  T.setStack(0) ;
  T.AccepterRoi(C1, 0) ;
  T.afficherTableau(0) ;
  Carte C2(Carte::trefle,Carte::Dame,Carte::V) ;
  T.Alternance(C2, 0) ;
  T.Alternance(C1, 0) ;
  T.afficherTableau(0) ;
  Carte C3(Carte::carreau,Carte::Valet,Carte::V) ;
  T.Alternance(C3, 0) ;
  T.afficherTableau(0) ;
  Carte C4(Carte::carreau,Carte::neuf,Carte::V) ;
  T.Alternance(C3, 6) ;
  T.afficherTableau(6) ;
  T.Alternance(C3, 6) ;
  T.Alternance(C4, 6) ;
  T.afficherTableau(6) ;
  stack<Carte> m ;
  Carte C5(Carte::trefle,Carte::huit,Carte::V) ;
  Carte C6(Carte::carreau,Carte::sept,Carte::V) ;
  Carte C7(Carte::trefle,Carte::six,Carte::V) ;
  m.push(C5) ;
  m.push(C6) ;
  m.push(C7) ;
  T.Alternance(m, 6) ;
  T.afficherTableau(6) ; */
  return 0 ;
}
