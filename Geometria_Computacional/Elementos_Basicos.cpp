#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
// Vector = Point Pero Vector = B - A
// Vector A
// A = Point(4,5);

// Los conceptos de vector y punto se manejarán de acuerdo a nuestra conveniencia.

struct Point
{
    double x, y;

    Point(double a, double b)
    {
        x = a;
        y = b;
    }

    double angle()
    {
        return atan2(y, x);
    }

    double mod()
    {
        return sqrt(x * x + y * y);
    }

    Point unit()
    {
        double modulo = mod();
        return Point(x / modulo, y / modulo);
    }
};

// Para configurar los criterios de las operaciones +-*/ (Sobrecarga de operadores)

// Point A, Point B
// Point C(A.x+B.x, A.y+B.y);
// Point C = A + B;
Point operator+(const Point &a, const Point &b)
{
    return Point(a.x + b.x, a.y + b.y);
}

Point operator-(const Point &a, const Point &b)
{
    return Point(a.x - b.x, a.y - b.y);
}

Point operator*(const Point &a, double k)
{
    return Point(a.x * k, a.y * k);
}

Point operator/(const Point &a, double k)
{
    return Point(a.x / k, a.y / k);
}

// Sort Ordernar puntos
bool operator<(const Point &a, const Point &b)
{
    if (a.x != b.x)
    {
        return a.x < b.x;
    }
    else
    {
        return a.y < b.y;
    }
}
// Sobrecarga del Operador Print
ostream &operator<<(ostream &os, Point p)
{
    return os << "Este es el Punto ===>(" << p.x << "," << p.y << ")";
}

// Operaciones entre elementos básicos: Vectores y puntos.

// Funciones Basicas
// Distancia de dos puntos // sqrt(B.x-A.x + B.y-A.y)
// http://www.cplusplus.com/reference/cmath/hypot/
double dist(const Point &A, const Point &B)
{
    return hypot(A.x - B.x, A.y - B.y); // sqrt((a.x-b.x)^2, (a.y-b.y)^2)
}

// Producto Escalar
// A y B son vectores
// si el producto es 0 son perpendiculares
double dot(const Point &A, const Point &B)
{
    return A.x * B.x + A.y * B.y;
}

// Product Cross or producto Vectorial (Area de un paralelogramo)
// En realidad, la función representa únicamente el tercer componente del producto vectorial matemático (0,0,V.x * U.y - V.y * U.x)
// V y U son vectores
// si el producto es 0 son paralelos
double cross(const Point &V, const Point &U)
{
    return V.x * U.y - V.y * U.x;
}

// PRUEBA DE OPERACIONES

int main()
{
    input;
    int n;
    vector<Point> poligono;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        poligono.push_back(Point(x, y));
    }
    for (int i = 0; i < n; i++)
    {
        cout << poligono[i] << endl;
    }
    cout << dist(poligono[0], poligono[1]) << endl;
    cout << cross(poligono[0], poligono[1]) << endl;
    cout << dot(poligono[0], poligono[1]) << endl;
    sort(poligono.begin(), poligono.end());
    for (int i = 0; i < n; i++)
    {
        cout << poligono[i] << endl;
    }
    return 0;
}
