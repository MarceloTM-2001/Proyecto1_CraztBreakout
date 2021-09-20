//
// Created by Lenovo on 20/9/2021.
//

#include "server.h"

    server::server(){
        this->Puntaje=0;
        this->Bloques=78;
        this->CantBolas=1;
        this->Profundidad=0;
        this->Grid.fillgrid();
        this->Ballspeeds[0]=5;
    }

    void server::LostBall(int index){
        for(int j=index+1;j<this->CantBolas+1;j++){
            this->Ballspeeds[index]=this->Ballspeeds[j];
            index++;
        }
        this->CantBolas--;
    }

    void server::GainedBall(){
        this->Ballspeeds[this->CantBolas]=5;
        this->CantBolas++;
    }


    void server::SpeedSurprise(bool Buff){
        if (Buff){//Aumento de velocidad
            for(int i=0;i<this->CantBolas;i++){
                if(this->Ballspeeds[i]!=10){
                    this->Ballspeeds[i]++;
                }else{//Velocidad máxima 10
                    continue;
                }
            }
        }else{//Disminución
            for(int i=0;i<this->CantBolas;i++){
                if(this->Ballspeeds[i]!=1){
                    this->Ballspeeds[i]--;
                }else{//Disminución mínima 1
                    continue;
                }
            }
        }
    }

