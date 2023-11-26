#ifndef _RESEARCH_RESPONSE_H_
#define _RESEARCH_RESPONSE_H_ 1

    #define DEFAULT_MESSAGE_LENGTH 256
    #define RESPONSE_STATUS_SUCCESS "SUCCESS"
    #define RESPONSE_STATUS_ERROR "ERROR"
    
    typedef struct Response response__t;
    enum ResponseStatus {
        SUCCESS,
        ERROR,
        NONE
    };

    //typedef void (*setStatus)(struct Response*,enum ResponseStatus) SetStatus;
    //typedef void (*setText)(struct Response*, char *text) SetText;
    //typedef void (*setData)(struct Response*, void *data) SetData;
    //typedef enum ResponseStatus (*getStatus)(struct Response*) GetStatus;
    //typedef char* (*getText)(struct Response*) GetText;
    //typedef void* (*getData)(struct Response*) GetData;

    void setResponseStatus(response__t*,enum ResponseStatus);
    void setResponseText(response__t*, char *text);
    void setResponseData(response__t*, void *data);
    enum ResponseStatus getResponseStatus(response__t*);
    char* getResponseText(struct Response*);
    void* getResponseData(struct Response*);

    response__t* createResponse(void);
    bool isResponseSuccess(response__t*);
    void destroyResponse(response__t*);
#endif