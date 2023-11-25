#include "common.h"
#include "response.h"

struct Response {
    enum ResponseStatus status;
    char *text;
    void *data;
    void (*setStatus)(struct Response*,enum ResponseStatus);
    void (*setText)(struct Response*, char *text);
    void (*setData)(struct Response*, void *data);
    enum ResponseStatus (*getStatus)(struct Response*);
    char* (*getText)(struct Response*);
    void* (*getData)(struct Response*);
};

void __setStatus(struct Response *this, enum ResponseStatus status) {
    this->status = status;
}

void __setText(struct Response *this, char *text) {
    this->text = text;
}

void __setData(struct Response *this, void *data) {
    this->data = data;
}

enum ResponseStatus __getStatus(struct Response *this) {
    return this->status;
}

char* __getText(struct Response *this) {
    return this->text;
}

void* __getData(struct Response *this) {
    return this->data;
}

response__t* newInstance(void) {
    response__t *result = (response__t*) malloc(sizeof(response__t));
    if(!result)
    {
        perror("ERROR: Creating response instance failed\n");
    }
    result->data = NULL;
    result->text = NULL;
    result->status = NONE;
    result->setData = __setData;
    result->setStatus = __setStatus;
    result->setText = __setText;
    result->getData = __getData;
    result->getStatus = __getStatus;
    result->getText = __getText;
    return result;
}

bool isResponseSuccess(response__t *res) {
    assert(res != NULL);
    bool status = false;
    return status; 
}