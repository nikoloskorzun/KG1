#pragma once

#include "light_source.h"



using namespace std;
Light_source::Light_source(const Light_source& polygone_copy)
{
	this->c = polygone_copy.c;
	this->z = polygone_copy.z;

	this->l = polygone_copy.l;



}



Light_source::Light_source()
{
	this->z = NULL;


	this->c.r = 255;
	this->c.g = 255;
	this->c.b = 255;
	this->c.a = 255;

}


Light_source& Light_source::operator=(const Light_source& right)
{

	if (this == &right) {
		return *this;
	}
	this->c = right.c;
	this->z = right.z;

	this->l = right.l;

	return *this;

}


Light_source::~Light_source()
{
	

}




void Light_source::set_z()
{
	this->z = this->l[0][2];
}



void Light_source::set_ñolor(Color ñolor_)
{
	

	this->c.r = 255;
	this->c.g = 255;
	this->c.b = 255;
	this->c.a = 255;
}

Color Light_source::get_ñolor()
{
	return this->c;

}


void Light_source::draw(SDL_Renderer* ren)
{
	SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);
	SDL_RenderDrawPoint(ren, this->l[0][0], this->l[0][1]);

	//cout << this->l[0][0] << " " << this->l[0][1] << endl;

}


void Light_source::associate(double** l_source)
{
	this->l = l_source;

}


