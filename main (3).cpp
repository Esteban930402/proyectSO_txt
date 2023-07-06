#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
void leerArchivo(); //Funcion encargada de leer el archivo de entrada
void escribirArchivo(string value);// Funcion encargada de escribir y crear un archivo txt con los resultados de las instrucciones dadas en el programa
//main
int main() {
  leerArchivo();
  return 0;
}

void leerArchivo(){
  string fileName;
  cout<<"Ingrese el nombre del archivo: ";
  cin>>fileName;
  ifstream archivo(fileName+".txt");
  string line;
  int accumulator=0;

  unordered_map<string, int> memory;  //Se utiliza el unordered_map para crear datos con manejo de clave-valor

  if(archivo.is_open()){
    
    while(getline(archivo,line)){ //Se encarga de leer el archivo linea a linea
      istringstream iss(line);
      vector <string> palabras;
      string palabra;
      while(iss>> palabra){ //Se encarga de almacenar las palabras en un vector
        palabras.push_back(palabra);
      }
      // SET : almacena un valor en una direccion de memoria
       if (!palabras.empty() && palabras[0] == "SET" && palabras.size() >= 3) { 
         string clave = palabras[1];
         int valor = stoi(palabras[2]);
         memory[clave] = valor;
      }
      //SHOW : Muestra el valor asociado a la direccion en memoria
      if (!palabras.empty() && palabras[0] == "SHW" && palabras.size() >= 3) {
        int value= memory[palabras[1]] ;
        cout<<memory[palabras[1]]<<endl;
        string show= to_string(memory[palabras[1]]);
        escribirArchivo(show);
      }
      //ADD : suma un valor de una direccion de memoria al acumulador
      if (!palabras.empty() && palabras[0] == "ADD" && palabras.size() >= 3) {
          if(palabras[2]=="NULL" && palabras[3]=="NULL"){
            int value= memory[palabras[1]] ;
            accumulator=accumulator+value;            
            
          }
          if(palabras[2]!="NULL" && palabras[3]=="NULL"){
          
            int value= memory[palabras[1]];
            int value2= memory[palabras[2]];
            accumulator=  value + value2;
            
          }
          if(palabras[2]!="NULL" && palabras[3]!="NULL"){
            int value= memory[palabras[1]];
            int value2= memory[palabras[2]];
            int suma = value + value2;
            memory[palabras[3]]=suma;
            
          }
      }
      //LDR : carga el valor de una direccion de memoria al acumulador
      if (!palabras.empty() && palabras[0] == "LDR" && palabras.size() >= 3) {
        int value= memory[palabras[1]];
        accumulator=value;
       
      }
      // MUL : multiplica el acumulador por el valor en direccion de memoria
      if (!palabras.empty() && palabras[0] == "MUL" && palabras.size() >= 3) {
          if(palabras[2]=="NULL" && palabras[3]=="NULL"){
            int value= memory[palabras[1]] ;
            accumulator=accumulator*value;            
           
          }
          if(palabras[2]!="NULL" && palabras[3]=="NULL"){
          
            int value= memory[palabras[1]];
            int value2= memory[palabras[2]];
            accumulator=  value * value2;
            
          }
          if(palabras[2]!="NULL" && palabras[3]!="NULL"){
            int value= memory[palabras[1]];
            int value2= memory[palabras[2]];
            int suma = value * value2;
            memory[palabras[3]]=suma;
            
          }
      }
      // SUB : resta
      if (!palabras.empty() && palabras[0] == "SUB" && palabras.size() >= 3) {
          if(palabras[2]=="NULL" && palabras[3]=="NULL"){
            int value= memory[palabras[1]] ;
            accumulator=accumulator-value;            
           
          }
          if(palabras[2]!="NULL" && palabras[3]=="NULL"){
            int value= memory[palabras[1]];
            int value2= memory[palabras[2]];
              accumulator=  value -value2;
          
          }
          if(palabras[2]!="NULL" && palabras[3]!="NULL"){
            int value= memory[palabras[1]];
            int value2= memory[palabras[2]];
            int suma = value - value2;
            memory[palabras[3]]=suma;
          }
      }
      // DIV : division
      if (!palabras.empty() && palabras[0] == "DIV" && palabras.size() >= 3) {
          if(palabras[2]=="NULL" && palabras[3]=="NULL"){
            int value= memory[palabras[1]] ;
            accumulator=accumulator/value;          
          }
          if(palabras[2]!="NULL" && palabras[3]=="NULL"){
          
            int value= memory[palabras[1]];
            int value2= memory[palabras[2]];
              accumulator=  value /value2;
             
          }
          if(palabras[2]!="NULL" && palabras[3]!="NULL"){
            int value= memory[palabras[1]];
            int value2= memory[palabras[2]];
            int suma = value / value2;
            memory[palabras[3]]=suma;
            
          }
      }
      //INC : incrementa en 1 el valor de la direccion de memoria
      if (!palabras.empty() && palabras[0] == "INC" && palabras.size() >= 3){
        int value = memory[palabras[1]];
        int increment = value + 1;
        memory[palabras[1]]=increment;
      
      }
      //DEC : Decrementa en 1 el valor de la direccion de memoria
      if (!palabras.empty() && palabras[0] == "DEC" && palabras.size() >= 3){
        int value = memory[palabras[1]];
        int decrement = value - 1;
        memory[palabras[1]]=decrement;
        
      }
      //MOV : almacena 
      if (!palabras.empty() && palabras[0] == "MOV" && palabras.size() >= 3){
        int value = memory[palabras[1]];
        memory.erase(palabras[1]);
        memory[palabras[2]]=value;
      
      }
      //STORE
      if (!palabras.empty() && palabras[0] == "STR" && palabras.size() >= 3) {
        memory[palabras[1]]=accumulator;
        accumulator=0;
      }
    }
    archivo.close();
  }
}
void escribirArchivo(string value){
  string shw = value;
  string fileName;
  time_t timeP = time(nullptr);
  srand(static_cast<unsigned int>(timeP));

  int randomNumber = rand()%10000;

  fileName = "exit_"+to_string(randomNumber)+".txt";

  ofstream archivo(fileName);

  if(archivo.is_open()){
    archivo<<shw<<endl;
  }
}
