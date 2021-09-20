#include <iostream>
#include <string>

using namespace std;

/**
 * Clase Bloque define las características principales que deben de tener los bloques
 * es la clase padre de todos los bloques
 */
class Bloque{
private:
    string Sorpresa; //Tipo de sorpresa
    int destroyed(){ //Se destruyó el bloque
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

    /**
     * Define si el bloque contiene o no sorpresa
     * La probabilidad de tener sorpresa es del 25%
     * La probabilidad de una sorpresa 25%
     * La probabilidad de todas las sorpresas es la misma 25%,
     * Por ende la probabilidad de que ub bloque contenga una sorpresa en específico es de 6.25%
     */
    void virtual defineSorpresa(){
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

    /**
     * Un bloque recibió un golpe de una bola
     *
     * @return La cantidad de puntos que se deben sumar por el golpe
     * No se suman si el bloque no se destruyó
     */
    int virtual hit(){
        this->vida--;
        if (this->vida==0){
            return destroyed();//Puntos a sumar
        }else{
            return 0;//Puntos a sumar
        }
    }

};

/**
 * Bloque Común
 * Da 10 puntos
 * 1 Vida
 */
class BComun:public Bloque{
public:
    BComun(){
        this->vida=1;
        this->tipo="Comun";
        this->puntos=10;
        this->defineSorpresa();
    }
};

/**
 * Bloque Doble
 * 15 Puntos
 * 2 vidas
 */
class BDoble:public Bloque{
public:
    BDoble(){
        this->vida=2;
        this->tipo="Doble";
        this->puntos=15;
        this->defineSorpresa();
    }
};

/**
 * Bloque Triple
 * 20 Puntos
 * 3 vidas
 */
class BTriple:public Bloque{
public:
    BTriple(){
        this->vida=3;
        this->tipo="Triple";
        this->puntos=20;
        this->defineSorpresa();
    }
};

/**
 * Bloques internos
 * 30 Puntos
 * 1 Vida(Infinita si es no está en modo profundo)
 */
class BInterno:public Bloque{
public:
    BInterno(){
        this->vida=1;
        this->tipo="Interno";
        this->puntos=30;
        this->defineSorpresa();
    }
};


/**
 * Bloque Profundo
 * 0 puntos
 * Vida infinita
 */
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

/**
 * Matriz que contiene un grid de los bloques
 * Contiene operaciones necesarias para el tablero
 */
class Bloques{

private:
Bloque *grid[6];//

public:

    Bloque** getgrid(){
    return grid;
    }

    /**
     * Devuelve un bloque en específico de la matriz
     * @param i (Posición fila)
     * @param j (Posición columna)
     * @return Bloque de la posición indicada
     */
    Bloque getBlock(int i,int j){
    return this->grid[i][j];
    }

    /**
     * Llena el grid de bloques
     * La probabilidad se ajusta de manera que solo puedan haber dos sets de bloques profundos por juego
     * Probabilidades:
     * Común=30%->40%->50% (después del ajuste de profundos)
     * Doble=30%
     * Triple=20%
     * Profundo=20%->10%->0% (después del ajuste de profundos)
     */
    void fillgrid(){
        int ajusteprofundos=0;
        int profundos[2];
        int cantprofundos=-1;
        for(int i=0;i<6;i++){
            Bloque row[13];
            for(int j=0;j<13;j++){
                int probability=rand()%11+1+ajusteprofundos;//Número del 1-10 con ajuste si ya se tienen profundos

                if(j==profundos[0]||j==profundos[1]){//Bloque profundo, por lo que los de arriba deben ser internos
                    BInterno newblock;
                    row[j]=newblock;
                }else if (probability<=2){//Probabilidad Profundos 20%->10%->0%(ajustes)
                    BProfundo newBlock;
                    cantprofundos+=1;
                    profundos[cantprofundos]=j;
                    ajusteprofundos+=1;
                    row[j]=newBlock;
                }else if(probability<=4){//Probabilidad Triples 20%
                    BTriple newBlock;
                    row[j]=newBlock;
                }else if(probability<=7){//Probabilidad Dobles 30%
                    BDoble newBlock;
                    row[j]=newBlock;
                }else{//Probabilidad comúnes 30%->40%->50%
                    BComun newBlock;
                    row[j]=newBlock;
                }
            }
            this->grid[i]=row;
        }
    }
};


/**
 * Contiene toda la información relacionada al juego y la mantiene actualizadda en
 * base a los cambios ocurridos en la GUI.
 */
class server{
public:
    Bloques Grid;
    int Ballspeeds[100];
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
        this->Ballspeeds[0]=5;
    }
    /**
     * se perdió una bola
     * @param index (bola que se perdió)
     */
    void LostBall(int index){
        for(int j=index+1;j<this->CantBolas+1;j++){
            this->Ballspeeds[index]=this->Ballspeeds[j];
            index++;
        }
        this->CantBolas--;
    }
    /**
     * Cuando se gana la una bola
     */
    void GainedBall(){
        this->Ballspeeds[this->CantBolas]=5;
        this->CantBolas++;
    }

    /**
     * Se activa cuando el bloque roto contiene una sorpresa
     * @param Buff (es aumento o disminución de velocidad
     */
    void SpeedSurprise(bool Buff){
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
};

int main() {
    cout<<"init"<<endl;
    server servidor;
    cout<<"fin"<<endl;

}
