#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
void leerArchivo();
void escribirArchivo(string value);

int main() {
  leerArchivo();
  return 0;
}

void leerArchivo(){

  ifstream archivo("hola.txt");
  string line;
  int accumulator=0;

  unordered_map<string, int> memory;  

  if(archivo.is_open()){
    while(getline(archivo,line)){
      istringstream iss(line);
      vector <string> palabras;
      string palabra;
      while(iss>> palabra){
        palabras.push_back(palabra);
      }
      // SET
       if (!palabras.empty() && palabras[0] == "SET" && palabras.size() >= 3) {
         string clave = palabras[1];
         int valor = stoi(palabras[2]);
         memory[clave] = valor;
      }
      //SHOW
      if (!palabras.empty() && palabras[0] == "SHW" && palabras.size() >= 3) {
        int value= memory[palabras[1]] ;
        cout<<memory[palabras[1]]<<endl;
        string show= to_string(memory[palabras[1]]);
        escribirArchivo(show);
      }
      //ADD
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
      //LDR 
      if (!palabras.empty() && palabras[0] == "LDR" && palabras.size() >= 3) {
        int value= memory[palabras[1]];
        accumulator=value;
       
      }
      // MUL
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
      // SUB
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
      // DIV
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
      //INC
      if (!palabras.empty() && palabras[0] == "INC" && palabras.size() >= 3){
        int value = memory[palabras[1]];
        int increment = value + 1;
        memory[palabras[1]]=increment;
      
      }
      //DEC
      if (!palabras.empty() && palabras[0] == "DEC" && palabras.size() >= 3){
        int value = memory[palabras[1]];
        int decrement = value - 1;
        memory[palabras[1]]=decrement;
        
      }
      //MOV
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
