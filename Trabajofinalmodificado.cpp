#include <iostream>
#include <iostream>
#include <string>
#include <cstdlib> // para borrar la pantalla con system
#include <chrono> // para medir el tiempo
#include <conio.h> // para hacer una pausa y pasar presionando cualquier tecla, solo funciona en windows
#include <limits> // limpia el buffer
using namespace std;

//while,for,switch,vectores

string nombre;
int opcion=0, puntos = 0, ejercicio = 0, respuesta;
int correctas[8] = {2,3,1,2,3,1,2,1};  
// Respuestas correctas de los 8 ejercicios

string operaciones[4][2] = {
    {"SUMAS", "Resuelve las siguientes sumas:"},
    {"RESTAS", "Resuelve las siguientes restas:"},
    {"MULTIPLICACIONES", "Resuelve las siguientes multiplicaciones:"},
    {"DIVISIONES", "Resuelve las siguientes divisiones:"}
};



int main() {
    setlocale(LC_ALL,"");
	
    cout<<"======================================="<<endl;
    cout<<" ¡BIENVENIDO AL DESAFIO DE FRACCIONES! "<<endl;
    cout<<"======================================="<<endl;
    cout<<"Por favor ingresa tu nombre: ";
    getline(cin,nombre);
    system("cls");

    cout<<"Hola "<<nombre<<", este juego te ayudara a practicar sumas, restas,"<<endl;
    cout<<"multiplicaciones y divisiones de fracciones."<<endl;
    cout<<"Por cada respuesta correcta ganaras 100 puntos."<<endl;
    cout<<"¡MUCHA SUERTE!"<<endl<<endl;
    cout<<"PRESIONA CUALQUIER TECLA PARA CONTINUAR"<<endl;
    _getch(); // para pasar a la siguiente pantalla presionando cualquier tecla
    

    while (opcion !=3) {

        system("cls");
        cout<<"==============================="<<endl;
        cout<<" MENU PRINCIPAL - " <<nombre<<endl;
        cout<<"==============================="<<endl<<endl;
        cout<<"1. Jugar"<<endl;
        cout<<"2. Ver instrucciones"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Selecciona una opcion: "<<endl;
        cin>>opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia el buffer

        if (opcion < 1 || opcion > 3) {
            cout<<"Opción no válida. Por favor elige una opcion del 1 al 3."<<endl;
            cout<<"Presiona cualquier tecla para continuar..."<<endl;
            _getch(); 
            continue;
        }

        switch (opcion) {

        case 1: {
            system("cls");
            puntos=0; // reinicia variables de la partida
            ejercicio=0;
            
            
            auto start = chrono::high_resolution_clock::now(); // registra el tiempo de inicio

            for (int tipo = 0; tipo < 4; tipo++) {
            	system("cls");
                cout<<"-------------------------------"<<endl;
                cout<<"Desafio: "<<operaciones[tipo][0]<<endl;
                cout<<operaciones[tipo][1]<<endl;
                cout<<"-------------------------------"<<endl;

                for (int e = 0; e < 2; e++) {
                    cout<<"Ejercicio "<<(ejercicio + 1)<<":"<<endl;

                    switch (ejercicio) {
                        case 0:
      					    cout<<"¿Cuánto es 7/12 + 5/18?"<<endl;
        					cout<<"1) 12/30\n2) 31/36\n3) 35/216"<<endl<<endl;
       						break;
    					case 1:
        					cout<<"¿Cuánto es 4/15 + 11/20?"<<endl;
        					cout<<"1) 15/35\n2) 44/300\n3) 49/60"<<endl<<endl;
       					    break;
    					case 2:
        					cout<<"¿Cuánto es 13/16 - 5/24?"<<endl;
        					cout<<"1) 29/48\n2) 8/8\n3) 65/384"<<endl<<endl;
        					break;
                        case 3:
        					cout<<"¿Cuánto es 9/14 - 7/20?"<<endl;
        					cout<<"1) 2/6\n2) 41/140\n3) 63/280"<<endl<<endl;
        					break;
    					case 4:
        					cout<<"¿Cuánto es 18/25 * 35/54?"<<endl;
        					cout<<"1) 630/1350\n2) 7/15\n3) 53/79"<<endl<<endl;	
        					break;
    					case 5:
        					cout<<"¿Cuánto es 14/25 * 10/49?"<<endl;
        					cout<<"1) 4/35\n2) 140/1225\n3) 24/74"<<endl<<endl;
        					break;
   						 case 6:
        					cout<<"¿Cuánto es (5/12) ÷ (10/33)?"<<endl;
        					cout<<"1) 50/396\n2) 11/8\n3) 15/22"<<endl<<endl;
        					break;
                        case 7:
        					cout<<"¿Cuánto es (8/15) ÷ (12/25)?"<<endl;
        					cout<<"1) 10/9\n2) 96/375\n3) 20/27"<<endl<<endl;
        					break;
                    }

                    cout<<"Tu respuesta: "<<endl;
                    cin>>respuesta;

                    if (respuesta == correctas[ejercicio]) {
                        cout << "¡Correcto!"<<endl<<endl;
                        puntos += 100;
                    } else {
                        cout << "Incorrecto."<<endl<<endl;
                    }
                    ejercicio++;
                }
				
				
            }
            	auto end = chrono::high_resolution_clock::now(); // registra el tiempo de finalizacion.
				auto duration = chrono::duration_cast<chrono::seconds>(end - start); // calcula la duracion en segundos
            	int tiempoTotal = duration.count();
            	
            	cout<<"¡JUEGO TERMINADO!"<<endl;
                cout<<"PUNTAJE FINAL: "<<puntos<<" PUNTOS"<<endl;
                cout<<"TIEMPO TOTAL: "<<tiempoTotal<<" SEGUNDOS"<<endl;
                cout<<"PRESIONA CUALQUIER TECLE PARA VOLVER AL MENÚ"<<endl;
                _getch();
                system("cls");
            	
        } break;


        case 2:
            system("cls");
            cout<<"==============================="<<endl;
            cout<<"    INSTRUCCIONES DEL JUEGO"<<endl;
            cout<<"==============================="<<endl<<endl;
            cout<<"- Lee la explicación antes de cada desafío."<<endl;
            cout<<"- Responde con el número de la opción correcta."<<endl;
            cout<<"- Cada respuesta correcta suma 100 puntos."<<endl;
            cout<<"- Gana puntos para subir de nivel."<<endl<<endl;
            cout<<"=============================================" << endl;
            cout<<"PRESIONA CUALQUIER TECLA PARA VOLVER AL MENÚ..."<<endl;
            _getch();
            break;

        case 3:
            cout<<"MUCHAS GRACIAS POR JUGAR EL DESAFIO DE FRACCIONES";
            return 0;
        }
    }

    return 0;
}