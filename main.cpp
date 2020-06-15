#include <QCoreApplication>
#include <QtDebug>
#include <iostream>
#include <QStack>
#include <QList>
#include <QQueue>
#include <QSet>

void listas();
void pilas();
void colas();
void conjuntos();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int opc = 0;
    do{
        qDebug() << "\n-- MENU DE COLECCIONES --";
        qDebug() << "1. Listas";
        qDebug() << "2. Colas";
        qDebug() << "3. Pilas";
        qDebug() << "4. Conjuntos";
        qDebug() << "5. Salir";
        qDebug() << "\nIngrese su opción: ";
        std::cin >> opc;
        switch (opc) {
        case 1:
            qDebug() << "-- LISTAS --\n";
            listas();
            break;
        case 2:
            qDebug() << "-- COLAS --\n";
            colas();
            break;
        case 3:
            qDebug() << "-- PILAS --\n";
            pilas();
            break;
        case 4:
            qDebug() << "-- CONJUNTOS --\n";
            conjuntos();
            break;
        case 5:
            qDebug() << "-- ADIOS --";
            break;
        default:
            qDebug() << "Opción incorrecta!";
            break;
        }
    }while(opc != 5);

    return a.exec();
}


void listas(){
    // Creando una lista de pares
    QList<int> pares;
    pares << 2 << 4 << 6;

    qDebug() << "Lista original: " << pares;

    // Agregando datos
    pares.prepend(0);       // agrega 0 al inicio
    pares.append(10);       // agrega 10 al final
    pares.insert(4,8);      // agrega 8 después del 4to elemento

    qDebug() << "Lista con nuevos elementos: " << pares;

    // Recorriendo elementos de una lista
    qDebug() << "\nRecorriendo la lista:";
    QListIterator<int> i(pares);
    while(i.hasNext()){
        qDebug () << "Número par:" << i.next();
    }

    // Tomando datos
    qDebug() << "\nTomando datos:";
    int dato = pares.at(0);
    qDebug() << "Se obtiene el primer elemento:" << dato;
    dato = pares.takeAt(0);
    qDebug() << "Se remueve el primer elemento:" << dato;


    // Eliminando datos
    pares.removeFirst();    // remueve primer elemento
    pares.removeLast();     // remueve último elemento
    pares.removeAt(2);      // remueve el 3er elemento

    qDebug() << "\nLista luego de remover elementos: " << pares;
}


void pilas(){
    // Creando una lista de pares
    QStack<float> pila;
    pila.push(25.65);
    pila.push(31.58);
    pila.push(78.41);

    qDebug() << "Pila original:" << pila;

    qDebug() << "Top:" << pila.top(); // 3
    qDebug() << "Pop:" << pila.pop(); // 3
    qDebug() << "Pop:" << pila.pop(); // 2
    qDebug() << "Pop:" << pila.pop(); // 1
    pila.isEmpty(); // true
}

void colas(){
    QQueue<QString> cola;
    cola.enqueue("Goku");
    cola.enqueue ("Vegeta");
    cola.enqueue ("Freezer");

    qDebug() << "Cola original:" << cola;

    qDebug() << "Top: " << cola.head(); // 1
    qDebug() << "Dequeue: " << cola.dequeue(); // 1
    qDebug() << "Dequeue: " << cola.dequeue(); // 2
    qDebug() << "Dequeue: " << cola.dequeue(); // 3
    cola.isEmpty(); // true
}

void conjuntos(){
    QSet<int> conjunto;
    conjunto << 1 << 3 << 7 << 9 << 3;

    qDebug() << "Conjunto original:" << conjunto;

    conjunto.contains(8);   // false
    conjunto.contains(3);   // true
    conjunto.remove(8);     // false y no borra nada
    conjunto.remove(3);     // true y borra el 3

    qDebug() << "Conjunto resultante:" << conjunto;

    qDebug() << "\nOperacion con listas y Conjuntos";
    QList<int> pares;
    pares << 2 << 2 << 4 << 4 << 8;     // 2,2,4,4,8
    QSet<int> numeros = pares.toSet(); // 2,4,8
    QList<int> pares_no_repes = numeros.toList();

    qDebug() << "Lista de números pares: " << pares;
    qDebug() << "Conjunto de números pares: " << numeros;
    qDebug() << "Nueva lista de números pares: " << pares_no_repes;
}
