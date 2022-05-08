//
//  tictactoe.cpp
//  kółko
//
//  Created by Łukasz Michalak on 28/03/2019.
//  Copyright © 2019 Łukasz Michalak. All rights reserved.
//

#include "tictactoe.hpp"
#include <iostream>
#include <vector>

using namespace std;


tictactoe::tictactoe() //konstruktor co robi całe puste
{
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            _gra[i][j]=nic;
        }
    }
}

void tictactoe::wypisz_plansze(){
    char liczby_na_znaki[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            switch (_gra[i][j]) {
                case nic:
                    liczby_na_znaki[i][j]=' ';
                    break;
                case iks:
                    liczby_na_znaki[i][j]='X';
                    break;
                case kolo:
                    liczby_na_znaki[i][j]='O';
                    break;
            }
        }
    }
    cout<<"     1   2   3"<<endl;
    cout<<"   -------------"<<endl;
    cout<<"1  | "<<liczby_na_znaki[0][0]<<" | "<<liczby_na_znaki[0][1]<<" | "<<liczby_na_znaki[0][2]<<" |"<<endl;
    cout<<"   -------------"<<endl;
    cout<<"2  | "<<liczby_na_znaki[1][0]<<" | "<<liczby_na_znaki[1][1]<<" | "<<liczby_na_znaki[1][2]<<" |"<<endl;
    cout<<"   -------------"<<endl;
    cout<<"3  | "<<liczby_na_znaki[2][0]<<" | "<<liczby_na_znaki[2][1]<<" | "<<liczby_na_znaki[2][2]<<" |"<<endl;
    cout<<"   -------------"<<endl;
    
}

void tictactoe::ruch(plansza gracz){
    int wiersz,kolumna;
    int petla=1,duza_petla=1;
    cout<<"Prosze podac wspolrzedne ruchu:"<<endl;
    do{//na to czy pole zajete
        do{//na to czy dobra wspolrzedna
            cout<<"Wiersz: ";
            cin>>wiersz;
            if(wiersz==1||wiersz==2||wiersz==3){//czy pole zajete
                petla=0;
            }
            else{
                cout<<"Zla wsporzedna! Należy wpisać 1, 2 lub 3!"<<endl;
            }
        }while(petla==1);
        wiersz-=1;
        
        petla=1;
        do{
            cout<<"Kolumna: ";
            cin>>kolumna;
            if(kolumna==1||kolumna==2||kolumna==3){//czy pole zajete
                petla=0;
            }
            else{
                cout<<"Zla wsporzedna! Należy wpisać 1, 2 lub 3!"<<endl;
            }
        }while(petla==1);
        kolumna-=1; //bo numeracja od 0
        
        if(_gra[wiersz][kolumna]==nic){
            _gra[wiersz][kolumna]=gracz;
            duza_petla=0;
        }
        else{
            cout<<"To pole jest juz zajte! Prosze wybrać inne!"<<endl;
        }
    }while(duza_petla==1);
}

void tictactoe::_ruch(int wiersz, int kolumna,plansza gracz){
    _gra[wiersz][kolumna]=gracz;
}


int tictactoe::wygrana(plansza gracz){
    char zwyciesca;
    if(_gra[0][0]!=nic&&_gra[0][1]!=nic&&_gra[0][2]!=nic&&_gra[1][0]!=nic&&_gra[1][1]!=nic&&_gra[1][2]!=nic&&_gra[2][0]!=nic&&_gra[2][1]!=nic&&_gra[2][2]!=nic){
        return 2;
    }
    if(gracz==iks){
        zwyciesca='X';
    }
    else{
        zwyciesca='O';
    }
    if((_gra[0][0]==gracz&&_gra[1][1]==gracz&&_gra[2][2]==gracz)||(_gra[2][0]==gracz&&_gra[1][1]==gracz&&_gra[0][2]==gracz)){
        return 1;
    }
    for(int i=0;i<3;i++){
        if((_gra[i][0]==gracz&&_gra[i][1]==gracz&&_gra[i][2]==gracz)||(_gra[0][i]==gracz&&_gra[1][i]==gracz&&_gra[2][i]==gracz)){
            return 1;
        }
    }
    return 0;
}

void tictactoe::Ai_move(plansza gracz){
    Ai bestMove=_Ai_move(gracz);
    _ruch(bestMove.wiersz, bestMove.kolumna, gracz);
}

Ai tictactoe::_Ai_move(plansza gracz){
    int winX=wygrana(iks),winO=wygrana(kolo);
    if(winX==1){
        return Ai(10);
    }
    else if(winO==1){
        return Ai(-10);
    }
    else if(winO==2&&winX==2){
        return Ai(0);
    }

    vector<Ai> ruchy;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(_gra[i][j]==nic){
                Ai move;
                move.wiersz=i;
                move.kolumna=j;
                _ruch(i, j, gracz);
                if(gracz==iks){
                    move.score=_Ai_move(kolo).score;
                }
                if(gracz==kolo){
                    move.score=_Ai_move(iks).score;
                }
                
                ruchy.push_back(move);
                _ruch(i, j, nic);

            }
        }
    }
    
    int bestMove=0;
    if(gracz==iks){
        int bestScore=-1000000000;
        for(int i=0;i<ruchy.size();i++){
            if(ruchy[i].score>bestScore){
                bestMove=i;
                bestScore=ruchy[i].score;
            }
        }
    }else{
        int bestScore=1000000000;
        for(int i=0;i<ruchy.size();i++){
            if(ruchy[i].score<bestScore){
                bestMove=i;
                bestScore=ruchy[i].score;
            }
        }
    }
    return ruchy[bestMove];
}
