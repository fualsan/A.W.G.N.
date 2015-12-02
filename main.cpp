#include "AWGN.h"

int main(int argc, const char * argv[]) {
    
    long samples = 10;

    AWGN g(0.0,1.0,samples);
    double * sampleArray = g.generateNoiseSamples();
    
    for (int j=0; j < samples; j++) {
      
        std::cout << sampleArray[j] << std::endl;
    }
    
    g.deallocate();
    
    AWGN t(20.0,samples);
    
    double * sampleArray2 = t.generateNoiseSamples();
    
    
    for (int i = 0; i < samples; i++) {
        std::cout << "SNR array: " << sampleArray2[i] << std::endl;
    }
    
    t.deallocate();
    
    
    return 0;
}
