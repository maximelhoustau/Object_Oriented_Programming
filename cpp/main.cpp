//
// main.cpp
// Created on 21/10/2018
//
//\author Maxime Lhoustau

#include "multimediaobject.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "groupe.h"

int main(int argc, const char* argv[])
{
    int * tab = new int [5] {1,1,1,1,1};
    int * duration = new int [3] {3,3,4};
    int * duration2 = new int [4] {3,3,4,2};

    Film * film1 = new Film("Film1", "./videos/1.mp4", 10, 3, duration);
    Film * film2 = new Film("Film2", "./videos/2.mp4", 12, 4, duration2);
    Film * film3 = new Film("Film3", "./videos/3.mp4", 5, 5, tab);
    Photo * photo1 = new Photo("Photo1","./photos/1.jpg",0,0);
    Photo * photo2 = new Photo("Photo2","./photos/2.jpg",1,1);
    Photo * photo3 = new Photo("Photo3","./photos/3.jpg",2,2);
    Video * video1 = new Video("Video1", "./videos/1.mp4", 10);
    Video * video2 = new Video("Video2", "./videos/2.mp4", 12);
    Video * video3 = new Video("Video3", "./videos/3.mp4", 5);

    MultimediaObject * objets1 = {film1,photo1,video1};
    Groupe grp1 = new Groupe(objets1, 3, "Objets 1");
    grp1.printInfos(cout);

    return 0;
}
