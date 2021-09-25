//
// Created by Lenovo on 20/9/2021.
//

#include "Bloques.h"
#include "iostream"

using namespace std;



    void Bloques::fillgrid(){
        for(int i=0;i<6;i++){
            for(int j=0;j<13;j++){
                int probability=rand()%11+1+this->ajusteprofundos;//Número del 1-10 con ajuste si ya se tienen profundos

                if(j==this->profundos[0]||j==this->profundos[1]){//Bloque profundo, por lo que los de arriba deben ser internos
                    BloqueInterno newblock;
                    this->grid[i][j]=newblock;

                }else if (probability<=2){//Probabilidad Profundos 20%->10%->0%(ajustes)
                    BloqueProfundo newBlock;
                    this->cantprofundos+=1;
                    this->profundos[this->cantprofundos]=j;
                    this->ajusteprofundos+=1;
                    this->grid[i][j]=newBlock;

                }else if(probability<=4){//Probabilidad Triples 20%
                    BloqueTriple newBlock;
                    this->grid[i][j]=newBlock;

                }else if(probability<=7){//Probabilidad Dobles 30%
                    BloqueDoble newBlock;
                    this->grid[i][j]=newBlock;

                }else{//Probabilidad comúnes 30%->40%->50%
                    BloqueComun newBlock;
                    this->grid[i][j]=newBlock;
                }
            }
        }
    }

    int Bloques::getCantProf() {
        return 1+this->cantprofundos;
    }
