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
        this->CantBloques-=this->Grid.getCantProf();
        this->Ballspeeds[0]=5;
    }


    void server::LostBall(int index){
        for(int j=index+1;j<this->CantBolas+1;j++){
            this->Ballspeeds[index]=this->Ballspeeds[j];
            index++;
        }
        this->CantBolas--;
    }

    void server::MessageReciever(string msg) {
    string hitfunc="BH";//Ball Hit function
    string Profact="Pr";//Activate /deactivate profundo
    string Gainfunc="GB";//Gained Ball Function
    string Lostfunc="LB";//Lost Ball Function
    if(msg[0]==hitfunc[0]&&msg[1]==hitfunc[1]){
        int i = atoi(&msg[3]);
        int j = atoi(&msg[5]);
        this->Ballhit(i,j);
    }else if(msg[0]==Profact[0]&&msg[1]==Profact[1]){
        string TrueFalse="T";
        if(msg[3]==TrueFalse[0]){
            this->ProfunActive(true);
        }else{
            this->ProfunActive(false);
        }
    }else if(msg[0]==Gainfunc[0]&&msg[1]==Gainfunc[1]){
        this->GainedBall();
    }else if(msg[0]==Lostfunc[0]&&msg[1]==Lostfunc[1]){
        int i=atoi(&msg[3]);
        this->LostBall(i);
    }
}

    void server::GainedBall(){
    this->Ballspeeds[this->CantBolas]=5;
    this->CantBolas++;
}

    void server::Managesurprise(string surprise) {
    if(surprise=="+V"){//Sorpresa más velocidad
        this->SpeedSurprise(true);
    }else if(surprise=="-V"){//Sorpresa menos velocidad
        this->SpeedSurprise(false);
    }else if(surprise=="+B"){//Sorpresa más barra
        this->LengthSurprise(true);
    }else{//Sorpresa menos barra
        this->LengthSurprise(false);
    }
}

    void server::ProfunActive(bool Activate) {
        this->modoprofundo=Activate;
    }

    void server::Ballhit(int i, int j) {
        Bloque Golpe= this->Grid.grid[i][j];
        if(Golpe.tipo==5){
            if(this->modoprofundo){
                this->Puntaje+=this->Grid.grid[i][j].hit();
                this->CantBloques--;
                if(Grid.grid[i][j].getSorpresa()!="N"){//El bloque contiene sorpresa
                    this->Managesurprise(Grid.grid[i][j].getSorpresa());
                }
            }else{
            }
        }//Bloque tipo interno

        else if(Golpe.tipo==4) {
            this->Profundidad++;
        }//Bloque tipo profundo

        else{
            int suma=this->Grid.grid[i][j].hit();
            this->Puntaje+=suma;
            if(suma!=0){//el bloque fue destruido
                if(Grid.grid[i][j].getSorpresa()!="N"){//El bloque contiene sorpresa
                    this->Managesurprise(Grid.grid[i][j].getSorpresa());
                    this->CantBloques--;
                    if (this->Profundidad!=0){//Profundidad no está en su valor mínimo
                        this->Profundidad--;
                    }
                }else{
                    this->CantBloques--;
                    if (this->Profundidad!=0){//Profundidad no está en su valor mínimo
                        this->Profundidad--;
                    }
                }
            }

        }//Otro tipo de bloque
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

string server::Martrparser() {
    string out="[";
    for(int i=0;i<6;i++){
        out.append("[");
        for(int j=0;j<13;j++){
            int type=this->Grid.grid[i][j].tipo;
            out.append(to_string(type));
            out.append(",");
        }
        if(i!=5) {
            out.append("],");
        }else{
            out.append("]")
        }
    }
    out.append("]");
    return out;
}

