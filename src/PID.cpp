#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    cur_time = std::clock();
    pre_time = std::clock();
}

void PID::UpdateError(double cte) {
    cur_time = std::clock();
    double dt = 1.0*(cur_time - pre_time)/CLOCKS_PER_SEC;
    std::cout << "dt= " << dt << " : " << cur_time << "-" << pre_time << std::endl;

    if (fabs(dt) < 0.000001){
        d_error = 0.0;
    }else{
        d_error = (cte - p_error) / dt;
    }
    pre_time = cur_time;
    i_error +=cte;
    p_error = cte;
}

double PID::TotalError() {
    return -(Kp * p_error + Kd * d_error + Ki * i_error);
}


