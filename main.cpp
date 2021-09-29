#include <iostream>
#include <string>
#include "Server/server.h"

using namespace std;
server * servidor;

void*serverRun(void *){
    try{
        servidor->run();
    }catch (string ex){
        cout<<ex<<endl;
    }
    pthread_exit(NULL);
}

int main() {
    servidor = new server;
    pthread_t  hiloS;
    pthread_create(&hiloS,0,serverRun,NULL);
    pthread_detach(hiloS);

    while(true){
        //USAR EL MESSAGE CREATOR
        string json="Hola desde el server \n";
        string msn;
        cin>>msn;
        if(msn=="salir"){
            break;
        }
        json.append(msn);
        servidor->setMsj(json.c_str());
    }
    delete servidor;
    return 0;
}
