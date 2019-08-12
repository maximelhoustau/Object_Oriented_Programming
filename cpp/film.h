#ifndef FILM_H
#define FILM_H
#include "video.h"

class Film : public Video
{
private:
    int nb_chapters = 0;
    int * chapters = nullptr;

    void setDuration(int _duration) override
    {
        Video::setDuration(_duration);
    };

public:
    ///Constructeurs
    Film() : Video(), nb_chapters(1), chapters(nullptr) {}
    Film(string _name, string _path, int _duration, int _nb_chapters, int * _chapters ) : Video(_name, _path, 0), nb_chapters(_nb_chapters)
    {
        int total_duration = 0;
        this->chapters = new int [nb_chapters];
        for(int i=0; i<nb_chapters; i++){
            chapters[i] = _chapters[i];
            total_duration +=  chapters[i];
        }
        this->setDuration(total_duration);
    }

    ///Destructeur
    ~Film()
    {
        delete [] chapters;
        cout << "Chapters deleted" << endl;
    }

    ///setters
    void setChapters(int _nb_chapters, int * _chapters)
    {
        nb_chapters = _nb_chapters;
        int total_duration = 0;
        delete [] this->chapters;
        this->chapters = new int [_nb_chapters];
        for (int i=0; i< _nb_chapters; i++){
            chapters[i] = _chapters[i];
            total_duration +=  chapters[i];
        }
        this->setDuration(total_duration);
    };

    ///getters
    int getNbChapters() const { return nb_chapters;};
    const int * getChapters() const { return chapters;};

    void displayChapters() const
    {
        cout <<"Chapters displayed: ";
        for(int i=0; i<nb_chapters; i++){
            cout << chapters[i] << " ";
        }
        cout << endl;
    }

    ///Methodes d'affichage
    void printInfos(ostream& stream) const override
    {
        stream << "Name: " << this->getName() << '\n'
             << "Path: " << this->getPath()  << '\n'
             << "Duration: " << this->getDuration() << '\n'
             << "Nb Chapters: " << this->getNbChapters() << '\n'
             << "Chapters: " << this->getChapters() << '\n'
             << endl;
    };

};


#endif // FILM_H
