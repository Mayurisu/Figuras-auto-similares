//Reto 2: Modifique el árbol fractal para que la rama izquierda y la rama derecha tengan tamaños diferentes.

#include <stdio.h>
#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth, float angle, float factorIzq, float factorDer) {
    if(depth == 0 || length < 5)
        return;

    if(depth > 5)
        turtleSetColor(turtle, 120, 70, 20);
    else
        turtleSetColor(turtle, 0, 200, 0);
    
    turtleForward(turtle, length);

    turtleLeft(turtle, angle);
    fractalTree(turtle, length * factorIzq, depth - 1, angle, factorIzq, factorDer);

    turtleRight(turtle, 2 * angle);
    fractalTree(turtle, length * factorDer, depth - 1, angle, factorIzq, factorDer);

    turtleLeft(turtle, angle);
    turtlePenUp(turtle);
    turtleBackward(turtle, length);
    turtlePenDown(turtle);
}

int main(void) {
    float length, angle, factorIzq, factorDer;
    int depth;

    printf("Ingresar longitud inicial: ");
    scanf("%f", &length);

    printf("Ingresar profundidad: ");
    scanf("%d", &depth);

    printf("Ingresar angulo: ");
    scanf("%f", &angle);

    printf("Ingresar factor de reduccion izquierdo: ");
    scanf("%f", &factorIzq);

    printf("Ingresar factor de reduccion derecho: ");
    scanf("%f", &factorDer);

    TurtleApp *app = turtleAppCreate(800, 800, "Fractal Tree Variaciones");

    if(app == NULL)
        return 1;

    Turtle *t = turtleAppGetTurtle(app);

    turtlePenUp(t);
    turtleGoTo(t, 400, 750);
    turtlePenDown(t);

    turtleLeft(t, 90.0);
    fractalTree(t, length, depth, angle, factorIzq, factorDer);

    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
}
