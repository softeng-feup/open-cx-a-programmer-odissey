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
    int readUnsigned(const char *key, unsigned int &target);
    
    int writeUnsigned(const char *key, const unsigned int &value);
};