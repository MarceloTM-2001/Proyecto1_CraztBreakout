//
// Created by Lenovo on 20/9/2021.
//

#include "server.h"

    server::server(){
        this->Puntaje=0;
        this->Length=5;
        this->CantBloques=78;
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
    void server::ProfunActive(bool Activate) {
        this->modoprofundo=Activate;
    }

    void server::Ballhit(int i, int j) {
        Bloque Golpe=this->Grid.getBlock(i,j);
        if(Golpe.tipo==5){
            if(this->modoprofundo){
                this->Puntaje+=this->Grid.getBlock(i,j).hit();
            }else{
            }
        }else if(Golpe.tipo==4){
            this->Profundidad++;
        }else{
            this->Puntaje+=this->Grid.getBlock(i,j).hit();
            this->Profundidad--;

        }
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

    void server::LengthSurprise(bool Buff){
    if (Buff){//Aumento de length
        if(this->Length!=10){
            this->Length++;
        }else{//Length máximo 10
        }
    }else{//Disminución
        if(this->Length!=1){
            this->Length--;
        }else{//Disminución mínima 1
        }
    }
}

