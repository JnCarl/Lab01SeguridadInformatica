#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
class Encriptacion
{
public:
//funcion para leer el archivo con la poesia original
  void files(const std::string &file){
    std::ifstream archivo(file); //abre el archivo
    std::string linea;
    if (archivo.is_open()){
      while (getline(archivo, linea)){
        std::cout << linea << std::endl;
      }
      archivo.close();
    }
    else{
      std::cout << "archivo no existe" << std::endl;
    }
  }
  //funcion para reemplazar las letras
  void reemplazar(std::string &file){
    std::ifstream archivoE(file); //abre el archivo original 'archivo.txt'
    std::ofstream archivoS("D:/UNSA/2023-A/LabSI/Lab01/archivo_reemplazado.txt"); //crea un nuevo archivo para escribir el poema reemplazado
    if (archivoE.is_open() && archivoS.is_open()){
      std::string linea;
      while (std::getline(archivoE, linea)){
        for (char& c : linea){
          if (c == 'a'){
            c = 'i';
          }
          else if (c == 'h'){
            c = 'j';
          }
          else if (c == 'ñ'){
            c = 'n';
          }
          else if (c == 'k'){
            c = 'l';
          }
          else if (c == 'v'){
            c = 'u';
          }
          else if (c == 'w'){
            c = 'v';
          }
          else if (c == 'z'){
            c = 'y';
          }
          else if (c == 'r'){
            c = 'f';
          }
        }
        archivoS << linea << std::endl;
      }
      archivoE.close();
      archivoS.close();
    }      
  }
  void convertirMayuscula(std::string &file){
    std::ifstream archivoE(file); //abre el archivo original 'archivo.txt'
    std::ofstream archivoS("D:/UNSA/2023-A/LabSI/Lab01/archivoMayuscula.txt"); 
    if (archivoE.is_open() && archivoS.is_open()){
      std::string linea;
      while(std::getline(archivoE, linea)){
        for(char& c : linea){
          c = std::toupper(c);
        }
        archivoS << linea << std::endl;
      }
      archivoE.close();
      archivoS.close();
  }else {
    std::cout <<"no se encontro archivo";
  }
  }
  void eliminar(std::string &file){
    std::ifstream archivoE(file); //abre el archivo original 'archivo.txt'
    std::ofstream archivoS("D:/UNSA/2023-A/LabSI/Lab01/POEMA_PRE.txt"); 
    if (archivoE.is_open() && archivoS.is_open()){
      std::string linea;
      while(std::getline(archivoE, linea)){
         linea.erase(std::remove_if(linea.begin(), linea.end(), [](char c) {
        return std::isspace(c) || std::ispunct(c);
      }), linea.end());
        archivoS << linea << std::endl;
      }
      archivoE.close();
      archivoS.close();
      }
      else {
        std::cout <<"no se encontro archivo";
      }
  }
  //funcion para eliminar tildes de un archivo .txt
  void eliminarTildes(std::string &file){
    std::ifstream archivoE(file); //abre el archivo original 'archivo.txt'
    std::ofstream archivoS("D:/UNSA/2023-A/LabSI/Lab01/eliminarTilde.txt"); 
    if (archivoE.is_open() && archivoS.is_open()){
      std::string linea;
      while(std::getline(archivoE, linea)){
        std::string textoSinTildes = linea;
        std::string tildes = "áéíóúÁÉÍÓÚ";
        std::string sinTildes = "aeiouAEIOU";// Reemplazar cada carácter con tilde por su equivalente sin tilde
        for (size_t i = 0; i < tildes.length(); ++i) {
          size_t pos = textoSinTildes.find(tildes[i]);
          while (pos != std::string::npos) {
            textoSinTildes.replace(pos, 1, sinTildes.substr(i, 1));
            pos = textoSinTildes.find(tildes[i], pos + 1);
          }
        }
        archivoS << textoSinTildes << std::endl;
      }
      archivoE.close();
      archivoS.close();
      }
      else {
        std::cout <<"no se encontro archivo";
      }  
  }
};


int main()
{
  Encriptacion leer;
  std::string texto = "D:/UNSA/2023-A/LabSI/Lab01/archivo.txt";
  //leer.files(texto);
  //std::cout << "\n----------Ahora se reemplaza------------\n"<< std::endl;
  //leer.reemplazar(texto);
  //leer.files("D:/UNSA/2023-A/LabSI/Lab01/archivo_reemplazado.txt");
  
  //leer.convertirMayuscula(texto);
  //leer.files("D:/UNSA/2023-A/LabSI/Lab01/archivoMayuscula.txt");
  
  //leer.eliminar(texto);
  //leer.files("D:/UNSA/2023-A/LabSI/Lab01/POEMA_PRE.txt");
  
  leer.eliminarTildes(texto);
  leer.files("D:/UNSA/2023-A/LabSI/Lab01/eliminarTilde.txt");
  return 0;
}