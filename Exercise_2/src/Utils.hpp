#pragma once
#include "iostream"

using namespace std;




// readFile apre e legge il file inputFileName.
// Restituisce true se è andato a buon fine, false se errore
// inputFileName: nome del file
// n: la dimensione finale degli array
// totSum: è la somma totale che posso investire
// sumArray: array con le percentuali da investire in ogni asset
// rateArray: array con i tassi di profitto di ogni asset
bool readFile(const string& inputFileName,
              size_t& n,
              double& totSum,
              double*& sumArray,
              double*& rateArray);


// calcoloRate calcola il tasso di profitto del portafoglio
// n: la dimensione finale degli array
// sumArray: array con le percentuali da investire in ogni asset
// rateArray: array con i tassi di profitto di ogni asset
// la funzione esegue il calcolo  (r[0])s[0] + (r[1])s[1] + ... + (r[n-1])s[n-1]
double calcoloRate(const size_t& n,
                    const double* const& sumArray,
                    const double* const& rateArray);


// calcoloValue calcola il valore finale del portafoglio
// totSum: è la somma totale che posso investire
// rate: è il tasddo di profitto del portafoglio, calcolato usando la funzione calcoloRate
// la funzione esegue il calcolo (1+rate)*totSum
double calcoloValue(const double& totSum,
                            const double& rate);




// writeFile apre e scrive nel file outputFileName. stampa anche a schermo nel formato specificato
// Restituisce true se è andato a buon fine, false se errore
// outputFileName: nome del file
// n: la dimensione finale degli array
// totSum: è la somma totale che posso investire
// sumArray: array con le percentuali da investire in ogni asset
// rateArray: array con i tassi di profitto di ogni asset
// rate: è il tasso di profitto del portafoglio, calcolato usando la funzione calcoloRate
// value: è il profitto finale del portafoglio calcoato usando calcoloValue

bool writeFile(const string& outputFileName,
               const size_t& n,
               const double& totSum,
               const double* const& sumArray,
               const double* const& rateArray,
               const double& rate,
               const double& value);


