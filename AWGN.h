#ifndef AWGN_h
#define AWGN_h
#endif /* AWGN_h */

#include <iostream>
#include <random>
#include <vector>
//#define DEBUG_MODE // debug mode on/off (comment this to disable debug mode)

class AWGN {
    
public:
    AWGN(); // Default constructor
    AWGN(double mean, double variance, long numberOfSamples); // Constructor with initializers
    AWGN(double SNR, long numberOfSamples); // Constructor with initializers (SNR)
    
    double * generateNoiseSamples();
    void deallocate();
    
private:
    double mean;
    double variance;
    long numberOfSamples;
    double sigma;
    bool isSNRMode;
    
};

AWGN::AWGN (){
    // default values are assigned
    this->mean = 0.0;
    this->variance = 1.0;
    this->numberOfSamples = 100;
    this->isSNRMode = false;
#ifdef DEBUG_MODE
    std::cout << "AWGN is initialized with default constructor!" << std::endl;
#endif
    
    std::cerr << "WARNING!, using default initializer is potentially dangerous, default parameters values are used!" << std::endl;
}

AWGN::AWGN (double mean, double variance, long numberOfSamples){
    this->mean = mean;
    this->variance = variance;
    this->numberOfSamples = numberOfSamples;
    this->isSNRMode = false;
#ifdef DEBUG_MODE
    std::cout << "AWGN is initialized with initializer constructor" << std::endl;
#endif
}

AWGN::AWGN (double SNR, long numberOfSamples){
    this->mean = 0.0;
    this->variance = 1.0;
    this->numberOfSamples = numberOfSamples;
    this->sigma = sqrt(pow(10,(-SNR/10)));
    this->isSNRMode = true;
#ifdef DEBUG_MODE
    std::cout << "AWGN is initialized with SNR initializer constructor" << std::endl;
#endif
    std::cout << "WARNING! singal power is assumed to be normalized" << std::endl;
    
}

double *AWGN::generateNoiseSamples(){
    
    std::default_random_engine defaultGeneratorEngine;
    std::normal_distribution<double> normalDistribution(this->mean,this->variance);
    
    // Dynamically allocate noise samples
    double *samples = new double[this->numberOfSamples];
    
    if (this->isSNRMode) {
        // calculate with mean and variance
        for (int i = 0; i<this->numberOfSamples; i++) {
            samples[i] = (this->sigma) * normalDistribution(defaultGeneratorEngine);
        }
        
    } else {
        // calculate with SNR
        for (int i = 0; i<this->numberOfSamples; i++) {
            samples[i] = normalDistribution(defaultGeneratorEngine);
        }
        
    }
    
    return samples;
    
#ifdef DEBUG_MODE
    std::cout << "noise samples are generated!" << std::endl;
#endif
    
}

void AWGN::deallocate(){
    // Deallocate dynamically allocated noise samples
    delete [] this->generateNoiseSamples();
    
#ifdef DEBUG_MODE
    std::cout << "noise samples are deallocated!" << std::endl;
#endif
    
}