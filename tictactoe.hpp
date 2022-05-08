//
//  tictactoe.hpp
//  kółko
//
//  Created by Łukasz Michalak on 28/03/2019.
//  Copyright © 2019 Łukasz Michalak. All rights reserved.
//

#ifndef tictactoe_hpp
#define tictactoe_hpp

#include <stdio.h>
enum plansza{nic,iks,kolo};
struct Ai{
    Ai(){}
    Ai(int x): score(x){}
    int wiersz;
    int kolumna;
    int score;
};

class tictactoe{
public:
    tictactoe();
    void wypisz_plansze();
    void ruch(plansza gracz);
    int wygrana(plansza gracz);
    void Ai_move(plansza gracz);
private:
    plansza _gra[3][3];
    void _ruch(int wiersz, int kolumna,plansza gracz);
    Ai _Ai_move(plansza gracz);
};

#endif /* tictactoe_hpp */
