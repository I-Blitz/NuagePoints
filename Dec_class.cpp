#include <iostream>
#include "def_class.hpp"

CloudOfPoints::CloudOfPoints()
    :points() // taille par défaut => 0
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

CloudOfPoints::CloudOfPoints(int N)
    :points(N) // on alloue de l'espace pour N points
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

CloudOfPoints::CloudOfPoints(const CloudOfPoints& Nuage)
    :points{Nuage.points} // On copie les points du Nuage en entrée
    {  
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

CloudOfPoints::CloudOfPoints(const std::initializer_list<point>& init_p)
    :points{init_p}
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }


CloudOfPoints::~CloudOfPoints(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void CloudOfPoints::afficher() const{
    for (unsigned int i=0; i < this->points.size(); ++i){
        std::cout << "x" << i << " = " << this->points[i][0] << std::endl;
        std::cout << "y" << i << " = " << this->points[i][1] << std::endl;
    }
}

void CloudOfPoints::setpoint(point p,int n){ // on change le n-eme point par un point p
    if (n>= 0 && n <= this->points.size()){
        this->points[n] = p;
    }
}

CloudOfPoints::CloudOfPoints(int n1, int n2, const CloudOfPoints& Nuage )
    {
        this->points.resize(n2-n1+1);
        for (unsigned int i =0; i< this->points.size() ; ++i){
            this->points[i] = Nuage.points[n1+i] ;
        }
    }


int CloudOfPoints::taille(){ 
    return(this->points.size());
}


point CloudOfPoints::barycentre(){
    point p{0,0};
    for (int i=0; i< this->points.size() ; ++i){
        p[0] += this->points[i][0];
        p[1] += this->points[i][1];
    }
    p[0] = p[0]/this->points.size();
    p[1] = p[1]/this->points.size();
    return p;
}