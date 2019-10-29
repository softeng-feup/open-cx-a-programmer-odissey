#include "MicroBit.h"

class FileManager{
    private:
        MicroBit *uBit;
    
    public:
    FileManager(MicroBit &uBit);
    
    /**
    * Reads unsigned int with 'key' and saves it to 'target'
    * Returns -1 if key was not found, 0 on success
    */
    int read(const char *key, int &target);
    
    int write(const char *key, const int &value);
};