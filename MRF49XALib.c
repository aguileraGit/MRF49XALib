#include MRF49XALib.h
#include MRF49XADef.h


void MRF49XA::reset() {
    
    // 3.1.3 SOFTWARE RESET
    // The Software Reset is initiated using the host microcontroller. The 0xFE00 command triggers this Reset only if the Sensitive Reset
    // mode is enabled. The hardware automatically clears the bit(s) to their power-on state. The Software Reset command is the same as
    // POR, but the duration of the Reset event is much less than the actual POR (0.25 ms, typical).
}


void MRF49XA::initialize() {
    
    //Start SPI
    SPI.begin();
    
    //Config FIFO
    setFIFOregister();
    
    //Enable synchronous latch
    enableSynchronousLatch();
    
    //Program frequency band and crystal load capacitance
    enableFrequencyCrystal();
    
    //Enable AFC
    enableAFC();
    
    //Center Frequency
    setFrequencyCenter();
    
    //Set data rate
    setDataRate();
    
    //Enable TX RX
    enableTxRx();
    
    //Configure RX register
    setRxRegister();
    
    //Configure TX register
    setTxRegister();
    
    //Tune antenna
    setAntenna();
    
    //Turn off transmitter and turn on receiver
    enableTx(OFF);
    enableRx(ON);
    
    //Enable FIFO for data reception
    enableFIFO();
    
    //Configure FIFO
    setFIFO();
    
}



STATUS MRF49XA::enableTxRx() {
    
    
    uint16_t toWrite = ( PMCREG << 8) |
    // RXCEN: Receiver Chain Enable bit
    ( 1 << RXCEN_BIT ) |
    // BBCEN: Baseband Circuit Enable bit
    ( 1 << BBCEN_BIT ) |
    // TXCEN: Transmit Chain Enable bit
    ( 1 << TXCEN_BIT ) |
    // SYNEN: Synthesizer Enable bit
    ( 1 << SYNEN_BIT ) |
    // OSCEN: Crystal Oscillator Enable bit
    ( 1 << OSCEN_BIT ) |
    // LBDEN: Low Battery Detector Enable bit
    ( 0 << LBDEN_BIT ) |
    // WUTEN: Wake-up Timer Enable bit
    ( 0 << WUTEN_BIT ) |
    // CLKOEN: Clock Output Enable bit
    ( 0 << CLKOEN_BIT );
    
    writeBytes(toWrite);
    
    delay_ms(5);
    
}


STATUS MRF49XA::setDataRate() {
    
    //DREx (kbps) = 10000/[29 x (DRPV<6:0> + 1) x (1 + DRPE x 7)]
    //DREx (kbps) = 10000/[29 x ( 35 + 1) x (1 + 0 x 7)] = 9.5kHz
    
    uint16_t toWrite = ( DRSREG << 8 ) |
    //DRPE
    ( 0 << DRPE_BIT ) |
    //DRPV
    ( 0x23 << DRPV_BIT );
    
    writeBytes(toWrite);
}


STATUS MRF49XA::setFrequencyCenter() {
    
    // FVAL = Decimal Value of FREQB<11:0> = 96 < FVAL < 3903
    // FVAL = 2000 - Midpoint -> 0x7D0
    
    // F0 = 10 x FA1 x (FA0 + FVAL/4000) MHz, where FA0 = 43 & FA1 = 1
    // F0 = 10 x 1 x (43 + 2000/4000) = 435 MHz
    
    uint16_t toWrite = ( CFSREG << 8 ) |
    //FVAL Value
    ( 0x7D0 );
    
    writeBytes(toWrite);
    return SUCCESS;
    
}


STATUS MRF49XA::enableAFC() {

    uint16_t toWrite = ( AFCCREG << 8 ) |
    //Runs once after power-up cycle
    ( 0x01 << AUTOMS_BIT) |
    //High accuracy mode
    ( 1 << HAM_BIT );
    
    writeBytes(toWrite);
    
    return SUCCESS;
}


STATUS MRF49XA::enableFrequencyCrystal() {
    
    uint16_t toWrite = ( GENCREG << 8 ) |
    //Tx Data Register Enable bit
    ( 1 << TXDEN_BIT ) |
    //FIFO Enable bit
    ( 1 << FIFOEN_BIT ) |
    //Frequency Band Select bits
    ( FREQ434MHZ << FBSBIT) |
    //Load Capacitance Select bits
    ( LOADCAP16P << LCSBIT );
    
    writeBytes(toWrite);
    
    return SUCCESS;
}


STATUS MRF49XA::setFIFOregister() {
    
    uint16_t toWrite = (FIFORSTREG << 8 ) |
    //Num of bits before interrupt
    ( 0x03 << FFBC_BIT ) |
    //FIFO starts filling when it detects sync pattern
    ( 0 << FFSC_BIT ) |
    //FIFO continues to fill when it detects the sync pattern
    ( 0 << FSCF_BIT) |
    //Disables sensitive reset mode
    ( 1 << DRSTM_BIT);
    
    writeBytes(toWrite);
    return SUCCESS;
}


STATUS writeByte(uint16_t _toWrite) {
    
    // I'm not sure if I have to define SPI SELECT PIN
    
    //SPI started in MRF init
    uint8_t data[2];
    
    data[0] = _toWrite & 0xFF00;
    data[1] = (uint8_t)(_toWrite & 0x00FF);
    
    Serial.print(SPI data[0]: );
    Serial.println( data[0], HEX);
    Serial.print(SPI data[1]: );
    Serial.println( data[1], HEX);
    
    SPI.tranfer( data[0] );
    SPI.tranfer( data[1] );
    
}
