#include "FileManager.h"

FileManager::FileManager(MicroBit &uBit){
    this->uBit = &uBit;    
}

int FileManager::read(const char *key, int &target){
    if (key == NULL)
        return -1;
    
    KeyValuePair *valuePair = uBit->storage.get(key);
    if (valuePair == NULL)
        return -1;
    
    memcpy(&target, valuePair->value, sizeof(int));
    delete valuePair;
    return 0;
}

int FileManager::write(const char *key, const int &value){
    if (key == NULL)
        return -1;
        
    uBit->storage.put(key, (uint8_t *) &value, sizeof(int));
    return 0;
}