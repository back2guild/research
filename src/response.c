#include "common.h"
#include "response.h"

struct Response {
    // properties
    enum ResponseStatus status;
    char *text;
    void *data;

    //actions
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


void setResponseStatus(response__t *res,enum ResponseStatus status) {
    res->setStatus(res, status);
}

void setResponseText(response__t *res, char *text) {
    res->setText(res,text);
}


void setResponseData(response__t *res, void *data) {
    res->setData(res, data);
}

enum ResponseStatus getResponseStatus(response__t *res) {
    return res->getStatus(res);
}


char* getResponseText(response__t *res) {
    return res->getText(res);
}


void* getResponseData(response__t *res) {
    return res->getData;
}

response__t* createResponse(void) {
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
    return (getResponseStatus(res) == SUCCESS && !strcmp(getResponseText(res), RESPONSE_STATUS_SUCCESS));
}

void destroyResponse(response__t *res) {
    
}