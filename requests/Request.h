#ifndef REQUEST_H
#define REQUEST_H
#include <string>
#include<queue>

class Request {
private:

public:
	std::string operation;
	uint64_t trackIdx;
	int dataIdx;
	uint64_t data;
	
	Request();
	Request(std::string operation, int trackIdx, int dataIdx, uint64_t data);
	~Request ();
};

//Ues yet 
//================
class RequestQueue {
private:
	std::string fileName;
	std::queue<Request*> requests;
public:
	RequestQueue();
	~RequestQueue();
	
	void Read(std::string filename);
	std::string GetFileName();
	Request* getNextRequest();
	void getNextRequest(Request** request);
};
//================
#endif // !REQUEST_H

