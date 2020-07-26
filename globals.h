/*  Global Variables
 * 
 * 
 * 
 */

// Public Variables










 // "Private" variables for GPS values

 // GPS Veriables - used to convert Floats to ints to use with sprintf

// Direct conversions from library

int16_t longitudePre;    // pre decimal point
int16_t longitudePost;   // post decimal point

int16_t latitudePre;
int16_t latitudePost;

int16_t longitudeDegPre;    // pre decimal point
int16_t longitudeDegPost;   // post decimal point

int16_t latitudeDegPre;
int16_t latitudeDegPost;

int16_t altitudePre;                  // Altitude is only in m so can just be cast to an int
int16_t altitudePost;

// calculated values and conversions

int16_t altitudeKmPre;
int16_t altitudeKmPost;


int16_t  speedKnotsPre;
int16_t  speedKnotsPost;


int16_t  speedmsPre;
int16_t  speedmsPost;

int16_t speedkmhPre;
int16_t speedkmhPost;

int16_t speedmphPre;
int16_t speedmphPost;
