/*
 *   	EJEMPLO BASE DE GATO, TIC TAC TOE, O TRES EN RALLA EN C++
 * 		DESARROLADO COMO EJEMPLO PARA: Freelance Hackers
 * 		https://www.facebook.com/groups/659443867402816/
 *
 * 		Desarrollador: Juan Valadez
 * 		www.mrcodigo.blogspot.com
 * */
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define VERDAD 1
#define FALSO  0

#define NADA    0
#define TACHA   1
#define CIRCULO 2

struct gato {
    int campo[3][3];
    void genera();
    void pinta();
    void control_t();
    void control_cpu();
    bool juego_terminado();
};

void gato::genera() {
    for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
            // LIMPIA CAMPO
            campo[x][y]=NADA;
        }
    }
}

void gato::pinta() {
    // LIMPIA PANTALLA
    system("clear");
    cout<<endl;

    // PINTA CAMPO GATO
    for (int y=0; y<3; y++) {
        cout<<" ";
        for (int x=0; x<3; x++) {
            if (campo[x][y]==NADA)    cout <<" ";
            if (campo[x][y]==TACHA)   cout <<"X";
            if (campo[x][y]==CIRCULO) cout <<"O";
            if (x<2) cout<<"|";
        }
        if (y==0) cout<<"          1|2|3";
        if (y==1) cout<<"          4|5|6";
        if (y==2) cout<<"          7|8|9";
        if (y<2) cout<<endl<<" -----          -----"<<endl;
    }
    cout<<endl;
}

void gato::control_t() {
    int t; // TECLA
    cout<<endl<<" Ingresa el valor => ";
    leer:
    cin>>t;
    if (t>=1 && t<=9) {
        // SE INGRESA TACHA DE ACUERDO A EL NUM DADO
        if (t==1 && campo[0][0]==NADA) campo[0][0]=TACHA;
        else if (t==2 && campo[1][0]==NADA) campo[1][0]=TACHA;
        else if (t==3 && campo[2][0]==NADA) campo[2][0]=TACHA;

        else if (t==4 && campo[0][1]==NADA) campo[0][1]=TACHA;
        else if (t==5 && campo[1][1]==NADA) campo[1][1]=TACHA;
        else if (t==6 && campo[2][1]==NADA) campo[2][1]=TACHA;

        else if (t==7 && campo[0][2]==NADA) campo[0][2]=TACHA;
        else if (t==8 && campo[1][2]==NADA) campo[1][2]=TACHA;
        else if (t==9 && campo[2][2]==NADA) campo[2][2]=TACHA;
        else goto leer;
    } else {
        // SI TECLA NO ES DENTRO DE 1 Y 9, REGRESAR A LEER
        goto leer;
    }
}

void gato::control_cpu() {
    int espacios_libres=0;

    // DETECTA ESPACIOS LIBRES
    for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
            if (campo[x][y]==NADA)
                 espacios_libres++;
        }
    }

    // SI HAT ESPCIOS LIBRES ENTONCES.. ELEGIR UNO
    if (espacios_libres!=0) {

        // ESPACIO ALEATORIO A INGRESAR CIRCULO
        int espacio_aleatorio=rand()%espacios_libres+1;
        espacios_libres=0;
        bool fin_turno=FALSO;

        // SE DETECTA ESPACIOS VACIOS PARA LLEGAR AL ESPACIO ALEATORIO
        for (int y=0; y<3; y++) {
            for (int x=0; x<3; x++) {
                if (campo[x][y]==NADA)
                    espacios_libres++;
                    if (espacios_libres==espacio_aleatorio) {
                        // SE INGRESA EL CIRCULO EN EL ESPACIO ALEATORIO
                        campo[x][y]=CIRCULO;
                        fin_turno=VERDAD;
                        break;
                    }
            }
            if (fin_turno==VERDAD)
            break;
        }
    }
}

bool gato::juego_terminado() {
    int i=0;

    // DETECTA ESPACIOS VACIOS
    for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
            if (campo[x][y]==NADA)
                i++;
        }
    }

    // SI NO HAY ESPACIOS VACIOS ENTONCES.. VERDAD
    if (i==0) return VERDAD;
    else return FALSO;
}

int main(void) {
    // CAMBIA SEMILLA RAND
    srand(time(0));
    // SE DECLARA GATO
    gato G;
    G.genera();
    G.pinta();
    do{
        G.control_t();
        G.control_cpu();
        G.pinta();
    }while(G.juego_terminado()==FALSO);
    // FIN DEL JUEGO
    cout<<endl<<endl<<"    FIN DEL JUEGO"<<endl<<endl;
    return 0;
}
