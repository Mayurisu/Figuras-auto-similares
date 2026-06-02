#include <stdio.h>
#include <math.h>
#include "turtlec.h"

void levy(Turtle* turtle, float length, int depth) {
    if(depth == 0) {
        turtleForward(turtle, length);
        return;
    }

    turtleLeft(turtle, 45);
    levy(turtle, length / sqrt(2), depth - 1);

    turtleRight(turtle, 90);
    levy(turtle, length / sqrt(2), depth - 1);

    turtleLeft(turtle, 45);
}

int main(void){
    float length;
    int depth;

    printf("ingresar longitud inicial: ");
    scanf("%f", &length);

    printf("Ingresa profundidad: ");
    scanf("%d", &depth);

    TurtleApp *app = turtleAppCreate(700, 600, "curva de Levy C");

    if(app == NULL)
        return 1;

    Turtle *t = turtleAppGetTurtle(app);

    turtlePenUp(t);
    turtleGoTo(t, 220, 500);
    turtlePenDown(t);

    //turtleLeft(t, 90);
    levy(t, length, depth);
  
    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
} 
