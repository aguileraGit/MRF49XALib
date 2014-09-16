#define OFF         0
#define ON          1

#define TIMEOUT     10

#define SUCCESS     0
#define FAIL        1

#define FREQ434MHZ  0x01
#define FREQ868MHZ  0x02
#define FREQ915MHZ  0x03

#define LOADCAP8_5PF        0x00
#define LOADCAP9_0PF        0x01
#define LOADCAP9_5PF        0x02
#define LOADCAP10PF         0x03
#define LOADCAP10_5PF       0x04
#define LOADCAP11PF         0x05
#define LOADCAP11_5PF       0x06
#define LOADCAP12PF         0x07
#define LOADCAP12_5PF       0x08
#define LOADCAP13PF         0x09
#define LOADCAP13_5PF       0x0A
#define LOADCAP14PF         0x0B
#define LOADCAP14_5PF       0x0C
#define LOADCAP15PF         0x0D
#define LOADCAP15_5PF       0x0E
#define LOADCAP16PF         0x0F

#define SPI_SELECT_PIN      10


//Registers
//#define STSREG                0x01

//#define GENCREG               0x02
#define GENCREG                 0x80

//#define AFCCREG               0x03
#define AFCCREG                 0xC4

//#define TXCREG                0x04
//#define TXBREG                0x05

//#define CFSREG                0x06
#define CFSREG                  0x0A

//#define RXCREG                0x07
//#define BBFCREG               0x08
//#define RXFIFOREG             0x09

//#define FIFORSTREG            0x0A
#define FIFORSTREG              0xCA

#define RegSYNBREG              0x0B

//#define DRSREG                0x0C
#define DRSREG                  0xC6

//#define PMCREG                0x0D
#define PMCREG                  0x82

//#define WTSREG                0x0E

//#define DCSREG                0x0F
//#define BCSREG                0x10
//#define PLLCREG               0x11

//STSREG Bit number and length
#define TXRXFIFO_BIT          15
#define POR_BIT               14
#define TXOWRXOF_BIT          13
#define WUTINT_BIT            12
#define LCEXINT_BIT           11
#define LBTD_BIT              10
#define FIFOEM_BIT            9
#define ATRSSI_BIT            8
#define DQDO_BIT              7
#define CLKRL_BIT             6
#define AFCCT_BIT             5
#define OFFSV_BIT             4
#define OFFSB_BIT             3

//GENCREG Bit number and length
#define TXDEN_BIT             7
#define FIFOEN_BIT            6
#define FBS_BIT               5
#define LCS_BIT               3

//AFCCREG Bit number and length
#define AUTOMS_BIT            7
#define ARFO_BIT              5
#define MFCS_BIT              3
#define HAM_BIT               2
#define FOREN_BIT             1

//TXCREG Bit number and length
#define MODPLY_BIT            8
#define MODBW_BIT             7
#define OTXPWR_BIT            2

//TXBREG Bit number and length
#define TXDB_BIT              7

//CFSREG Bit number and length
#define FREQB_BIT             11

//RXCREG Bit number and length
#define FINTDIO_BIT           10
#define DIORT_BIT             9
#define RXBW_BIT              7
#define RXLNA_BIT             4
#define DRSSIT_BIT            2

//BBFCREG Bit number and length
#define ACRLC_BIT             7
#define MCRLC_BIT             6
#define FTYPE_BIT             4
#define DQTI_BIT              2

//RXFIFOREG Bit number and length
#define RXDB                  7

//FIFORSTREG Bit number and length
#define FFBC_BIT              7
#define SYCHLEN_BIT           3
#define FFSC_BIT              2
#define FSCF_BIT              1
#define DRSTM_BIT             0

//SYNBREG Bit number and length
#define SYNCB_BIT             7

//DRSREG Bit number and length
#define DRPE_BIT              7
#define DRPV_BIT              6

//PMCREG Bit number and length
#define RXCEN_BIT             7
#define BBCEN_BIT             6
#define TXCEN_BIT             5
#define SYNEN_BIT             4
#define OSCEN_BIT             3
#define LBDEN_BIT             2
#define WUTEN_BIT             1
#define CLKOEN_BIT            0

//WTSREG Bit number and length
#define WTEV_BIT              12
#define WTMV_BIT              7

//DCSREG Bit number and length
#define DCMV_BIT              7
#define DCMEN_BIT             0

//BCSREG Bit number and length
#define COFSB_BIT             7
#define LBDVB_BIT             3

//PLLCREG Bit number and length
#define CBTC_BIT              6
#define PDDS_BIT              3
#define PLLDD_BIT             2
#define PLLBWB_BIT            0




