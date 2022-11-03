# Geometría Computacional

En varios concursos de programación, tales como el ICPC, los problemas de geometría computacional representan un gran desafío para todos los competidores, este tipo de problemas suelen ser de los menos solucionados a primera vista, esto debido al gran nivel de abstracción que debe tener un participante para construir una solución y la probabilidad de constituir una programación tediosa. Sin embargo, aquel programador que tenga muy bien dominados los principales tópicos puede hacer frente a estos problemas y avanzar en las competencias. A continuación se presentan los conceptos básicos para comenzar a introducirse con la *geometría computacional*.

### El punto y el vector

Un punto y un vector matemáticamente son dos elementos totalmente diferentes, un punto es un objeto sin anchura y altura que señala una posición precisa en el plano o espacio (dependiendo del tipo de problemas que se estén tratando). Sin embargo, para geometría computacional un punto es manipulado como si fuese un vector y viceversa, para realizar distintos análisis, esto último mencionado con los conceptos se utilizará de acuerdo a conveniencia del programador. 

En el código del presente repositorio, se puede observar que el punto y el vector podrían considerarse lo mismo.

```c++
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

```

Las operaciones +-*/ para puntos y vectores están definidas con sobrecarga de operadores en el mismo código del presente repositorio

### Rectas

Una recta está definida matemáticamente por un vector y un punto tal que a través del primero pueden conformarse infinitos puntos que se encuentren en la misma dirección y sentido (o contrariamente). Los segmentos nacen de las rectas estableciendo intervalos para que los puntos no sean infinitos y su construcción es la misma que tienen las rectas, respetando el intervalo claramente. Los problemas que existen van más ligados a la intersección de rectas e intervalos, lo cual computacionalmente se trata más de manera gráfica que de manera analítica.

En el código del presente repositorio para determinar esto último, se hará manejo claramente los conceptos de *producto escalar* y *producto vectorial*:

```c++
Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}

// P esta dentro del segmento AB
// 0.0
bool onSegment(const Point &A, const Point &B, const Point &P)
{
    return areaTriangulo(A, B, P) == 0 &&
           (P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x)) &&
           (P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y));
}

bool intersectsSegment(const Point &A, const Point &B, const Point &C, const Point &D)
{
    double A1 = area(C, A, D); // el segmento es CD y A es el punto
    double A2 = area(C, B, D); // el segmento es CD, y B es el punto
    double A3 = area(A, B, C); // el segmento es AB, y C es el punto
    double A4 = area(A, B, D); // el segmento es AB, y D es el punto

    if (((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) &&
        ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0)))
    {
        return true;
    }

    if (A1 == 0 && onSegment(C, D, A))
    {
        return true;
    }

    if (A2 == 0 && onSegment(C, D, B))
    {
        return true;
    }

    if (A3 == 0 && onSegment(A, B, C))
    {
        return true;
    }

    if (A4 == 0 && onSegment(A, B, D))
    {
        return true;
    }

    return false;
}
```

### Polígonos

Con los polígonos se tienen problemas como: Convexidad (Demostrar si un polígono es convexo o no), áreas (Área de un polígono), perímetros (Suma de distancias) y *Convex Hull* (El polígono convexo que abarque todo un conjunto de puntos). De la misma manera que las rectas y segmentos, se tienen de base el *producto escalar* y *producto vectorial (visto como el área de un paralelogramo)* 

```c++
double areaP(const Point &V, const Point &U)
{
    return abs(cross(V, U));
}

// Area de 3 puntos

double area(const Point &A, const Point &B, const Point &C)
{
    return cross(B - A, C - A); 
}

// Area de un triangulo
// Area formada por 3 puntos.
// Primero Crear el vector V = C-A y el vector U = B-A
// Por lo tanto puedo usar el cross product

double areaTriangulo(const Point &A, const Point &B, const Point &C)
{
    return abs(area(A, B, C)) / 2.;
}

//  Formula de heron

double areaHeron(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

bool isConvex(const vector<Point> &polign)
{
    int nroPoints = polign.size();           
    int areasPositive = 0, areasNegative = 0; 
    for (int i = 0; i < nroPoints; i++)
    {
        // Números circulares para evaluar un ciclo de puntos 
        double areaPoints = area(polign[i], polign[(i + 1) % nroPoints], polign[(i + 2) % nroPoints]);
        if (areaPoints > 0)
        {                   
            areasPositive++;
        }
        else if (areaPoints < 0)
        {
            areasNegative++;
        }
    }
    // Para una sola evaluación
    return areasPositive == 0 || areasNegative == 0;
}

bool pointInConvex(const vector<Point> &polign, const Point &P)
{
    int nroPoints = polign.size();
    int areasPositive = 0, areasNegative = 0;
    for (int i = 0; i < nroPoints; i++)
    {
        double areaPoints = area(P, polign[i], polign[(i + 1) % nroPoints]);
        if (areaPoints > 0)
        {
            areasPositive++;
        }
        else if (areaPoints < 0)
        {
            areasNegative++;
        }
    }
    return areasPositive == 0 || areasNegative == 0;
}
// Area de un Poligono

double areaPoligono(const vector<Point> &poligono)
{
    int nroPoints = poligono.size();
    double areaTotal = 0;
    for (int i = 1; i < nroPoints - 1; i++)
    {
        areaTotal += area(poligono[0], poligono[i], poligono[i + 1]);
    }
    return abs(areaTotal / 2);
}

// Convex Hull

vector<Point> convexHull(vector<Point> &points)
{
    sort(points.begin(), points.end()); // Ordenamos los puntos para encontrar el punto mas a la izquierda
    int k = 0;                          // k cuenta cuantos puntos tendra el convex hull
    Point hulls[points.size() + 100];   // Guardar los puntos del convex hull
    // Parte inferior
    for (int i = 0; i < points.size(); i++)
    {
        while (k >= 2 && area(hulls[k - 2], hulls[k - 1], points[i]) <= 0)
        {
            k--; // stack.pop();
        }
        hulls[k++] = points[i];
    }
    // Parte Superior
    for (int i = points.size() - 2, t = k; i >= 0; i--)
    {
        while (k > t && area(hulls[k - 2], hulls[k - 1], points[i]) <= 0)
        {
            k--;
        }
        hulls[k++] = points[i];
    }
    return vector<Point>(hulls, hulls + k - 1);
}
```
## Código Base

-[ElementosBasicos](https://github.com/AnderMichael/Algoritmica/blob/main/Geometria_Computacional/Elementos_Basicos.cpp)
-[OperacionesElementos](https://github.com/AnderMichael/Algoritmica/blob/main/Geometria_Computacional/Operaciones_Elementos.cpp)

## Problemas

- [Height_to_Area](https://github.com/AnderMichael/Algoritmica/blob/main/Geometria_Computacional/Problemas/HeightToArea.cpp)
- [Sunny_Mountains](https://github.com/meysamaghighi/UVa/blob/master/10522%20-%20Height%20to%20Area.cpp)

## Referencias
https://pierre.senellart.com/enseignement/2012-2013/acm_icpc/6-geometry.pdf
https://www.topcoder.com/thrive/articles/Geometry%20Concepts%20part%201:%20Basic%20Concepts
https://www.topcoder.com/thrive/articles/Geometry%20Concepts%20part%202:%20%20Line%20Intersection%20and%20its%20Applications

Competitive Programming 3: The New Lower Bound of Programming Contests, Volumen 3. Steven Halim (2013)
