#pragma once
#include <iostream>

#include <SDL.h>

#include "template_functions.h"
#include "base_polygone.h"


using namespace std;

//����� ������ (������� ����� ���������) �����

class Shadow_polygone : public Base_polygone
    //������� ������� - ��� ������������� ���� ����������� �� ����� ���� 4-� � 5-�� ��������
    //������ �������� ��������� � ������� �������� ���������� �� ������ �������� ��������� ���������. ����� �� �� ������ ��������� �� ���������� � ����� ������ ����������, ��������� ��� �������� �����.
{
public:


    Shadow_polygone(const Shadow_polygone& polygone_copy);



    Shadow_polygone();

    Shadow_polygone& operator=(const Shadow_polygone& right);

    ~Shadow_polygone();

    virtual void set_z() override;

    virtual void set_�olor(Color �olor_) override;
    virtual Color get_�olor() override;

    void set_vertexes(size_t count, double** v);


    virtual void draw(SDL_Renderer* ren) override;

private:


    
    size_t count_of_vertex;

    double **coords;//5*3 always - bad code




};




