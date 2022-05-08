//
//  main.cpp
//  rozbudowany tictactoe
//
//  Created by Łukasz Michalak on 28/03/2019.
//  Copyright © 2019 Łukasz Michalak. All rights reserved.
//

#include <iostream>
#include "tictactoe.hpp"

using namespace std;

int main(void) {
    plansza gracz,przeciwnik;
    cout<<"Prosze wybrać gracza[ X lub O ] : ";
    char wybor;
    cin>>wybor;
    if(wybor!='X'&&wybor!='O'&&wybor!='x'&&wybor!='o'){
        cout<<"Blednie wybrany gracz!"<<endl;
        return 0;
    }
    else{
        if(wybor=='X'||wybor=='x'){
            gracz=iks;
            przeciwnik=kolo;
        }
        else{
            gracz=kolo;
            przeciwnik=iks;
        }
    }
    tictactoe tictactoe;
    tictactoe.wypisz_plansze();
    int stop=0;
    for(int i=0;i<9;i++){
                if(i==0||i==2||i==4||i==6||i==8){
            if(gracz==iks){
                tictactoe.ruch(gracz);
                stop=tictactoe.wygrana(gracz);
            }else{
                tictactoe.Ai_move(przeciwnik);
                stop=tictactoe.wygrana(przeciwnik);
            }
        }
        else{
            if(gracz==kolo){
                tictactoe.ruch(gracz);
                stop=tictactoe.wygrana(gracz);
            }
            else{
                tictactoe.Ai_move(przeciwnik);
                stop=tictactoe.wygrana(przeciwnik);
            }
        }
        system("clear");
        tictactoe.wypisz_plansze();
        if(stop==1){
            cout<<"Koniec gry!"<<endl;
            break;
        }
        else if(stop==2){
            cout<<"Remis!"<<endl;
            break;
        }
    }
    return 0;
}
