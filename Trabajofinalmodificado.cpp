#include<iostream>
#include<cstdlib> // para system
using namespace std;

//while,for,switch,vectores

string nombre;
int opcion;


string operaciones[4][2] = {
    {"SUMAS", "Resuelve las siguientes sumas:"},
    {"RESTAS", "Resuelve las siguientes restas:"},
    {"MULTIPLICACIONES", "Resuelve las siguientes multiplicaciones:"},
    {"DIVISIONES", "Resuelve las siguientes divisiones:"}
};

int correctas[8] = {2,3,1,1,1,2,2,2}; 
// Respuestas correctas de los 8 ejercicios

int respuesta; 


int main() {
    setlocale(LC_ALL,"");
	
    cout << "==============================" << endl;
    cout << "  ¡Bienvenido al Desafio de Fracciones! " << endl;
    cout << "===============================" << endl;
    cout << "Por favor ingresa tu nombre: ";
    getline(cin,nombre);
    system("cls");

    cout << "Hola " << nombre << ", este juego te ayudara a practicar sumas, restas,"<<endl;
    cout << "multiplicaciones y divisiones de fracciones."<<endl;
    cout << "Por cada respuesta correcta ganaras 100 puntos."<<endl<<endl;
    cout << "¡MUCHA SUERTE!";

    while (opcion != 3) {

        system("cls");
        cout << "===============================" << endl;
        cout << "     MENU PRINCIPAL - " << nombre << endl;
        cout << "===============================" << endl;
        cout << "1. Jugar\n";
        cout << "2. Ver instrucciones\n";
        cout << "3. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (opcion < 1 || opcion > 3) {
            cout << "Opción no válida. Por favor elige 1, 2 o 3.\n\n";
            cout << "Presiona cualquier tecla para continuar...";
            cin >> nombre; 
            continue;
        }

        switch (opcion) {

        case 1: {
            system("cls");

            int puntos = 0;
            int ejercicio = 0;

            for (int tipo = 0; tipo < 4; tipo++) {
                cout << "-------------------------------" << endl;
                cout << "Desafio: " << operaciones[tipo][0] << endl;
                cout << operaciones[tipo][1] << endl;
                cout << "-------------------------------" << endl;

                for (int e = 0; e < 2; e++) {
                    cout << "\nEjercicio " << (ejercicio + 1) << ":\n";

                    switch (ejercicio) {
                        case 0:
                            cout << "¿Cuánto es 1/2 + 1/2?\n";
                            cout << "1) 1/4\n2) 1\n3) 2/4\n";
                            break;
                        case 1:
                            cout << "¿Cuánto es 3/4 + 1/4?\n";
                            cout << "1) 3/8\n2) 4/8\n3) 1\n";
                            break;
                        case 2:
                            cout << "¿Cuánto es 3/4 - 1/4?\n";
                            cout << "1) 1/2\n2) 3/8\n3) 2\n";
                            break;
                        case 3:
                            cout << "¿Cuánto es 5/6 - 1/6?\n";
                            cout << "1) 2/3\n2) 3/4\n3) 4/6\n";
                            break;
                        case 4:
                            cout << "¿Cuánto es 1/2 * 1/3?\n";
                            cout << "1) 1/6\n2) 1/5\n3) 2/3\n";
                            break;
                        case 5:
                            cout << "¿Cuánto es 3/4 * 2/3?\n";
                            cout << "1) 1/2\n2) 3/6\n3) 6/7\n";
                            break;
                        case 6:
                            cout << "¿Cuánto es (1/2) ÷ (1/4)?\n";
                            cout << "1) 1/8\n2) 2\n3) 4\n";
                            break;
                        case 7:
                            cout << "¿Cuánto es (3/5) ÷ (3/10)?\n";
                            cout << "1) 1/2\n2) 2\n3) 3\n";
                            break;
                    }

                    cout << "Tu respuesta: ";
                    cin >> respuesta;

                    if (respuesta == correctas[ejercicio]) {
                        cout << "¡Correcto!\n";
                        puntos += 10;
                    } else {
                        cout << "Incorrecto.\n";
                    }
                    ejercicio++;
                }

                cout << "\nLlevas " << puntos << " puntos.\n";
                cout << "Presiona una tecla y ENTER para continuar...";
                cin >> nombre;
                system("cls");
            }
        } break;


        case 2:
            system("cls");
            cout << "===============================" << endl;
            cout << "   INSTRUCCIONES DEL JUEGO" << endl;
            cout << "===============================" << endl;
            cout << "- Lee la explicación antes de cada desafío.\n";
            cout << "- Responde con el número de la opción correcta.\n";
            cout << "- Cada respuesta correcta suma 100 puntos.\n";
            cout << "- Gana puntos para subir de nivel.\n";
            cout << "===============================" << endl;
            cout << "Presiona una tecla para volver...";
            cin >> nombre;
            break;

        case 3:
            cout << "====================================================" << endl;
            cout << "MUCHAS GRACIAS POR JUGAR EL DESAFIO DE FRACCIONES";
            return 0;
        }
    }

    return 0;
}

