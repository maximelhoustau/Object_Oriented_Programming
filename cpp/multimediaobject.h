#ifndef MULTIMEDIAOBJECT_H
#define MULTIMEDIAOBJECT_H
#include <iostream>
#include <string>
using namespace std;


class MultimediaObject
{
protected:
    string name = "Default";
    string path = "./" ;

public:
    //Constructeurs de la classe
    MultimediaObject(string _name, string _path);
    MultimediaObject();

    //getters
    string getName() const;
    string getPath() const;

    //setters
    void setName(string _name);
    void setPath(string _path);

    //Destructeur
    ~MultimediaObject() {cerr << "Objet effacé \n" ;}

    //affichage des variables de l'objet
    virtual void printInfos(ostream& stream) const;

    virtual void play() const = 0;
};

#endif // MULTIMEDIAOBJECT_H
