# A.W.G.N. Additive White Gaussian Noise

Very basic noise generator that you can use for your signal processing (and many other) projects, it very simple and straightfoward to use.  

# Dependencies 
C++ STL (not really a dependancy but you know...)

# HOWTO
You specify mean and variance, 

``` AWGN noiseObject(mean,variance,numberOfSamples); ```

Or your can just use a SNR (signal to noise ratio) value (signal is assumed to be normalized!), 

``` AWGN noiseObject(SNR,numberOfSamples);```

Noise samples are dynamically allocated so don't forget to deallocate them to avoid memory leaks.

``` noiseObject.deallocate(); ```

# Just compile for an example 
``` g++ main.cpp -o example ```

# Then, just run
``` ./example ```

# TODO
- Thread safe coding (maybe)
- Singal processing application examples 
- Many other things that I don't remember right now :)

# License
MIT 
