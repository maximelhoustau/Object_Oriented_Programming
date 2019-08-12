#ifndef VIDEO_H
#define VIDEO_H
#include "multimediaobject.h"

class Video : public MultimediaObject
{
private:
    int duration = 0;
public:
    ///Constructeurs
    Video() : MultimediaObject(), duration(0) {}
    Video(string _name, string _path, int _duration) : MultimediaObject(_name, _path), duration(_duration) {}

    ///setters
    virtual void setDuration(int _duration) { duration = _duration;};

    ///getters
    int getDuration() const { return duration;};

    ///Methode d'affichage
    void printInfos(ostream& stream) const override
    {
        stream << "Name: " << this->getName() << '\n'
             << "Path: " << this->getPath()  << '\n'
             << "Duration: " << this->getDuration()
             << endl;
    };

    void play() const override
    {
        string arg_sys = "mpv "+this->getPath()+ " &";
        system(arg_sys.c_str());
    };
};

#endif // VIDEO_H
