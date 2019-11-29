#include <iostream>

using namespace std;

class Interest {
private:
    static unsigned int id;
    unsigned int fields_number = 6;
    //fields map is ordered from most interested in fields to least
    unsigned int *fields;
public:

    Interest :: Interest (unsigned int *fields, unsigned int fields_number) {

        this->id++;
        this->fields_number = fields_number;
        realloc(this->fields, this->fields_number);
        for (unsigned int i = 0; i < fields_number; i++){
            this->fields[i] = fields[i];
        }
    }
    unsigned int getID(){
        return this->id;
    }
    unsigned int* getFields() {
        return this->fields;
    }
    void setFields(unsigned int *fields, unsigned int fields_number) {
        this->fields_number = fields_number;
        realloc(this->fields, this->fields_number);
        for (unsigned int i = 0; i < fields_number; i++){
            this->fields[i] = fields[i];
        }
    }
    unsigned int getInterest() {
        unsigned int interest =this->fields[0];
        unsigned int interest_decrement = 1 / this->fields_number;
        for (unsigned int i = 1; i < this->fields_number; i++) {
            interest += this->fields[i] * (1 - interest_decrement / i);
        }

        return interest / this->fields_number;
    }
};

unsigned int Interest :: id{0};