#ifndef __PUZL_HTTP_H__
#define __PUZL_HTTP_H__

// std
#include <string>
#include <vector>
#include <functional>
// curl
#include <curl/curl.h>
#include <curl/easy.h>

typedef unsigned int uint;
typedef std::function<void(std::string)> HttpCallback;

struct HttpParams
{
    uint timeout;
};

struct HttpJsonData
{
    void* data;
    long size;
};

struct HttpResponse
{
    std::string data;
    std::string error;
    int code;
};

class Http
{
public:
    Http();
    ~Http();

public:
    HttpResponse get
    (
        const std::string& url,
        const std::vector<std::string>& headers,
        const HttpParams* pParams
    );

    HttpResponse post
    (
        const std::string& url,
        const std::vector<std::string>& headers,
        const HttpParams* pParams,
        const HttpJsonData* pJsonData
    );

    HttpResponse put
    (
        const std::string& url,
        const std::vector<std::string>& headers,
        const HttpParams* pParams,
        const HttpJsonData* pJsonData
    );

    HttpResponse postFormData
    (
        const std::string& url,
        std::vector<std::vector<std::string>>& options,
        void* pData,
        long dataSize
    );

public:
    static void setSSLCertificate(const std::string& certFile);

private:
    HttpResponse request
    (
        const std::string& url,
        const std::vector<std::string>& headers,
        const HttpParams* pParams,
        const HttpJsonData* pJsonData,
        bool put
    );

private:
    CURL *mCurl;
    static std::string sSSLCertificate;
};

#endif // __PUZL_HTTP_H__