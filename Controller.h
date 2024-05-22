#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
private:
    /* data */
public:
    Controller(/* args */);
    virtual int steer() = 0;
    ~Controller();
};

#endif