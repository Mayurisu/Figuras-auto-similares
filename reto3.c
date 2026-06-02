//Reto 3: Modifique el arbol fractal para que el color dependa de la profundidad.

#include <stdio.h>
#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth, float angle, float factor) {
    if(depth == 0 || length < 5)
        return;

    uint8_t r = (depth * 50) % 256;  
    uint8_t g = (depth * 30) % 256;
    uint8_t b = (depth * 20) % 256; 
    turtleSetColor(turtle, r, g, b);

    turtleForward(turtle, length);

    turtleLeft(turtle, angle);
    fractalTree(turtle, length * factor, depth - 1, angle, factor);

    turtleRight(turtle, 2 * angle);
    fractalTree(turtle, length * factor, depth - 1, angle, factor);

    turtleLeft(turtle, angle);
    turtlePenUp(turtle);
    turtleBackward(turtle, length);
    turtlePenDown(turtle);
}

int main(void) {
    float length, angle, factor;
    int depth;

    printf("Ingresar longitud inicial: ");
    scanf("%f", &length);

    printf("Ingresar profundidad: ");
    scanf("%d", &depth);

    printf("Ingresar angulo: ");
    scanf("%f", &angle);

    printf("Ingresar factor de reduccion: ");
    scanf("%f", &factor);

    TurtleApp *app = turtleAppCreate(800, 800, "Fractal Tree Variaciones");

    if(app == NULL)
        return 1;

    Turtle *t = turtleAppGetTurtle(app);

    turtlePenUp(t);
    turtleGoTo(t, 400, 750);
    turtlePenDown(t);

    turtleLeft(t, 90.0);
    fractalTree(t, length, depth, angle, factor);

    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
}
