#ifndef GROUPE_H
#define GROUPE_H
#include <list>
#include <string>
#include "film.h"
#include "photo.h"

using namespace std;


class Groupe : public list<MultimediaObject>
{
private:
	int size_grp = 0;
	string grp_name = "Default";
	list<MultimediaObject> grp_member;

public:
	///Constructeur
	Groupe(MultimediaObject * _grp_member, int _size_grp, string _grp_name) {
		this->grp_name = _grp_name;
		this->grp_member = new list<MultimediaObject>;
		for (int i=0; i<_size_grp; i++){
			grp_member.push_back(_grp_member[i]);
		}
	}

	///Accesseur
	string getGrpName() const {
		return this->grp_name;
	}

	///Methode d'affichage
	void printInfos(ostream& stream) const {
		list<MultimediaObject> copy = grp_member;
		for (int i=0; i<size_grp; i++){
			copy.front().printInfos(stream);
			copy.pop_front();
		}
		delete copy;
	}

};

#endif
