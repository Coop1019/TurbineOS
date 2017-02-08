#include <iostream>
#include <cmath>

#define BLADERADIUS .225
#define PI 3.14159265358979

using namespace std;

double windSpeed, RPM, powerInAir, TSMS, TSR, W, ef, pitch, resistance = 0.5, opTSR=6;
int featherNOW;

void calculatePowerInWind(){
    powerInAir = .5*1.2*(PI*BLADERADIUS*BLADERADIUS)*windSpeed*windSpeed*windSpeed;
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
        pitch = 0.1;
    }
}

void calculateResistance(){
    if (TSR<opTSR){
        if (resistance>0.005){
            if (opTSR-TSR<0.1){
                resistance=resistance-0.001;
            }
            else { resistance=resistance-0.01;}
        }
    }
    else if ((TSR>opTSR)){
        if (TSR-opTSR<0.1){
            resistance=resistance+0.001;
        }
        else {resistance = resistance + 0.005;}
    }
    if (featherNOW==1){
        resistance=1;
    }

}

void calculateEfficiency(){
    ef = windSpeed/powerInAir;
}

void debug(){
    cout << "windSpeed: " << windSpeed << endl;
    cout << "RPM: " << RPM << endl;
    cout << "powerInAir: " << powerInAir << endl;
    //cout << "TSMS: " << TSMS << endl;
    cout << "TSR: " << TSR << endl;
    cout << "W: " << W << endl;
    //cout << "ef: " << ef << endl;
    cout << "pitch: " << pitch << endl;
    cout << "resistance: " << resistance << endl;
    cout << "--------" << endl;
    //cout << "opTSR: " << opTSR << endl;
    //cout << "featherNow: " << featherNOW << endl;
}

void getAllThoseImportantVariablesDude(double datWindSpeed){
    windSpeed = datWindSpeed;
    double solidity = 45/pitch;
    double effFactor = 0.5;
    double bladeConst = 10;
    RPM= powerInAir/solidity/effFactor/resistance*bladeConst;

    // @0rpm 0I @ 100rpm 1.5I @ 2000rpm 35I
    // y=ax^2+bx
    //a=1.3157895*10^-6
    //b=.0148684211

    double Iamps = (.0000013157895*RPM*RPM);
    W = Iamps*Iamps*resistance;
}

void turbineLoop(double windSpeedX){
    getAllThoseImportantVariablesDude(windSpeedX);
    calculatePowerInWind();
    calculateTSR();
    calculateBladePitch();
    calculateResistance();
    calculateEfficiency();
    debug();
    cin >> featherNOW;
}
int main() {
    for (double datWinSpd = 10; datWinSpd < 11; datWinSpd){
        turbineLoop(datWinSpd);
        turbineLoop(datWinSpd);
        turbineLoop(datWinSpd);
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}