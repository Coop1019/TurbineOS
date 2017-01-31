#include <iostream>
#include <cmath>

#define BLADERADIUS .225
#define PI 3.14159265358979

using namespace std;

double windSpeed, RPM, powerInAir, TSMS, TSR, W, ef, pitch, resistance, opTSR;
int featherNOW;

void calculatePowerInWind(){
    powerInAir = .5*1.2*(PI*BLADERADIUS*BLADERADIUS)*windSpeed*windSpeed;
}

void calculateTSR(){
    TSMS = PI*BLADERADIUS*RPM/30;
    TSR = TSMS/windSpeed;
}

void calculateBladePitch(){
    if (featherNOW == 0) {
        pitch = windSpeed;
    }
    else {
        pitch = -1;
    }
}

void calculateResistance(){
    if (TSR<opTSR){
        if (resistance>1){
            resistance=resistance-1;
        }
    }
    else if (TSR>opTSR){
        resistance = resistance + 1;
    }
    else {
        resistance = 0;
    }
}

void calculateEfficiency(){
    ef = windSpeed/powerInAir;
}

void debug(){
    cout << "windSpeed: " << windSpeed << endl;
    cout << "RPM: " << RPM << endl;
    cout << "powerInAir: " << powerInAir << endl;
    cout << "TSMS: " << TSMS << endl;
    cout << "TSR: " << TSR << endl;
    cout << "W: " << W << endl;
    cout << "ef: " << ef << endl;
    cout << "pitch: " << pitch << endl;
    cout << "resistance: " << resistance << endl;
    cout << "opTSR: " << opTSR << endl;
    cout << "featherNow: " << featherNOW << endl;
}

void getAllThoseImportantVariablesDude(double datWindSpeed, double datRPM, double datW){
    windSpeed = datWindSpeed;
    RPM= datRPM;
    W = datW;
}
int main() {


    std::cout << "Hello, World!" << std::endl;
    return 0;
}