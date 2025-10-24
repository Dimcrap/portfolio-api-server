#include <drogon/drogon.h>	
#include <iostream>
#include <json/json.h>

using namespace drogon;

//#include "controllers/TestCtrl.h"

int main() {
    //Set HTTP listener address and port

app().registerHandler("/",
        [](const HttpRequestPtr &req,
           std::function<void(const HttpResponsePtr &)> &&callback) {
            auto resp = HttpResponse::newHttpResponse();
            resp->setContentTypeCode(CT_TEXT_HTML);
            std::string html = R"(
<!DOCTYPE html>
<html>
<head>
    <title>My Portfolio API</title>
    <style>
        body { font-family: Arial, sans-serif; max-width: 800px; margin: 40px auto; padding: 20px; }
        .endpoint { background: #f5f5f5; padding: 15px; margin: 10px 0; border-radius: 5px; }
        a { color: #007bff; text-decoration: none; }
        a:hover { text-decoration: underline; }
        pre { background: #f8f8f8; padding: 10px; border-radius: 5px; }
    </style>
</head>
<body>
    <h1>🚀 Portfolio API Server</h1>
    <p>Built with <strong>C++ and Drogon Framework</strong></p>
    
    <div class="endpoint">
        <h3><a href="/api/projects" target="_blank">/api/projects</a></h3>
        <p>Get project portfolio (JSON API)</p>
    </div>
    
    <div class="endpoint">
        <h3><a href="/api/skills" target="_blank">/api/skills</a></h3>
        <p>View my technical skills (JSON API)</p>
    </div>
    
    <div class="endpoint">
        <h3><a href="/api/health" target="_blank">/api/health</a></h3>
        <p>Server health check (JSON API)</p>
    </div>
    
    <div class="endpoint">
        <h3>Quick Test:</h3>
        <pre>curl http://localhost:5555/api/health</pre>
    </div>
</body>
</html>
            )";
            resp->setBody(html);
            callback(resp);
        });

    // Projects API endpoint
    app().registerHandler("/api/projects",
        [](const HttpRequestPtr &req,
           std::function<void(const HttpResponsePtr &)> &&callback) {
            Json::Value response;
            response["message"] = "Projects retrieved successfully";
            
            Json::Value projects = Json::arrayValue;
            
            Json::Value project1;
            project1["id"] = 1;
            project1["name"] = "Portfolio API Server";
            project1["description"] = "A high-performance C++ web server built with Drogon framework";
            project1["tech_stack"] = "C++, Drogon, Linux, CMake";
            project1["status"] = "Completed";
            projects.append(project1);
            
            Json::Value project2;
            project2["id"] = 2;
            project2["name"] = "Web Development Learning";
            project2["description"] = "Learning backend development with modern C++ frameworks";
            project2["tech_stack"] = "C++, REST APIs, JSON";
            project2["status"] = "In Progress";
            projects.append(project2);
            
            response["projects"] = projects;
            
            auto resp = HttpResponse::newHttpJsonResponse(response);
            callback(resp);
        });

    // Skills API endpoint
    app().registerHandler("/api/skills",
        [](const HttpRequestPtr &req,
           std::function<void(const HttpResponsePtr &)> &&callback) {
            Json::Value response;
            response["message"] = "Skills retrieved successfully";
            
            Json::Value skills = Json::objectValue;
            skills["C++"] = "Intermediate";
            skills["Linux"] = "Intermediate";
            skills["Problem Solving"] = "must be good :D";
            skills["Web Development"] = "Beginner";
            skills["Backend APIs"] = "Beginner";
            
            response["skills"] = skills;
            
            auto resp = HttpResponse::newHttpJsonResponse(response);
            callback(resp);
        });

    
    app().registerHandler("/api/health",
        [](const HttpRequestPtr &req,
           std::function<void(const HttpResponsePtr &)> &&callback) {
            Json::Value response;
            response["status"] = "healthy";
            response["message"] = "Server is running perfectly!";
            response["framework"] = "Drogon C++ Web Framework";
            response["timestamp"] = "2025/1404";
            
            auto resp = HttpResponse::newHttpJsonResponse(response);
            callback(resp);
        });


    drogon::app().addListener("0.0.0.0", 5555);
  
    std::cout<<"========================================\n";
    std::cout << "🚀 Portfolio API Server Started!" << std::endl;
    std::cout << "📍 Server running at: http://localhost:5555" << std::endl;    
	
  //Load config file
    //drogon::app().loadConfigFile("../config.json");
    //drogon::app().loadConfigFile("../config.yaml");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
