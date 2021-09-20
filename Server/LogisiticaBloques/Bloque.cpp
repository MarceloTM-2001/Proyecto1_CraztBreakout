//
// Created by Lenovo on 20/9/2021.
//

#include "Bloque.h"
#include "string"

using namespace std;

    int Bloque::destroyed(){ //Se destruyó el bloque
        tipo="Destruido";
        return this->puntos;
    }
    string Bloque::getSorpresa(){
        return this->Sorpresa;
    }

    void Bloque::setSorpresa(string Sorpresa){
        this->Sorpresa=Sorpresa;
    }


    void Bloque:: defineSorpresa(){
        int probability=rand()%4+1;//Genera un número del 1-4,
        if(probability==1){ //Probabilidad del 25%
            int probability2=rand()%4+1;//Genera un número de 1-4
            if (probability2==1){
                this->Sorpresa="+V";//Aumentar velocidad de la bola
            }else if (probability2==2){
                this->Sorpresa="-V";//Disminuir velocidad de la bola
            }else if (probability2==3){
                this->Sorpresa="+B";//Aumentar tamaño de la barra
            }else{
                this->Sorpresa="-B";//Disminuir tamaño de la barra
            }
        }else{
            this->Sorpresa="N";//No hay sorpresa
        }
    }

    int Bloque::hit(){
        this->vida--;
        if (this->vida==0){
            return destroyed();//Puntos a sumar
        }else{
            return 0;//Puntos a sumar
        }
    }
