#include "multimediaobject.h"

MultimediaObject::MultimediaObject() {
    name = "Default";
    path = "./";
}

MultimediaObject::MultimediaObject(string _name, string _path)
{
    name = _name;
    path = _path;
}

void MultimediaObject::setName(string _name)
{
    name = _name;
}

void MultimediaObject::setPath(string _path)
{
    path = _path;
}

string MultimediaObject::getName() const
{
    return name;
}

string MultimediaObject::getPath() const
{
    return path;
}

void MultimediaObject::printInfos(ostream& stream) const
{
    stream << "Name: " << this->getName() << '\n'
         << "Path: " << this->getPath()
         << endl;
}
