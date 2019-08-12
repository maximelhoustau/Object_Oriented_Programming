#ifndef PHOTO_H
#define PHOTO_H

class Photo : public MultimediaObject
{
private:
    int latitude = 0;
    int longitude = 0;
public:
    ///Constructeurs
    Photo() : MultimediaObject(), latitude(0), longitude(0) {}
    Photo(string _name, string _path, int _latitude, int _longitude) : MultimediaObject(_name, _path), latitude(_latitude), longitude(_longitude) {}

    ///setters
    void setLatitude(int _latitude) { latitude = _latitude;};
    void setLongitude(int _longitude) { longitude = _longitude;};

    ///getters
    int getLatitude() const { return latitude;};
    int getLongitude() const { return longitude;};

    ///Methode d'affichage
    void printInfos(ostream& stream) const override
    {
        stream << "Name: " << this->getName() << '\n'
             << "Path: " << this->getPath()  << '\n'
             << "Latitude: " << this->getLatitude() << '\n'
             << "Longitude: " << this->getLongitude()
             << endl;
    };

    void play() const override
    {
        //Environnement mac
        string arg_sys = "java -jar -Xmx1024m /Applications/ImageJ/ImageJ.app/Contents/Java/ij.jar "+this->getPath()+ " &";
        //Environnement linux
        //string arg_sys = "imagej "+this->getPath()+ " &";
        system(arg_sys.c_str());
    };
};

#endif // PHOTO_H
