// Reto 1

#include <stdio.h>
#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth, float angle, float factor) {
    if(depth == 0 || length < 5)
        return;

    turtleForward(turtle, length);

    turtleLeft(turtle, angle);
    fractalTree(turtle, length * factor, depth - 1, angle, factor);
    
    turtleRight(turtle, angle);
    fractalTree(turtle, length * factor, depth - 1, angle, factor);
    
    turtleRight(turtle, angle);
    fractalTree(turtle, length * factor, depth - 1, angle, factor);

    turtleLeft(turtle, angle);
    turtleBackward(turtle, length);
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

    TurtleApp *app = turtleAppCreate(800, 800, "Three-branch Fractal Tree 3");

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

