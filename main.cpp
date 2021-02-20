#include <iostream>
#include "def_class.hpp"

int main(){

    std::cout << "version 4 du nuage de points" << std::endl;
    point p{2.0/3,-3.5};
    CloudOfPoints nuage{3};
    CloudOfPoints nuage3;

    std::cout << "nuage avant modification" << std::endl;
    nuage.afficher();

    std::cout << "nuage apres modification" << std::endl;
    nuage.setpoint(p,1);
    nuage.afficher();

    std::cout << "nuage2 cree par copie" << std::endl;
    CloudOfPoints nuage2{nuage};
    nuage2.afficher();

    std::cout << "nuage copie partielle" << std::endl;
    CloudOfPoints nuage4{0,1,nuage};
    nuage4.afficher();

    std::cout << "création par liste d'init" << std::endl;
    CloudOfPoints nuage5{ point{1.25,-1.0}, point{3.14,-2.0} };
    nuage5.afficher();

    point bar = nuage.barycentre();
    std::cout << "le nuage est compose de : " << nuage.taille() << " points et a pour barycentre : \n" << "x = " << bar[0] 
                << "\ny = " << bar[1]  << std::endl;
    return 0;
}