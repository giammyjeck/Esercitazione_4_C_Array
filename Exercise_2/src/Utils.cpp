#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include <iomanip>

using namespace std;



bool readFile(const string& inputFileName,
              size_t& n,
              double& totSum,
              double*& sumArray,
              double*& rateArray)
{

    ///apro il file
    ifstream file;
    file.open(inputFileName);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }


    /// estraggo totSum
    // estrarre creo un oggetto stringa poi con getline prendo una riga dal file e la metto nella stringa,
    // ripeto scorrendo tutto il file finchè non trovo la linea che inizia con S, poi dalla stringa devo metterlo
    // nella variabile giusta con l'oggetto istringstream

    string linea;
    while (!file.eof())
    {
        getline(file, linea);

        if (linea[0] == 'S')
            break;
    }
    istringstream convertTotSum;
    convertTotSum.str(linea);
    char c1; //i primi due sono da scartare
    char c2;
    convertTotSum >> c1 >> c2 >> totSum;


    /// estraggo n
    // n è nella riga successiva a quella di S

    getline(file, linea);
    istringstream convert_n;
    convert_n.str(linea);
    convert_n >> c1 >> c2 >> n;

    /// creo i due array
    // devo chiedere che i puntatori che ho inizializzato nel main puntino a due array di interi lunghi 8
    // questi puntatori devono morire quando chiudo il main, dopo che ho svolto tutti i calcoli
    sumArray = new double[n];
    rateArray = new double[n];


    /// leggo riga per riga e riempio gli array
    // la prima riga dopo n è una riga di intestazione che va scartata, poi le altre le leggo e le processo
    string scarto;
    getline(file, scarto);

    istringstream convertArrays;
    for (unsigned int i = 0; i < n; i++)
    {
        getline(file, linea);
        convertArrays.str(linea);
        convertArrays >> sumArray[i] >> c1 >> rateArray[i];
        convertArrays.clear();
        //TEST cout << sumArray[i] << " : "<< rateArray[i] << endl;
    }


    /// chiudo il file
    file.close();


    return true;
}


double calcoloRate(const size_t& n,
                   const double* const& sumArray,
                   const double* const& rateArray)
{
    double rate = 0;
    for (unsigned int i = 0; i < n; i++)
        rate += (rateArray[i]) * sumArray[i];

    //cout<< rate <<endl;
    return rate;
}



double calcoloValue(const double& totSum,
                    const double& rate)
{
    double value = (1+rate) * totSum;
    //cout<< fixed << setprecision(2) << value <<endl;

    return value;

}




bool writeFile(const string& outputFileName,
               const size_t& n,
               const double& totSum,
               const double* const& sumArray,
               const double* const& rateArray,
               const double& rate,
               const double& value)
{

    /// Open File
    ofstream file;
    file.open(outputFileName);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }


    /// stampa su file dei vettori su e risultati nella forma specificata
    file << "S = "<< fixed << setprecision(2) << totSum << ", n = "<< n << endl;

    file<< "w = "<< "[ ";
    for (unsigned int i = 0; i < n; i++)
        file<< sumArray[i] << " ";
    file << "]"<< endl;


    file<< "r = "<< "[ ";
    for (unsigned int i = 0; i < n; i++)
        file<< rateArray[i] << " ";
    file << "]"<< endl;

    file << "Rate of return of the portfolio: "  << setprecision(4) << rate << endl;
    file << "V: " << fixed << setprecision(2) << value;


    /// Close File
    file.close();




    /// stampa su monitor dei vettori su e risultati nella forma specificata
    cout << "S = "<< fixed << setprecision(2) << totSum << ", n = "<< n << endl;

    cout<< "w = "<< "[ ";
    for (unsigned int i = 0; i < n; i++)
        cout<< sumArray[i] << " ";
    cout << "]"<< endl;


    cout<< "r = "<< "[ ";
    for (unsigned int i = 0; i < n; i++)
        cout<< rateArray[i] << " ";
    cout << "]"<< endl;

    cout << "Rate of return of the portfolio: "  << setprecision(4)<< rate << endl;
    cout << "V: " << fixed << setprecision(2) << value<< endl;;







    return true;
}




