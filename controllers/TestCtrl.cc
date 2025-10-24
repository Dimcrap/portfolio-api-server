#include "TestCtrl.h"
#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <json/json/h>

using namespace drogon;

Json::Value projects={
{"projects",{
{

{"id",1},
{"name","Drogon Web server"},
{"description"," a high-performance C++ web server built with drogon framework"},
{"tech_stack",{"c++","Drogon","CMake","linux"}},
{"status","Completed"}

},
{

{"id",2},
{"name","Portfolio API"},
{"description","RESTful API service showcasing backend development skills:)"},
{"tech_stack",{"c++","REST API","JSON"}},
{"status","In Progress"}

}

}}

};


Json::Value skills ={
{"skills",{
{"c++","Advanced"},
{"Linux","Intermediate"},
{"Web Development","Beginner"},
{"Problem Solving","advanced"}

}}

};


void TestCtrl::asyncHandleHttpRequest(const HttpRequestPtr & req,
					std::function<void(const HttpResponsePtr &)>&& callback)
{
	auto resp =HttpResponse::newHttpResponse();
	resp->setContentTypeCode(CT_APPLICATION_JSON);

	Json::Value response;

	if(req->getPath() =="/api/project"){
	response=projects;
	}
	else if (req->getPath()=="/api/skills"){
	response=skills;
	}
	else if(req->getPath()=="/api/health"){
	response["status"]="Server is running healthy!";
	response["timestamp"]="2025";
	response["framework"]="Drogon C++";
	}
	else{
	response["message"] ="Portfolio API Server";
	response["endpoint"]={
	"/api/projects - Get project list",
	"/api/skills - Get technial skills",
	"/api/health -Server health check"
	};
	response["developer"]="mamadrezayof";
	response["tech"] = "C++ Drogon Framework";
	}

resp->setBody(response.toStyledString());
callaback(resp);

}








