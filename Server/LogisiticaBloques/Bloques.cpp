//
// Created by Lenovo on 20/9/2021.
//

#include "Bloques.h"




    Bloque** Bloques:: getgrid(){
        return this->grid;
    }

    Bloque Bloques::getBlock(int i,int j){
        return this->grid[i][j];
    }

    void Bloques::fillgrid(){
        int ajusteprofundos=0;
        int profundos[2];
        int cantprofundos=-1;
        for(int i=0;i<6;i++){
            Bloque row[13];
            for(int j=0;j<13;j++){
                int probability=rand()%11+1+ajusteprofundos;//Número del 1-10 con ajuste si ya se tienen profundos

                if(j==profundos[0]||j==profundos[1]){//Bloque profundo, por lo que los de arriba deben ser internos
                    BloqueInterno newblock;
                    row[j]=newblock;
                }else if (probability<=2){//Probabilidad Profundos 20%->10%->0%(ajustes)
                    BloqueProfundo newBlock;
                    cantprofundos+=1;
                    profundos[cantprofundos]=j;
                    ajusteprofundos+=1;
                    row[j]=newBlock;
                }else if(probability<=4){//Probabilidad Triples 20%
                    BloqueTriple newBlock;
                    row[j]=newBlock;
                }else if(probability<=7){//Probabilidad Dobles 30%
                    BloqueDoble newBlock;
                    row[j]=newBlock;
                }else{//Probabilidad comúnes 30%->40%->50%
                    BloqueComun newBlock;
                    row[j]=newBlock;
                }
            }
            this->grid[i]=row;
        }
    }
