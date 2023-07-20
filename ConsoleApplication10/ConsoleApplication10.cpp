//Critter
#include <iostream>
#include <vector>

using namespace std;

void mainEj1();
void mainEj2();

class Critter
{
public:
    Critter(int hunger = 10, int boredom = 10, int thirst = 10);
    void Talk();
    void NeedsList();
    void Die(); 
    void Eat(int food = 4);
    void Play(int fun = 4);
    void Drink(int water = 4);

private:
    int m_Hunger;
    int m_Boredom;
    int m_Thirst;
    bool dead = false;
    void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom, int thirst) :
    m_Hunger(hunger),
    m_Boredom(boredom),
    m_Thirst(thirst)

{
    cout << "--- Lista de necesidades ---" << endl;
    cout << "Thirst: " << m_Thirst << endl;
    cout << "Boredom: " << m_Boredom << endl;
    cout << "Hunger: " << m_Hunger << endl;
}

void Critter::Die() {
    if (m_Hunger == 0) {
        cout << endl << "Mori de hambre..." << endl;
        exit(0);
    }
    else if (m_Boredom == 0) {
        cout << endl << "Mori de aburrimiento..." << endl;
        exit(0);
    }
    else if (m_Thirst == 0) {
        cout << endl << "Mori de sed..." << endl;
        exit(0);
    }
    else {
        return;
    }
}

void Critter::NeedsList() 
{
    cout << "--- Lista de necesidades ---" << endl;
    cout << "Thirst: " << m_Thirst << endl;
    cout << "Boredom: " << m_Boredom << endl;
    cout << "Hunger: " << m_Hunger << endl;
}


void Critter::PassTime(int time)
{
    m_Hunger -= time;
    m_Boredom -= time;
    m_Thirst -= time;
}

void Critter::Talk()
{
    if (m_Hunger <= 2) {
        cout << "Humano, voy a MORIR por no comer, ayuda !!" << endl;
    } else if (m_Boredom <= 2) {
        cout << "Humano, voy a MORIR de aburrimiento, ayuda !!" << endl;
    } else if (m_Thirst <= 2) {
        cout << "Humano, voy a MORIR de sed, ayuda !!" << endl;
    } else if (m_Hunger <= 5) {
        cout << "Humano, tengo MUCHA hambre." << endl;
    } else if (m_Boredom <= 5) {
        cout << "Humano, estoy MUY aburrido." << endl;
    } else if (m_Thirst <= 5) {
        cout << "Humano, tengo MUCHA sed." << endl;
    } else if (m_Hunger < 10) {
        cout << "Humano, tengo hambre." << endl;
    } else if (m_Boredom < 10) {
        cout << "Humano, estoy aburrido." << endl;
    } else if (m_Thirst < 10) {
        cout << "Humano, tengo sed." << endl;
    } else {
        cout << "Humano estoy bien ! Gracias por cuidarme buena. :3" << endl;
    }

    PassTime();
    Die();
    NeedsList();
}

void Critter::Eat(int food)
{
    cout << "\nBrrupp. \n";
    m_Hunger += food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime();
    NeedsList();
    Die();
}

void Critter::Play(int fun)
{
    cout << "\nWheee!\n";
    m_Boredom += fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    PassTime();
    NeedsList();
    Die();
}

void Critter::Drink(int water)
{
    cout << "\nSlurp!\n";
    m_Thirst += water;
    if (m_Thirst < 0)
    {
        m_Thirst = 0;
    }
    PassTime();
    NeedsList();
    Die();
}

int main()
{
    int ejercicios;
    do {
        cout << "Cual ejercicio hoy?" << endl;
        cout << "1) Numero Vectores" << endl;
        cout << "2) Mascota" << endl;
        cin >> ejercicios;
        if (ejercicios == 1)
        {

            mainEj1();
        }
        else if (ejercicios == 2) {
            mainEj2();
        }
        else {
            cout << "Inserte un valor valido." << endl;
        }
    } while (ejercicios != 1 && ejercicios != 2);

}

#include <iostream>
#include <vector>

using namespace std;

// Función para contar la cantidad de dígitos pares en un número
int contarDigitosPares(int numero) {
    int contador = 0;
    while (numero != 0) {
        if ((numero % 10) % 2 == 0)
            contador++;
        numero /= 10;
    }
    return contador;
}

// Función para encontrar el número con la mayor cantidad de dígitos pares
int* encontrarNumeroConMasDigitosPares(const vector<int>& numeros) {
    if (numeros.empty())
        return nullptr;

    int maxDigitosPares = 0;
    int* punteroNumeroMaxDigitosPares = nullptr;

    for (int i = 0; i < numeros.size(); ++i) {
        int cantidadDigitosPares = contarDigitosPares(numeros[i]);
        if (cantidadDigitosPares > maxDigitosPares) {
            maxDigitosPares = cantidadDigitosPares;
            punteroNumeroMaxDigitosPares = const_cast<int*>(&numeros[i]);
        }
    }

    return punteroNumeroMaxDigitosPares;
}

void mainEj1() {
    vector<int> numeros;
    int numero;

    cout << "Ingresa 8 números:" << endl;

    for (int i = 0; i < 8; ++i) {
        cin >> numero;
        numeros.push_back(numero);
    }

    int* punteroNumeroMaxDigitosPares = encontrarNumeroConMasDigitosPares(numeros);

    if (punteroNumeroMaxDigitosPares != nullptr) {
        int posicion = punteroNumeroMaxDigitosPares - &numeros[0];
        cout << "Número con la mayor cantidad de dígitos pares: " << *punteroNumeroMaxDigitosPares << endl;
        cout << "Dirección de memoria: " << punteroNumeroMaxDigitosPares << endl;
        cout << "Posición en el vector: " << posicion << endl;
    }
    else {
        cout << "No se ingresaron números o todos los números tienen cero dígitos pares." << endl;
    }

}

void mainEj2() {

    Critter crit;
    int choice;
    do
    {
        cout << "\n Mascotas Virtuales\n\n";
        cout << "0 - Salir.\n";
        cout << "1 - Escucha a tu mascota.\n";
        cout << "2 - Alimentar.\n";
        cout << "3 - Jugar con tu mascota.\n";
        cout << "4 - Darle de tomar a tu mascota.\n";
        cout << "Elige una opcion: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Vuelve pronto!.\n";
            break;
        case 1:
            crit.Talk();
            break;
        case 2:
            crit.Eat();
            break;
        case 3:
            crit.Play();
            break;
        case 4:
            crit.Drink();
            break;
        default:
            cout << "\n Tu elección es inválida. \n";
        }
    } while (choice != 0);
}
