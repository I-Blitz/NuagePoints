#include <iostream>
#include <array>
#include <vector>

using point = std::array<double,2>;

class CloudOfPoints{
    public:
        CloudOfPoints();
        CloudOfPoints(int N);
        CloudOfPoints(const CloudOfPoints& Nuage);
        CloudOfPoints(int n1, int n2, const CloudOfPoints& Nuage );
        CloudOfPoints(const std::initializer_list<point>& init_p);
        ~CloudOfPoints();
        void afficher() const;
        void setpoint(point p,int n);
        int taille(); // taille du nuage de points
        point barycentre(); // coordonnées du barycentre
    private:
        std::vector<point> points; 

};

