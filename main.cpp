#include <iostream>
#include <string>

using namespace std;

/**
 * Clase Bloque define las características principales que deben de tener los bloques
 * es la clase padre de todos los bloques
 */
class Bloque{
private:
    string Sorpresa;//Tipo de sorpresa
    int destroyed(){//Se destruyó el bloque
        tipo="Destruido";
        return this->puntos;
    }

public:
    int vida;
    int puntos;
    string tipo;
    string getSorpresa(){
        return this->Sorpresa;
    }

    void setSorpresa(string Sorpresa){
        this->Sorpresa=Sorpresa;
    }

    void virtual defineSorpresa(){
        int probability=rand()%4+1;//Genera un número del 1-4,
        if(probability==1){ //Probabilidad del 25%
            int probability2=rand()%4+1;
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

    int virtual hit(){
        this->vida-=1;
        if (this->vida==0){
            return destroyed();
        }else{
            return 0;
        }
    }
};

class BComun:public Bloque{
public:
    BComun(){
        this->vida=1;
        this->tipo="Comun";
        this->puntos=10;
        this->defineSorpresa();
    }
};

class BDoble:public Bloque{
public:
    BDoble(){
        this->vida=2;
        this->tipo="Doble";
        this->puntos=15;
        this->defineSorpresa();
    }
};

class BTriple:public Bloque{
public:
    BTriple(){
        this->vida=3;
        this->tipo="Triple";
        this->puntos=20;
        this->defineSorpresa();
    }
};

class BInterno:public Bloque{
public:
    BInterno(){
        this->vida=1;
        this->tipo="Interno";
        this->puntos=30;
        this->defineSorpresa();
    }
};

class BProfundo:public Bloque{
public:
    BProfundo(){
        this->vida=0;
        this->tipo="Profundo";
        this->puntos=0;
        defineSorpresa();
    }
    void defineSorpresa() override{
        setSorpresa("N");
    }
};

class Bloques{
private:
Bloque *grid[6];//
public:
    Bloque** getgrid(){
    return grid;
    }

    Bloque getBlock(int i,int j){
    return this->grid[i][j];
    }

    void fillgrid(){
        int ajusteprofundos=0;
        int profundos[2];
        int cantprofundos=-1;
        for(int i=0;i<6;i++){
            Bloque row[13];
            for(int j=0;j<13;j++){
                int probability=rand()%11+1+ajusteprofundos;
                if(j==profundos[0]||j==profundos[1]){
                    BInterno newblock;
                    row[j]=newblock;
                }else if (probability<=2){
                    BProfundo newBlock;
                    cantprofundos+=1;
                    profundos[cantprofundos]=j;
                    ajusteprofundos+=1;
                    row[j]=newBlock;
                    cout<<"Yes"<<endl;
                }else if(probability<=4){
                    BTriple newBlock;
                    row[j]=newBlock;
                }else if(probability<=7){
                    BDoble newBlock;
                    row[j]=newBlock;
                }else{
                    BComun newBlock;
                    row[j]=newBlock;
                }
            }
            this->grid[i]=row;
        }
    }
};

class server{
public:
    Bloques Grid;
    int Puntaje;
    int Bloques;
    int CantBolas;
    int Profundidad;

    server(){
        this->Puntaje=0;
        this->Bloques=78;
        this->CantBolas=1;
        this->Profundidad=0;
        this->Grid.fillgrid();
    }
};

int main() {
    cout<<"init"<<endl;
    server servidor;
    cout<<"fin"<<endl;

}
