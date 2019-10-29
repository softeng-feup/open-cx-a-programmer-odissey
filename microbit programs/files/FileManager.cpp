#include "FileManager.h"

FileManager::FileManager(MicroBit &uBit){
    this->uBit = &uBit;    
}

int FileManager::readUnsigned(const char *key, unsigned int &target){
    if (key == NULL)
        return -1;
    
    KeyValuePair *valuePair = uBit->storage.get(key);
    if (valuePair == NULL)
        return -1;
    
    memcpy(&target, valuePair->value, sizeof(unsigned int));
    delete valuePair;
    return 0;
}

int FileManager::writeUnsigned(const char *key, const unsigned int &value){
    if (key == NULL)
        return -1;
        
    uBit->storage.put(key, (uint8_t *) &value, sizeof(unsigned int));
    return 0;
}