#pragma once

#include <drogon/HttpSimpleController.h>


using namespace drogon;

class TestCtrl: public HttpSimpleController<TestCtrl>
{
public:
	void asyncHandleHttpRequest(const HttpRequestPtr & req,
					std::function<void (const HttpResponsePtr&)>&&callback)override;
PATH_LIST_BEGIN
PATH_ADD("/",Get);
PATH_ADD("/api/projects",Get);
PATH_ADD("/api/skills",Get);
PATH_ADD("/api/health",Get);
PATH_LIST_END
};
