//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

//velocity
#define VELOCITY 4
// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    // initiate the ball velocity x and y 
    double rand_val = drand48();
    while(rand_val<.3 || rand_val>.5)
        rand_val = drand48();
    double velx = rand_val*VELOCITY;
    double vely = (1-rand_val)*VELOCITY;
    

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // TODO

        //move the paddle with mouse
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);
        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure paddle follows top cursor
                double x = getX(event) ;
                if (x> WIDTH - getWidth(paddle))
                    x = WIDTH - getWidth(paddle);
                //double y = getY(event) - getWidth(circle);
                setLocation(paddle, x, 7*HEIGHT/8 );
            }
        }
        //####################################################    
        //Move the ball
        
        move(ball, velx, vely);                
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            velx = -velx;
        }

        // bounce off left edge of window
        else if (getX(ball) <= 0)
        {
            velx = -velx;
        }

        if (getY(ball) + getWidth(ball) >= getHeight(window))
        {
            lives = lives-1;
            //removeGWindow(window, ball);
            waitForClick();
            setLocation(ball, WIDTH/2-RADIUS/2,HEIGHT/2-RADIUS/2);
            
        }

        // bounce off left edge of window
        else if (getY(ball) <= 0)
        {
            vely = -vely;
        }
        // linger before moving again
        pause(10);
        //####################################################
        
        // Detect collisions
        
        GObject obj = detectCollision(window, ball);
        if (obj != label && obj!=NULL){
            if ( obj == paddle){
                vely = -vely;
                pause(20);
            }
            
            if (strcmp(getType(obj), "GRect") == 0 && obj != paddle && obj != label ){
                bricks = bricks -1;
                removeGWindow(window, obj);
                vely = -vely;
                pause(10);
                updateScoreboard(window, label, 50- bricks);
            }
        }
     
        
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO
    double brickWidth = WIDTH/COLS;
    double brickHeight = WIDTH/COLS/2;
    string colors[5];
    colors[0] = "RED";
    colors[1] = "ORANGE";
    colors[2] = "GREEN";
    colors[3] = "YELLOW";
    colors[4] = "CYAN";
    
    for (int i=0; i < COLS ; i++)
    {
        for (int j=0; j < ROWS ; j++)
        {
            GRect rect = newGRect(5+i*brickWidth,5+j*brickHeight,brickWidth-7.5, brickHeight-5);
            setColor(rect, colors[(j+i)%5]);
            setFilled(rect, true);
            add(window, rect);
        }
    }
    
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    GOval ball = newGOval(WIDTH/2-RADIUS,HEIGHT/2-RADIUS, 2*RADIUS, 2*RADIUS);
    setColor(ball,"BLUE");
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    double paddleWidth = WIDTH/5;
    double paddleHeight = 4;
    double paddlex = WIDTH/2-paddleWidth/2;
    double paddley = 7*HEIGHT/8;
    GRect paddle = newGRect(paddlex, paddley, paddleWidth , paddleHeight);
    setColor(paddle,"BLACK");
    setFilled(paddle, true);
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    GLabel label = newGLabel("");
    setFont(label, "SansSerif-36");
    add(window, label);
    setLabel(label, "0");
    double x = (WIDTH - getWidth(label)) / 2;
    double y = (HEIGHT - getHeight(label)) / 2;
    setLocation(label, x, y);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
