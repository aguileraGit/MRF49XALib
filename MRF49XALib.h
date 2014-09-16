#include "Arduino.h"
#include <WProgram.h>
#include "MRF49XADef.h"

#ifndef MRF49XALib_h
#define MRF49XALib_h

class MRF49XA {
    
    public:
        void reset();
        void initialize();
        STATUS enableTxRx();
        STATUS setDataRate();
        STATUS setFrequencyCenter();
        STATUS enableAFC();
        STATUS enableFrequencyCrystal();
        STATUS setFIFOregister();
        
        //Write to registers
        STATUS writeByte(uint16_t _toWrite);
        
    private:
        
    
};





#endif