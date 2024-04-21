#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;

int main()
{

    string inputFileName = "./data.csv";
    size_t n = 0;
    double totSum ;
    double* sumArray = nullptr;
    double* rateArray = nullptr;


    /// leggo il file
    // chiamo una funzione che legga il file, devo costruire il vettore sumArray e rateArray. mi serve la dimensione n,
    // ho due puntatori che puntano ai due array (devo aggiornare n e totSum e aggiungere memoria ai due puntatori)
    // se fallisce la lettura return error

    if (readFile(inputFileName, n, totSum, sumArray, rateArray))
    {
        cout << "file letto correttamente"<< endl;
        //aggiungere stampa dei risultati su schermo?
    }
    else
    {
        cerr << "errore lettura file"<< endl;;
        return -1;
    }


    /// faccio i conti
    // funzione che dati gli array e la totSum calcola
    // rate of return and the final value of the whole portfolio

    double rate = calcoloRate(n, sumArray, rateArray);
    double value = calcoloValue(totSum, rate);


    /// scrivo il file e stampo su schermo
    // funzione che crea il file di output e scrive i risultati, nel formato specificato
    // se succede qualcosa viene segnalato con return -2.


    string outputFileName = "./result.txt";
    if (writeFile(outputFileName, n, totSum, sumArray, rateArray , rate, value))
    {
        cout<< "file scritto correttamente"<< endl;
    }
    else
    {
        cerr<< "Errore creazione file di output"<< endl;
        return -2;
    }



    delete[] sumArray;
    delete[] rateArray;


  return 0;
}

