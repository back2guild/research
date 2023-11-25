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

    response__t* newInstance(void);
    bool isResponseSuccess(response__t*);
#endif